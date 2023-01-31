import time

# 내 풀이
n, m = map(int, input().split())

list_matrix = []
list_minimum_of_row = []

for i in range(n):
    list_matrix.append(list(map(int, input().split())))


start_time = time.time()


for index, row in enumerate(list_matrix):
    row.sort()
    list_minimum_of_row.append(row[0])

list_minimum_of_row.sort()

print(list_minimum_of_row[n - 1])


end_time = time.time()
print("time:", end_time - start_time)



# 정답1
# N, M을 공백으로 구분하여 입력받기
n, m = map(int, input().split())

result = 0
# 한 줄씩 입력 받아 확인
for i in range(n):
    data = list(map(int, input().split()))
    # 현재 줄에서 가장 작은 수 찾기
    min_value = min(data)
    result = max(result, min_value)

print(result)


# 정답2
# N, M을 공백으로 구분하여 입력받기
n, m = map(int, input().split())

result = 0
# 한 줄씩 입력받아 확인
for i in range(n):
    data = list(map(int, input().split()))
    # 현재 줄에서 가장 작은 수 찾기
    min_value = 10001
    for a in data:
        min_value = min(min_value, a)
    # 가장 작은 수들 중에서 가장 큰 수 찾기
    result = max(result, min_value)

print(result)


"""
교훈: enumerate 함수, min 함수, max 함수
"""