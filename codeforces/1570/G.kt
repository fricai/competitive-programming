private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }

fun main() {
	println("? " + (1..100).joinToString(" "))
	println("? " + (128..12800 step 128).joinToString(" "))

	val a = readInt()
	val b = readInt()
	println("! " + ((a and 127.inv()) + (b and 127)))
}
