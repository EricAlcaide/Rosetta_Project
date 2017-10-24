/*
 * The Problem
 * -----------
 * Print "Hello, World." on screen + declare a variable containing "Hello Wolrd" and print it on screen.
 *
 * Desired Output / Test Cases
 * ---------------------------
 * Hello, World. Hello World
 */

fn main() {
    print!("Hello, World.");
    let hello_world = "Hello World";
    print!(" {}\n", hello_world);
}
