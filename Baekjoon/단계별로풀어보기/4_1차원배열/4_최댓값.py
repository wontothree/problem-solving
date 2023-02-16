array = []
for i in range(9):
    num = int(input())
    array.append(num)

sorted_array = sorted(array)

count = 1
for i in array:
    if sorted_array[8] != i:
        count += 1
    else:
        break

print(sorted_array[8], count, sep='\n')