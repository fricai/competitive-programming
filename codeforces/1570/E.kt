private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }

fun main() {
	var t = readInt()

	while (t-- > 0) {
		val s = readLn()

		var one = false
		var cur = 0
		var ans = 0
		for (c in s) {
			if (c == '1') {
				if (one) {
					ans += cur
				} else {
					one = true
				}
				cur = 0
			} else {
				++cur
			}
		}
		println(ans)
	}
}
