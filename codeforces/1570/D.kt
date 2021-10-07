private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }

fun f(x: Int): Int {
	var y = x + 1
	while (y % 10 == 0)
		y /= 10
	return y
}

fun main() {
	var x = readInt()

	var ans = 9
	while (x >= 10) {
		++ans
		x = f(x)
	}
	println(ans)
}
