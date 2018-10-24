func fib(_ n: Int) -> Int {
    var M = [[1, 1], [1, 0]]
    guard n > 2 else { return n }
    power(&M, n)
    return M[0][0]
}
func power(_ matrix: inout [[Int]], _ n: Int) {
    guard n > 1 else { return }
    power(&matrix, n/2)
    matrix = multiply(matrix, matrix)
    if n % 2 != 0 {
        let M = [[1, 1], [1, 0]]
        multiply(matrix, M)
    }
}
