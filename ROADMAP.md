# Roadmap

The 56 katas from [ryanmcdermott/katas](https://github.com/ryanmcdermott/katas),
ordered from easiest to hardest.

The cycle for each tier:

1. **Add**: scaffold the tier's katas with their API, tests, stub and reference solution.
2. **Solve**: implement each `<name>.cc` until `bazel test //katas/<name>:practice` passes.
3. **Review**: go over the solutions once the whole tier is solved.
4. Only then add the next tier.

Status: ✅ done · ⬜ not yet

## Tier 1: Warm-ups (bit tricks and simple loops)

Added in `3e4ff13`.

| # | Kata | Solved | Reviewed |
|---|---|:-:|:-:|
| 1 | bitwise_swap | ⬜ | ⬜ |
| 2 | bitwise_check_set | ⬜ | ⬜ |
| 3 | bitwise_power_of_two | ⬜ | ⬜ |
| 4 | bitwise_non_duplicate | ⬜ | ⬜ |
| 5 | reverse_digits | ⬜ | ⬜ |
| 6 | palindrome_check | ⬜ | ⬜ |
| 7 | exponent | ⬜ | ⬜ |
| 8 | two_sum | ⬜ | ⬜ |
| 9 | buy_sell_stock | ⬜ | ⬜ |
| 10 | bitwise_addition | ⬜ | ⬜ |
| 11 | bitwise_division | ⬜ | ⬜ |

## Tier 2: Arrays, sorting, searching (not added yet)

bubble_sort, selection_sort, insertion_sort, binary_search, shuffle,
prime_sieve, matrix_rotate, matrix_spiral, sorted_rotated_array, quicksort

## Tier 3: Linear data structures and heaps (not added yet)

stack, queue, linked_list, linked_list_reversed, linked_list_remove_duplicates,
merge_lists, stack_two_queues, max_heap, kth_largest

Needs a shared linked list node in `//lib`.

## Tier 4: Trees (not added yet)

binary_search_tree, compare_trees, binary_tree_invert, binary_tree_check,
sum_tree_check, binary_tree_height_balanced, binary_tree_level_order,
binary_tree_lca, trie

Needs a shared tree node in `//lib`, plus a builder that makes a tree from a
level-order vector.

## Tier 5: Recursion and backtracking (not added yet)

permutations, power_set, subset_sum, n_queens

## Tier 6: Graphs (not added yet)

graph, bfs, dfs_all_paths, graph_cycle_detection, topological_sort, dijkstra,
prim

Needs a shared graph type in `//lib`.

## Tier 7: Dynamic programming (not added yet)

longest_common_subsequence, levenshtein, knapsack

## Tier 8: Advanced (not added yet)

interval_tree, convex_hull, parallel_summation

## Progress check

```sh
bazel test --config=practice //...   # PASSED = solved
```
