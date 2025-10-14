def matrix_dot_vector(a: list[list[int|float]], b: list[int|float]) -> list[int|float]:
	rows = len(a)
    cols = len(a[0])
    # a = matrix, b = vec
    # row == col
    for row in a:
        if len(row) != cols: return -1
    
    # dim
    if cols != len(b): return -1

    res = []
    for i in range(rows):
        dot_prod = 0
        for j in range(cols):
            dot_prod += a[i][j] * b[j]
        res.append(dot_prod)
    
    return res
