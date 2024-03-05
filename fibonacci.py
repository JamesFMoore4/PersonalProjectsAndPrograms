
def fibonacci(n):

    if n == 0:
        return None
    elif n == 1:
        return 0

    x = 0
    y = 1
    numbers = []

    i = 0
    while i <= n:
        numbers.append(x)
        z = x + y
        y, x = z, y
        i += 1

    return numbers


def main():
    print(fibonacci(7))


if __name__ == '__main__':
    main()
