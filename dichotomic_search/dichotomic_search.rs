/*
 * The Problem
 * -----------
 * Find a value inside an ordered array.
 *
 * Desired Output / Test Cases
 * ---------------------------
 * ['a','b','d','e','g','h','j','l','m','q','x'] 'z' >> null
 * ['a','b','d','e','g','h','j','l','m','q','x'] 'e' >> 'e'
 * [1,2,3,5,6,10,15] 20 >> null
 * [1,2,3,5,6,10,15] 4 >> null
 * [1,2,3,5,6,10,15] 3 >> 3
 */
 
fn dicho_search<T: PartialOrd + Clone>(v: Vec<T>, val: T) -> Option<T> {
    let (med, _) = v.len().overflowing_div(2);
    if v.len() > 1 {
        if v[med] > val { return dicho_search(v[0 .. med].to_vec(), val); }
        return dicho_search(v[med .. v.len()].to_vec(), val);
    }
    if v[med] == val { return Some(val); }
    None
}
 
fn main() {
    // Simple test
    let result = dicho_search([1,0,1,2,3].to_vec(), 2);
    println!("{}", result.unwrap());
    // Running test suite:
    assert_eq!(dicho_search(['a','b','d','e','g','h','j','l','m','q','x'].to_vec(), 'z'), None);
    assert_eq!(dicho_search(['a','b','d','e','g','h','j','l','m','q','x'].to_vec(), 'e'), Some('e'));
    assert_eq!(dicho_search([1,2,3,5,6,10,15].to_vec(), 20), None);
    assert_eq!(dicho_search([1,2,3,5,6,10,15].to_vec(), 4), None);
    assert_eq!(dicho_search([1,2,3,5,6,10,15].to_vec(), 3), Some(3));
    // If it does not panic at run-time the test passed successfully.
}
