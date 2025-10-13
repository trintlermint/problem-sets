
def matrix_dot_vector(a: list[list[int|float]], b: list[int|float]) -> list[int|float]:
	# Return a list where each element is the dot product of a row of 'a' with 'b'.
	# If the number of columns in 'a' does not match the length of 'b', return -1.
	l = len(a[0])
	if l != len(b): return -1
	sum = 0
	i = 0
	for i in range(len(a)):
		for j in range(len(a[i])):
			sum += (a[i][j] * a[i][j])
	return sum
	pass
print(matrix_dot_vector([[1,2],[2,4]], [1,2]))
