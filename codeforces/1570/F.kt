private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }

fun main() {
	val (n, m) = readInts()
	var b = Array(n) { IntArray(m) {0} }
	var a = Array(n) { readInts() }

	var v = ArrayList<Pair<Int, Int>>()
	
	for (i in 1 until n) {
		for (j in 1 until m) {
			if ((a[i][j] != 1) || (a[i - 1][j] != 1) || (a[i][j - 1] != 1) || (a[i - 1][j - 1] != 1))
				continue
			b[i][j] = 1
			b[i - 1][j] = 1
			b[i][j - 1] = 1
			b[i - 1][j - 1] = 1
			v.add(Pair(i, j))
		}
	}

	for (i in 0 until n) {
		for (j in 0 until m) {
			if (a[i][j] != b[i][j]) {
				println(-1)
				return
			}
		}
	}

	println(v.size)
	for ((i, j) in v)
		println("$i $j")
}
