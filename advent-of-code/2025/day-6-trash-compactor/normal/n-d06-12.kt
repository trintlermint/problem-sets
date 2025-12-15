fun main() {
    val lines = generateSequence(::readLine).toMutableList()
    val maxLen = lines.maxOf { it.length }
    val padded = lines.map { it. padEnd(maxLen) }
    
    val cols = (0 until maxLen).map { c -> padded. map { it[c] }. joinToString("") }
    
    fun solve(cs: List<String>): Long {
        var total = 0L
        var i = 0
        while (i < cs.size) {
            while (i < cs. size && cs[i].isBlank()) i++
            if (i >= cs.size) break
            var j = i
            while (j < cs.size && cs[j].isNotBlank()) j++
            val op = cs[i].last()
            val nums = (i until j).mapNotNull { k ->
                val s = cs[k].dropLast(1).replace(" ", "")
                if (s.isNotEmpty()) s.toLong() else null
            }
            total += if (op == '+') nums.sum() else nums.reduce { a, b -> a * b }
            i = j
        }
        return total
    }
    
    println(solve(cols))
    println(solve(cols.reversed()))
}
