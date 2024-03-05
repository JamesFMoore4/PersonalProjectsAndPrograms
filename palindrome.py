
def palindrome(string):

    string = string.strip()
    string = string.lower()
    string2 = string[::-1]

    if string == string2:
        return True

    return False


def main():

    test_string = "racecar"
    test_string2 = "Test"

    print(palindrome(test_string))
    print(palindrome(test_string2))


if __name__ == '__main__':
    main()
