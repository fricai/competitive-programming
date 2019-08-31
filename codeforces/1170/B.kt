import java.util.Scanner

fun main(args: Array<String>) {
    val read = Scanner(System.`in`)
    val n = read.nextInt()
    var mx1 = 0
    var mx2 = 0
    var ans = 0
    for (i in 1..n) {
        val cur = read.nextInt()
        if (cur < mx1 && cur < mx2) {
            ans += 1
        }
        if (cur >= mx1) {
            mx2 = mx1
            mx1 = cur
        } else if (cur > mx2) {
            mx2 = cur
        }
    }
    print(ans)
}