
def convert(binary):

    binary = binary[::-1]
    num = 0

    for i in range(len(binary)):
        if binary[i] == '1':
            num += 2 ** i

    return num


print(convert('01111111'))
