/*
 * The Problem
 * -----------
 * Print the 10 first numbers of the Fibonacci Series starting @ the second 1.
 *
 * Desired Output / Test Cases
 * ---------------------------
 * 1 2 3 5 8 13 21 34 55 89
 */

fn fibonacci(n: i32) -> i32 {
    if n <= 1 { return n;}
    fibonacci(n-1) + fibonacci(n-2)
}

fn main() {
    // it start to 2 and ends to 11, because of the shift of lefting behind the first 1 in the series...
    for i in 2..12 {
        print!("{} ", fibonacci(i));
    }
}
