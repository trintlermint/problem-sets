fun main() {
    var pos = 50
    var p1 = 0
    var p2 = 0
    generateSequence(:: readLine).forEach { line ->
        val d = line[0]
        val n = line.substring(1).toInt()
        repeat(n) {
            pos = (pos + if (d == 'L') -1 else 1 + 100) % 100
            if (pos < 0) pos += 100
            if (pos == 0) p2++
        }
        if (pos == 0) p1++
    }
    println(p1)
    println(p2)
}
