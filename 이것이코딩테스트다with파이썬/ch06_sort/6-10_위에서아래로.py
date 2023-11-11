# 내 풀이
n = int(input())

array = []

for i in range(n):
    factor = int(input())
    array.append(factor)


result = sorted(array)
# array.sort()

print(array)


# 답지 풀이
n = int(input())

array = []
for i in range(n):
    array.append(int(input()))

array = sorted(array, reverse=True)

for i in array:
    print(i, end=' ')