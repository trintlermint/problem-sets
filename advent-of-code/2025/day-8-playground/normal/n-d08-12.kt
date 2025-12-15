import kotlin.math.sqrt
import kotlin.math.pow

class UF(n: Int) {
    val p = IntArray(n) { it }
    val s = IntArray(n) { 1 }
    fun find(x: Int): Int { if (p[x] != x) p[x] = find(p[x]); return p[x] }
    fun unite(x: Int, y: Int): Boolean {
        var px = find(x); var py = find(y)
        if (px == py) return false
        if (s[px] < s[py]) { val t = px; px = py; py = t }
        p[py] = px; s[px] += s[py]; return true
    }
}

fun main() {
    val pts = generateSequence(:: readLine).map { l -> l.split(",").map { it.toInt() } }. toList()
    val n = pts.size
    val dists = mutableListOf<Triple<Double, Int, Int>>()
    for (i in 0 until n) for (j in i + 1 until n) {
        val d = sqrt((0.. 2).sumOf { (pts[i][it] - pts[j][it]).toDouble().pow(2) })
        dists.add(Triple(d, i, j))
    }
    dists.sortBy { it.first }
    
    val uf1 = UF(n)
    dists.take(1000).forEach { (_, i, j) -> uf1.unite(i, j) }
    val sizes = (0 until n).filter { uf1.find(it) == it }.map { uf1.s[it] }. sortedDescending()
    println(sizes[0]. toLong() * sizes[1] * sizes[2])
    
    val uf2 = UF(n)
    for ((_, i, j) in dists) {
        if (uf2.unite(i, j) && (0 until n).map { uf2.find(it) }.toSet().size == 1) {
            println(pts[i][0]. toLong() * pts[j][0])
            break
        }
    }
}
