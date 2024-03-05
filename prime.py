
def primelist(n):

    primes = []
    exclude = []

    if n < 2:
        return None

    for i in range(2, n + 1):
        for j in range(2, n + 1):
            num = i * j
            if num <= n and num not in exclude:
                exclude.append(num)

    for h in range(2, n + 1):
        if h not in exclude:
            primes.append(h)

    return primes


print(primelist(50))
