fun main(args : Array<String>) {
    println(factorialize(7))
}

private fun factorialize(n: Int): Int {
    return when  {
        n == 0 -> 1
        n <= 1 -> n
        else -> n * factorialize(n - 1)
    }
}