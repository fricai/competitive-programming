fun main(args: Array<String>) {
    val q = Integer.valueOf(readLine())
    for (i in 1..q) {
        val d = " "
        val str = readLine()!!.split(d)
        val x = Integer.valueOf(str[0])
        val y = Integer.valueOf(str[1])
        val a = minOf(x - 1, y - 1)
        val b = x - a
        val c = y - a
        println("$a $b $c")
    }
}