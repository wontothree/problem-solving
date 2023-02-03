# 내 풀이
n = int(input())


if n >= 0 and n < 3:
    count = 1575 * (n + 1)
elif n >= 3 and n < 13:
    count = 1575 * n + 3600
elif n >= 13 and n < 23:
    count = 1575 * (n - 1) + 7200
elif n == 23:
    count = 1575 * (n -2) + 10800

print(count)