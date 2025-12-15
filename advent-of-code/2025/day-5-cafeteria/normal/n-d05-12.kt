fun main() {
    val input = generateSequence(::readLine).joinToString("\n").split("\n\n")
    val ranges = input[0].lines().map { val (a, b) = it.split("-").map(String::toLong); a to b }. sortedBy { it.first }. toMutableList()
    val ids = input[1].trim().lines().map { it.toLong() }
    
    val merged = mutableListOf<Pair<Long, Long>>()
    for ((lo, hi) in ranges) {
        if (merged.isNotEmpty() && lo <= merged.last().second + 1)
            merged[merged.lastIndex] = merged.last().first to maxOf(merged.last().second, hi)
        else merged.add(lo to hi)
    }
    
    val p1 = ids.count { i -> merged.any { (lo, hi) -> i in lo..hi } }
    val p2 = merged.sumOf { (lo, hi) -> hi - lo + 1 }
    println(p1)
    println(p2)
}
