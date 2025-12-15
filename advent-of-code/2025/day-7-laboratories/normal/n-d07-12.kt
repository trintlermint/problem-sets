fun main() {
    val grid = generateSequence(::readLine).toList()
    val h = grid.size
    val w = grid[0].length
    val sx = (0 until w).first { grid[0][it] == 'S' }
    var splits = 0
    val queue = ArrayDeque<Pair<Int, Int>>()
    val visited = mutableSetOf<Pair<Int, Int>>()
    queue.add(0 to sx)
    while (queue.isNotEmpty()) {
        val (y, x) = queue.removeFirst()
        if ((y to x) in visited) continue
        visited.add(y to x)
        val ny = y + 1
        if (ny >= h) continue
        if (grid[ny][x] == '^') {
            splits++
            if (x > 0) queue.add(ny to x - 1)
            if (x < w - 1) queue.add(ny to x + 1)
        } else queue.add(ny to x)
    }
    
    val memo = mutableMapOf<Pair<Int, Int>, Long>()
    fun countPaths(y: Int, x: Int): Long {
        if (y >= h) return 1
        memo[y to x]?.let { return it }
        val ny = y + 1
        if (ny >= h) return 1
        val result = if (grid[ny][x] == '^') {
            (if (x > 0) countPaths(ny, x - 1) else 0) + (if (x < w - 1) countPaths(ny, x + 1) else 0)
        } else countPaths(ny, x)
        memo[y to x] = result
        return result
    }
    
    println(splits)
    println(countPaths(0, sx))
}
