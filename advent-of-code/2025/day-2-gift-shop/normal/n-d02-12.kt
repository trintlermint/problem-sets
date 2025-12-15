fun isDouble(n: Long): Boolean {
    val s = n.toString()
    if (s.length % 2 != 0) return false
    return s.substring(0, s.length / 2) == s.substring(s.length / 2)
}

fun isRepeat(n: Long): Boolean {
    val s = n.toString()
    for (k in 1 until s.length) {
        if (s.length % k == 0) {
            val pat = s.substring(0, k)
            if (pat. repeat(s.length / k) == s) return true
        }
    }
    return false
}

fun main() {
    val data = generateSequence(::readLine).joinToString("").trim()
    var p1 = 0L
    var p2 = 0L
    for (r in data.split(",")) {
        if (r.isBlank()) continue
        val (lo, hi) = r.split("-").map { it.toLong() }
        for (n in lo..hi) {
            if (isDouble(n)) p1 += n
            if (isRepeat(n)) p2 += n
        }
    }
    println(p1)
    println(p2)
}
