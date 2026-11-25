# cpp-kata

C++ coding katas built with Bazel and tested with GoogleTest. Inspired by
[ryanmcdermott/katas](https://github.com/ryanmcdermott/katas).

Each kata has a stub that you implement and a reference solution. The same
tests run against both.

## Setup

Install [bazelisk](https://github.com/bazelbuild/bazelisk) as `bazel`. It
downloads the Bazel version pinned in `.bazelversion`.

## Layout

```
katas/<name>/
├── BUILD.bazel      # kata(name = "<name>")
├── <name>.h         # API (namespace kata::<name>)
├── <name>.cc        # your attempt
├── solution.cc      # reference solution
└── <name>_test.cc   # GoogleTest tests
```

There is no `main.cpp`. `gtest_main` provides `main()`.

## Workflow

```sh
./scripts/new_kata.sh two_sum            # scaffold a new kata
bazel test //katas/two_sum:practice      # test your attempt
bazel test //katas/two_sum:solution      # test the reference
bazel test --config=solution //...       # all reference solutions must pass
bazel test --config=practice //...       # your overall progress
bazel run //katas/two_sum:practice -- --gtest_filter='*Empty*'
git checkout katas/two_sum/two_sum.cc    # reset an attempt to the stub
```

When you write a new kata, define the API in `<name>.h`, write the tests,
implement `solution.cc` until `:solution` passes, then commit `<name>.cc` as a
stub that compiles but fails the tests.

Katas that share helpers (for example a tree node) can pass them as
`kata(name = ..., deps = ["//lib:tree"])`.

Format with `clang-format -i katas/**/*.{h,cc}`.
