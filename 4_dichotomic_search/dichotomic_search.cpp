// dichotomic search implemented in C++ for Rosetta Project
#include <iostream>
#include <vector>
#include <math.h>
#include <assert.h>
using namespace std;

template <class T>
bool dichotomic_search(const vector<T> &arr, T key) {
    int mid = floor(arr.size() / 2);
    
    if (arr.size() < 1) {
        return false;
    }
    if (arr.size() == 1) {
        return (arr[0] == key) ? true : false;
    }
    if (arr[mid] > key) {
        vector<T> arr_half1(arr.begin(), (arr.begin() + arr.size() / 2));
        return dichotomic_search(arr_half1, key);
    }
    vector<T> arr_half2((arr.begin() + arr.size() / 2), arr.end());
    return dichotomic_search(arr_half2, key);
}

int main() {
    int arr_test1[5] = { 1, 2, 3, 4, 5 };
    char arr_test2[5] = { 'a', 'b', 'c', 'd', 'e' };
    vector<int> test1(arr_test1, arr_test1 + sizeof arr_test1 / sizeof arr_test1[0]);
    vector<char> test2(arr_test2, arr_test2 + sizeof arr_test2 / sizeof arr_test2[0]);

    cout << "test: try to find 5 in list { 1, 2, 3, 4, 5 }. . .";
    assert(dichotomic_search(test1, 5) == true);
    cout << "passed\n";
    cout << "test: try to find 7 in list { 1, 2, 3, 4, 5 }. . .";
    assert(dichotomic_search(test1, 7) == false);
    cout << "passed\n";
    cout << "test: try to find -1 in list { 1, 2, 3, 4, 5 }. . .";
    assert(dichotomic_search(test1, -1) == false);
    cout << "passed\n";
    cout << "test: try to find b in list { a, b, c, d, e }. . .";
    assert(dichotomic_search(test2, 'b') == true);
    cout << "passed\n";
    cout << "test: try to find c in list { a, b, c, d, e }. . .";
    assert(dichotomic_search(test2, 'c') == true);
    cout << "passed\n";
    cout << "test: try to find z in list { a, b, c, d, e }. . .";
    assert(dichotomic_search(test2, 'z') == false);
    cout << "passed\n";
    
    return 0;
}