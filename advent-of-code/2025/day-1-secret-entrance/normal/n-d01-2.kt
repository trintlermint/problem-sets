var dial = 50

fun main() = println(generateSequence(::readLine).sumOf { line ->
    (0 until line.substring(1).toInt()).count {
        dial += if (line.startsWith('R')) 1 else -1
        dial % 100 == 0
    }
})