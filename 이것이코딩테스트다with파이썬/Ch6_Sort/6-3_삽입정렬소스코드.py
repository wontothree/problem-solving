array = [7, 5, 9, 0, 3, 1, 6, 2, 4, 8]

for i in range(len(array)):
    for j in range(i, 0, -1): # 인덱스 i부터 1까지 감소하며 반복하는 문법
        if array[j] < array[j - 1]: # 한 칸 씩 왼쪽으로 이동
            array[j], array[j - 1] = array[j - 1], array[j]
        else:
            break

print(array)