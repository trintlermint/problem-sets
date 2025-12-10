import sys
from typing import List, Tuple

import numpy as np
from scipy.optimize import milp

def parse_button_indices(button_token: str) -> List[int]:
    inner = button_token.strip()[1:-1].strip()
    if not inner:
        return []
    return [int(x) for x in inner.split(",")]


def build_button_matrix(buttons: List[List[int]], size: int) -> np.ndarray:
    num_buttons = len(buttons)
    matrix = np.zeros((size, num_buttons), dtype=int)
    for j, indices in enumerate(buttons):
        for i in indices:
            matrix[i, j] = 1
    return matrix


def solve_part_two_min_presses(button_matrix: np.ndarray, targets: np.ndarray) -> int:
    num_buttons = button_matrix.shape[1]
    objective = np.ones(num_buttons, dtype=float)
    integrality = np.ones(num_buttons, dtype=int)

    result = milp(
        c=objective,
        constraints=(button_matrix, targets, targets),
        integrality=integrality,
    )
    return int(round(result.fun))


def solve_part_one_min_presses(button_matrix: np.ndarray, targets_mod2: np.ndarray) -> int:
    num_buttons = button_matrix.shape[1]
    size = button_matrix.shape[0]
    slack_matrix = -2 * np.eye(size, dtype=int)
    augmented_matrix = np.hstack([button_matrix, slack_matrix])

    objective = np.concatenate(
        [np.ones(num_buttons, dtype=float), np.zeros(size, dtype=float)]
    )
    integrality = np.ones(num_buttons + size, dtype=int)

    result = milp(
        c=objective,
        constraints=(augmented_matrix, targets_mod2, targets_mod2),
        integrality=integrality,
    )
    return int(round(result.fun))


def parse_line(line: str) -> Tuple[np.ndarray, np.ndarray, np.ndarray]:
    parts = line.strip().split()
    indicator_token = parts[0]
    joltage_token = parts[-1]
    button_tokens = parts[1:-1]

    target_bits = np.array([1 if ch == "#" else 0 for ch in indicator_token[1:-1]], dtype=int)
    joltage_targets = np.array(eval(joltage_token[1:-1]), dtype=int)

    buttons = [parse_button_indices(tok) for tok in button_tokens]
    button_matrix = build_button_matrix(buttons, len(target_bits))

    return target_bits, button_matrix, joltage_targets


def main() -> None:
    part_one_total = 0
    part_two_total = 0
    for raw_line in sys.stdin:
        raw_line.strip()
        target_bits, button_matrix, joltage_targets = parse_line(raw_line)

        part_one_total += solve_part_one_min_presses(button_matrix, target_bits)
        part_two_total += solve_part_two_min_presses(button_matrix, joltage_targets)

    print(part_one_total, part_two_total)


if __name__ == "__main__":
    main()
