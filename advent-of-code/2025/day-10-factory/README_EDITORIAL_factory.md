# Day 10: Factory — Editorial

Each input line describes one machine:
- An indicator pattern in brackets `[...]` using `.` (off) and `#` (on).
- A list of buttons in parentheses, each listing the zero-based indices it affects.
- A joltage target vector in braces `{...}`.

Part 1 (indicator lights):
- All lights start off.
- Pressing a button toggles each listed light.
- Find the minimum total button presses so that every light matches the target pattern.

Part 2 (joltage counters):
- All counters start at zero.
- Pressing a button adds 1 to each listed counter.
- Find the minimum total presses to reach the exact target vector.
We must sum the min() over all machines.

### set a matrix A:

For a machine with `k` lights/counters and `m` buttons, build a matrix `A` of shape `(k, m)` where
`A[i, j] = 1` if button `j` affects position `i`, else `0`.
Decision variables are press counts `x_j ≥ 0`, integers.

### Part 2 (additive counters)

```
A @ x = target
minimize sum(x_j)
x_j ≥ 0, integer
```

### Part 1 (binary light mod 2)

toggling creates a mod-2 constraint:

```
A @ x ≡ target (mod 2)
```

We linearize the modulo with slack integers `y_i ≥ 0`:

```
A @ x - 2 * y = target
```
Objective counts only button presses; slack has zero cost.

## Impl

For each line:

1. Parse the indicator pattern to a 0/1 target vector.
2. Parse the buttons into index lists, build matrix `A`.
3. Parse joltage targets.
4. Part 1: solve the augmented ILP with slack for modulo-2.
5. Part 2: solve the direct equality ILP.
6. Accumulate both minima.

- Part 2: The ILP enforces `A x = target` exactly with non-negative integers; minimizing `sum(x)` yields the fewest presses.
- Part 1: For any integer solution `(x, y)`, `A x = target + 2y` implies `A x ≡ target (mod 2)`, matching toggle parity. Conversely, any press vector achieving the target parity can pair with `y = (A x - target)/2` to satisfy the linear constraint. Objective ignores `y`, so the optimum matches the minimum valid press count. Summing per-machine optima gives the required totals.
Let `k` be lights/counters and `m` buttons per machine. The ILP has `m` variables (plus `k` slack for part 1) and `k` equalities.
