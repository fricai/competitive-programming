import java.util.Scanner

val read = Scanner(System.`in`)
    
fun input(): Int {
    return read.nextInt()
}

fun main(args: Array<String>) {
    var n = input()
    val k = input()
    for (i in 1..k) {
        if (n % 10 == 0)
            n /= 10
        else
            n -= 1
    }
    print(n)
}