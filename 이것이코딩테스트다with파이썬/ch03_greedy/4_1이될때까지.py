# 내 풀이
n, k = map(int, input().split())

value = n
count = 0
while value >= k:
    remainder = value % k
    count += remainder

    value = value // k
    count += 1


count += value - 1
print(count)