array = []
for i in range(10):
    fac = int(input())
    array.append(fac)

spare_list = []
for i in array:
    spare = i % 42
    spare_list.append(spare)

spare_set = set(spare_list)

print(len(spare_set))