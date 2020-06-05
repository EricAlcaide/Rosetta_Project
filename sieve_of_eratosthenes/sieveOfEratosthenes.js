var sieveOfEratosthenes = (n) => {
  let bools = [];

  for (let i = 2; i <= n; i++) bools.push(true);

  for (let i = 2; i < Math.sqrt(n); i++) {
  	// For index values which remain true in the set of 'bools'
  	// after the while loops (below) -- those are primes.
  	if (bools[i] === true) {
  		// 'i' is a prime number.
  		let j = i*i,
  		    x = 1;
  		bools[j] = false;
  		while (j <= n) {
  			// Set every multiple of 'i' to false.
  			j = i * i + x * i;
        bools[j] = false;
        x++;
  		}
  	}
  } 
  let primes = [];
  for (let i = 2; i <= n; i++) {
  	if (bools[i] === true) primes.push(i);
  }

  return primes;
};