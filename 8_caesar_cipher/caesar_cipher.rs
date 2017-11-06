// Caesar cipher in Rust
// ISSUES:
// - It works only for a latin alphabet
// TODO: 
// - Generalize replacement functions for both ASCII_LOWER and ASCII_UPPER
// - Solve the problem of negaive shift.

static ASCII_LOWER:  &'static str = "abcdefghijklmnopqrstuvwxyz";
static ASCII_UPPER:  &'static str = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
fn caesar(text: String, shift: usize) -> String {
    let mut shifted = String::with_capacity(text.len());
    let mut sh: usize;
    let mut p: usize;
    for c in text.chars() { 
        if c.is_alphabetic() {
            p = ASCII_LOWER.find(c).unwrap_or(27);
            if p != 27 {
                sh = if shift + p > 26 {shift + p - 26} else {shift + p};
                shifted.push(ASCII_LOWER.chars().nth(sh).unwrap());
            } else {
                p = ASCII_UPPER.find(c).unwrap_or(27);
                if p != 27 {
                    sh = if shift + p > 26 {shift + p - 26} else {shift + p};
                    shifted.push(ASCII_UPPER.chars().nth(sh).unwrap());
                }
            }
        } else {
            shifted.push(c);
        }
    }
    shifted
}

fn main() {
    assert_eq!(caesar("This is a caesar cipher example".to_string(), 0), "This is a caesar cipher example");
    assert_eq!(caesar("A not so long string".to_string(), 2), "C pqv uq nqpi uvtkpi");
    //No negative array indexing in Rust!
    //assert_eq!(caesar("Negative shift".to_string(), -1), "Mdfzshud rghes");
}
