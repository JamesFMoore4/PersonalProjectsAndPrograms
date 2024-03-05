#Returns dictionary of words and their frequencies in a string
def wordfreq(string):

    word_list = string.lower().split(" ")
    frequency_list = {}

    for i in word_list:
        if i not in frequency_list.keys():
            count = 0
            for j in word_list:
                if i == j:
                    count += 1
            frequency_list[i] = count
    return frequency_list


def main():
    print(wordfreq("Hello my helLo is hello"))


if __name__ == '__main__':
    main()
