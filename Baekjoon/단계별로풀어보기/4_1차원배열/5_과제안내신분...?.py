array = []
for i in range(28):
    fac = int(input())
    array.append(fac)

student_list = []
for i in range(1, 31):
    student_list.append(i)

for i in array:
    student_list.remove(i)


print(student_list[0], student_list[1])
