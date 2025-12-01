// https://open.kattis.com/problems/jibjob
import kotlin.math.*

fun main() {
   val pt = List(readln().toInt()) {
       readln().split(" ").map { it.toDouble() }
   }
   val ans = pt.map { (x1, y1, h) ->
       val collide = pt.filter { it[2] > h }
            .minOfOrNull { (x2, y2, h2) ->
                hypot((x2 - x1), (y2 - y1)) } ?: h
                // there are no towers > h. .filter(it[2] > h)
                // outputs no elements in the set => compile error from NoSuchElementException
                // => fix: check with minOfOrNull instead of minOf, check if it is null => collide = h;
       minOf(h, collide).toInt()
   }
   println(ans.joinToString("\n"))
}

