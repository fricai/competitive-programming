import java.util.Scanner

fun main(args: Array<String>) {
    val read = Scanner(System.`in`)
    val q = read.nextInt()
    for (i in 1..q) {
        val x = read.nextInt()
        val y = read.nextInt()
        val a = minOf(x - 1, y - 1)
        val b = x - a
        val c = y - a
        println("$a $b $c")
    }
}