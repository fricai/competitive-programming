fun main(args: Array<String>) {
    val n = readLine()!!.toInt()
    val str = readLine()
    var cnt = mutableMapOf<String, Int>()
    
    for (i in 0..n - 2) {
        val z = str!!.substring(i, i + 2)
        cnt.merge(z, 1, Int::plus)
    }
    
    var mx = 0
    var s = ""
    for ((k, v) in cnt) {
        if (v > mx) {
            mx = v
            s = k
        }
    }
    
    print(s)
}