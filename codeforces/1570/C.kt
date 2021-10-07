private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }

fun main() {
	val n = readInt()
	val a = readInts()

	var indices = a.indices.toList()

	val cmp = Comparator {i: Int, j: Int -> a[j] - a[i] }
	indices = indices.sortedWith(cmp)

	var ans = n
	for (i in indices.indices)
		ans += a[indices[i]] * i
	
	println(ans)
	println(indices.map{it + 1}.joinToString(" "))
}
