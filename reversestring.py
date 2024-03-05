
def reverse(string):

    reverse_string = ""

    i = -1
    while i >= -len(string):
        reverse_string += string[i]
        i -= 1

    return reverse_string

print(reverse("Hello"))
