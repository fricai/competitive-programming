import kotlin.math.*

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }

fun main() {
	var a1 = readInt()
	var a2 = readInt()
	var k1 = readInt()
	var k2 = readInt()
	val n = readInt()

	if (k1 > k2) {
		a1 = a2.also{a2 = a1}
		k1 = k2.also{k2 = k1}
	}

	var n1 = n
	var mx = 0
	mx += min(n1 / k1, a1)
	n1 -= mx * k1

	val dumb = min(n1 / k2, a2)
	mx += dumb
	n1 -= dumb * k2

	var mn = max(0, n - a1 * (k1 - 1) - a2 * (k2 - 1))

	println("$mn $mx")
}
