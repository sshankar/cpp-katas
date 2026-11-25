#!/usr/bin/env bash
# Usage: ./scripts/new_kata.sh <snake_case_name>
set -euo pipefail

root="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
name="${1:-}"

if [[ ! "$name" =~ ^[a-z][a-z0-9_]*$ ]]; then
  echo "usage: $0 <snake_case_name>" >&2
  exit 1
fi

dir="$root/katas/$name"
if [[ -e "$dir" ]]; then
  echo "error: $dir already exists" >&2
  exit 1
fi

guard="KATAS_$(echo "$name" | tr '[:lower:]' '[:upper:]')_$(echo "$name" | tr '[:lower:]' '[:upper:]')_H_"
test_name="$(echo "$name" | sed -E 's/(^|_)([a-z0-9])/\U\2/g')"

render() {
  sed -e "s/{{NAME}}/$name/g" -e "s/{{GUARD}}/$guard/g" -e "s/{{TEST_NAME}}/$test_name/g" "$1" > "$2"
}

mkdir -p "$dir"
render "$root/templates/BUILD.bazel.tmpl" "$dir/BUILD.bazel"
render "$root/templates/kata.h.tmpl"      "$dir/$name.h"
render "$root/templates/kata.cc.tmpl"     "$dir/$name.cc"
render "$root/templates/solution.cc.tmpl" "$dir/solution.cc"
render "$root/templates/kata_test.cc.tmpl" "$dir/${name}_test.cc"

echo "Created katas/$name"
echo "  bazel test //katas/$name:solution   # reference"
echo "  bazel test //katas/$name:practice   # your attempt"
