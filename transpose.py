
def transpose(matrix):

    columns = 0
    rows = 0
    new_matrix = []

    for i in range(len(matrix)):
        rows += 1
    for i in range(len(matrix[0])):
        columns += 1
    for i in range(columns):
        new_matrix.append(list())

    index = 0
    for i in matrix:
        for j in range(len(i)):
            new_matrix[j].append(i[j])

        index += 1

    return new_matrix


nums = [
    [1, 2, 3, 4],
    [4, 5, 6, 7],
    [7, 8, 9, 10]
]

mat = transpose(nums)

for row in mat:
    print(row)
