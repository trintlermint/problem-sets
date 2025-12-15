fun main() {
    val g = generateSequence(::readLine).toMutableList().map { it.toMutableList() }
    val h = g.size
    val w = g[0].size
    
    fun countN(grid: List<List<Char>>, y: Int, x: Int): Int {
        var c = 0
        for (dy in -1..1) for (dx in -1..1) {
            if (dy == 0 && dx == 0) continue
            val ny = y + dy; val nx = x + dx
            if (ny in 0 until h && nx in 0 until w && grid[ny][nx] == '@') c++
        }
        return c
    }
    
    val p1 = (0 until h).sumOf { y -> (0 until w).count { x -> g[y][x] == '@' && countN(g, y, x) < 4 } }
    
    val g2 = g. map { it.toMutableList() }.toMutableList()
    var total = 0
    while (true) {
        val rem = mutableListOf<Pair<Int, Int>>()
        for (y in 0 until h) for (x in 0 until w)
            if (g2[y][x] == '@' && countN(g2, y, x) < 4) rem.add(y to x)
        if (rem.isEmpty()) break
        total += rem.size
        for ((y, x) in rem) g2[y][x] = '.'
    }
    println(p1)
    println(total)
}
