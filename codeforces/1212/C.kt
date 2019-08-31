fun main(args: Array<String>) {
    val (n, k) = readLine()!!.split(' ').map(String::toInt)
    val a = ArrayList(readLine()!!.split(' ').map(String::toInt))
    a.sort()
    if (k == 0) {
        if (a[0] != 1)
            print(1)
        else
            print(-1)
    } else if (k == n) print(a[n - 1])
    else {
        if (a[k] != a[k - 1])
            print(a[k - 1])
        else
            print(-1)
    }
}