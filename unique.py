#Returns a list with only unique items
def unique(values):

    values_new = list()
    excluded = list()

    for i in values:
        count = 0
        for j in values:
            if i == j:
                count += 1
        if count == 1 and i not in excluded:
            values_new.append(i)
        excluded.append(i)

    print(excluded)

    return values_new


print(unique(['hello', 'hello', 'test', 1, 1, 1, 2, 3, 4]))
