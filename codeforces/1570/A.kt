fun main() {
	var t = readLine()!!.toInt()

	while (t-- > 0) {
		val (a, b) = readLine()!!.split(" ").map{it.toInt()}
		println(a + b)
	}
}
