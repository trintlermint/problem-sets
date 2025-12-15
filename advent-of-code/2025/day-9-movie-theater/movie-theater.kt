fun main() {
    val pts = generateSequence(:: readLine).map { l -> l.split(",").map { it.toInt() }. let { it[0] to it[1] } }.toList()
    val n = pts.size
    var mx1 = 0L
    for (i in 0 until n) for (j in i + 1 until n)
        mx1 = maxOf(mx1, kotlin.math.abs(pts[i].first - pts[j].first).toLong() * kotlin.math.abs(pts[i].second - pts[j].second))
    println(mx1)
    val edges = mutableSetOf<Pair<Int, Int>>()
    for (i in 0 until n) {
        val (x1, y1) = pts[i]; val (x2, y2) = pts[(i + 1) % n]
        if (x1 == x2) for (y in minOf(y1, y2)..maxOf(y1, y2)) edges.add(x1 to y)
        else for (x in minOf(x1, x2)..maxOf(x1, x2)) edges.add(x to y1)
    }
    
    var minx = edges.minOf { it.first } - 1; var maxx = edges.maxOf { it.first } + 1
    var miny = edges. minOf { it.second } - 1; var maxy = edges.maxOf { it.second } + 1
    
    val outside = mutableSetOf<Pair<Int, Int>>()
    val q = ArrayDeque<Pair<Int, Int>>()
    q.add(minx to miny)
    while (q.isNotEmpty()) {
        val (x, y) = q.removeFirst()
        if ((x to y) in outside || (x to y) in edges || x < minx || x > maxx || y < miny || y > maxy) continue
        outside. add(x to y)
        for ((dx, dy) in listOf(-1 to 0, 1 to 0, 0 to -1, 0 to 1)) q.add(x + dx to y + dy)
    }
    
    val valid = edges + (minx..maxx).flatMap { x -> (miny..maxy).mapNotNull { y -> if ((x to y) !in outside && (x to y) !in edges) x to y else null } }
    
    var mx2 = 0L
    for (i in 0 until n) for (j in i + 1 until n) {
        val xlo = minOf(pts[i].first, pts[j].first); val xhi = maxOf(pts[i].first, pts[j].first)
        val ylo = minOf(pts[i].second, pts[j].second); val yhi = maxOf(pts[i].second, pts[j].second)
        if ((xlo..xhi).all { x -> (ylo..yhi).all { y -> (x to y) in valid } })
            mx2 = maxOf(mx2, (xhi - xlo).toLong() * (yhi - ylo))
    }
    println(mx2)
}
