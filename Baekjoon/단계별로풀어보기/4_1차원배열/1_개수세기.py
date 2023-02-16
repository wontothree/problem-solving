n = int(input())
data = list(map(int, input().split()))
num = int(input())

count = 0
for i in data:
    if num == i:
        count += 1

print(count)