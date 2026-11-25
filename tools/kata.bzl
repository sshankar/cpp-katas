"""kata() macro: one test file run against both your stub and a reference solution."""

load("@rules_cc//cc:defs.bzl", "cc_library", "cc_test")

def kata(name, deps = []):
    """Defines targets for a kata.

    Expects <name>.h, <name>.cc (your attempt), solution.cc and <name>_test.cc.

    Targets:
      :api           header-only library
      :practice_lib  your implementation
      :solution_lib  reference implementation
      :practice      tests against your implementation (tag "practice")
      :solution      tests against the reference (tag "solution")
    """
    cc_library(
        name = "api",
        hdrs = [name + ".h"],
        deps = deps,
    )
    for variant, src in [("practice", name + ".cc"), ("solution", "solution.cc")]:
        cc_library(
            name = variant + "_lib",
            srcs = [src],
            deps = [":api"] + deps,
        )
        cc_test(
            name = variant,
            srcs = [name + "_test.cc"],
            deps = [
                ":api",
                ":" + variant + "_lib",
                "@googletest//:gtest_main",
            ],
            size = "small",
            tags = [variant],
        )
