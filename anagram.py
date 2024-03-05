
def isanagram(string1, string2):

    first = list()
    second = list()

    string1 = string1.lower()
    string2 = string2.lower()

    for i in string1:
        if i != " ":
            first.append(i)

    for i in string2:
        if i != " ":
            second.append(i)

    first.sort()
    second.sort()

    if first == second:
        return True

    return False


print(isanagram("Hello", "he llo"))

