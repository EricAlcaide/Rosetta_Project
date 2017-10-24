function factorialize(num) {
 if(num === 0) {
  return 1;
 } else if (num <= 1 ) {
  return num;
 } else {
  return num * factorialize(num - 1);
 }
}

factorialize(0);
