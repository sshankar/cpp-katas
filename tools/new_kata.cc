// Scaffolds katas/<name>/ from templates/. Run via:
//   bazel run //tools:new_kata -- <snake_case_name>

#include <cctype>
#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <memory>
#include <regex>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

#include "rules_cc/cc/runfiles/runfiles.h"

namespace fs = std::filesystem;
using rules_cc::cc::runfiles::Runfiles;

namespace {

std::string Upper(std::string s) {
  for (char& c : s) c = static_cast<char>(std::toupper(c));
  return s;
}

// two_sum -> TwoSum
std::string Pascal(const std::string& s) {
  std::string out;
  bool up = true;
  for (char c : s) {
    if (c == '_') {
      up = true;
    } else {
      out += up ? static_cast<char>(std::toupper(c)) : c;
      up = false;
    }
  }
  return out;
}

std::string Render(std::string text,
                   const std::vector<std::pair<std::string, std::string>>& vars) {
  for (const auto& [key, value] : vars) {
    const std::string token = "{{" + key + "}}";
    for (size_t pos = 0; (pos = text.find(token, pos)) != std::string::npos;
         pos += value.size()) {
      text.replace(pos, token.size(), value);
    }
  }
  return text;
}

}  // namespace

int main(int argc, char** argv) {
  if (argc != 2 || !std::regex_match(argv[1], std::regex("[a-z][a-z0-9_]*"))) {
    std::cerr << "usage: bazel run //tools:new_kata -- <snake_case_name>\n";
    return 1;
  }
  const std::string name = argv[1];

  const char* workspace = std::getenv("BUILD_WORKSPACE_DIRECTORY");
  if (workspace == nullptr) {
    std::cerr << "error: run this via `bazel run`\n";
    return 1;
  }

  std::string error;
  std::unique_ptr<Runfiles> runfiles(
      Runfiles::Create(argv[0], BAZEL_CURRENT_REPOSITORY, &error));
  if (runfiles == nullptr) {
    std::cerr << "error: " << error << "\n";
    return 1;
  }

  const fs::path dir = fs::path(workspace) / "katas" / name;
  if (fs::exists(dir)) {
    std::cerr << "error: " << dir.string() << " already exists\n";
    return 1;
  }

  const std::vector<std::pair<std::string, std::string>> vars = {
      {"NAME", name},
      {"GUARD", "KATAS_" + Upper(name) + "_" + Upper(name) + "_H_"},
      {"TEST_NAME", Pascal(name)},
  };
  const std::vector<std::pair<std::string, std::string>> files = {
      {"BUILD.bazel.tmpl", "BUILD.bazel"},
      {"kata.h.tmpl", name + ".h"},
      {"kata.cc.tmpl", name + ".cc"},
      {"solution.cc.tmpl", "solution.cc"},
      {"kata_test.cc.tmpl", name + "_test.cc"},
  };

  fs::create_directories(dir);
  for (const auto& [tmpl, out] : files) {
    std::ifstream in(runfiles->Rlocation("_main/templates/" + tmpl));
    if (!in) {
      std::cerr << "error: missing template " << tmpl << "\n";
      fs::remove_all(dir);
      return 1;
    }
    std::stringstream buf;
    buf << in.rdbuf();
    std::ofstream(dir / out) << Render(buf.str(), vars);
  }

  std::cout << "Created katas/" << name << "\n"
            << "  bazel test //katas/" << name << ":solution   # reference\n"
            << "  bazel test //katas/" << name << ":practice   # your attempt\n";
  return 0;
}
