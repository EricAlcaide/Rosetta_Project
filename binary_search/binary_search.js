function binary_search(list, item) {
  var low = 0,
      high = list.length - 1,
      mid,
      guess;
  while (low <= high) {
    mid = Math.round((low + high) / 2),
    guess = list[mid];
    console.log("guess="+guess);
    if (guess < item) {
      low = mid + 1;
      console.log("if");
    }
    else if (guess > item) {
      high = mid - 1;
      console.log("else if");
    } else {
      console.log("else");
      return mid;
    }
    console.log("end while");
  }
  console.log("return");
  return -1;
}
my_list = [1, 3, 5, 7, 9]
console.log(binary_search(my_list,3));