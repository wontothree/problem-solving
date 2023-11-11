# 내 풀이
n = int(input())

array = []
for i in range(n):
    name, score = input().split()
    score = int(score)
    array.append([name, score])


for index1 in range(len(array)):
    for index2 in range(index1, len(array)):
        if array[index1][1] > array[index2][1]:
            array[index1], array[index2] = array[index2], array[index1]

print(array)

# 답지 풀이
n = int(input())

array = []
for i in range(n):
    input_data = input().split()
    array.append((input_data[0], int(input_data[1])))

array = sorted(array, key=lambda student: student[1])

for student in array:
    print(student[0], end = ' ')
