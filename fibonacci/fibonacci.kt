fun main(args: Array<String>) {
    fibonacci();
}

fun fibonacci(): Unit {
    var prev = 0
    var actual = 1
    var aux: Int

    for (q in 0 until 10) {
        aux = actual
        actual = prev + aux
        prev = aux
        println(actual)
    }
}

