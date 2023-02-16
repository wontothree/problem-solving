n, x = map(int, input().split())
data = list(map(int, input().split()))

array = []
for i in data:
    if x > i:
        print(i, end=' ')

