fun main() {
    var p1 = 0L
    var p2 = 0L
    generateSequence(::readLine).forEach { line ->
        val d = line. map { it - '0' }
        val n = d.size
        var mx = 0
        for (i in 0 until n) for (j in i + 1 until n) mx = maxOf(mx, d[i] * 10 + d[j])
        p1 += mx
        val res = StringBuilder()
        var start = 0
        for (rem in 12 downTo 1) {
            var best = start
            for (i in start.. n - rem) if (d[i] > d[best]) best = i
            res.append(d[best])
            start = best + 1
        }
        p2 += res.toString().toLong()
    }
    println(p1)
    println(p2)
}
