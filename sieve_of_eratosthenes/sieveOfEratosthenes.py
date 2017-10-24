def sieveOfEratosthenes(n):
    if n < 2:
        return []

    bools = [False, False]

    for _ in range(2, n + 1):
        bools.append(True)

    for i in range(2, round(n ** 0.5)):
        if bools[i] == True:
            j = i * i
            x = 1
            if j <= n:
                bools[j] = False
            while j <= n:
                j = i * i + x * i
                if j <= n:
                    bools[j] = False
                x += 1

    primes = []
    for i in range(2, n + 1):
        if bools[i] == True:
            primes.append(i)

    return primes

print(sieveOfEratosthenes(100))
