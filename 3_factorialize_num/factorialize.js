function factorialize(num) {
 if(num === 0) {
  return 1;
 } else if (num <= 1 ) {
  return num;
 } else {
  var ans = 1;
  for(var i=2;i<=num;i+=1) {
    ans *= i;
  }
  return ans;
 }
}

console.log(factorialize(0));
console.log(factorialize(1));
console.log(factorialize(5));
console.log(factorialize(10));
