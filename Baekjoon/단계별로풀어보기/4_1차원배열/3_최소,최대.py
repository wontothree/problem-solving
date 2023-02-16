n = int(input())
array = list(map(int, input().split()))

array_ = sorted(array)

print(array_[0], array_[n - 1])