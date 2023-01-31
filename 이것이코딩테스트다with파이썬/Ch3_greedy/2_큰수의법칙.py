import time

# 내 풀이
# N, M, K를 공백으로 구분하여 입력받기 - 해설 참고
n, m, k = map(int, input().split())
# N개의 수를 공백으로 구분하여 입력받기 - 해설 참고
data = list(map(int, input().split()))


start_time = time.time()

for index1 in range(n):
    for index2 in range(index1, n):
        if data[index1] < data[index2]:
            save = data[index1]
            data[index1] = data[index2]
            data[index2] = save

x = data[0]
y = data[1]

share = m // (k+1)
remainder = m % (k+1)

print(share * (k * x + y) + remainder * x)


end_time = time.time()
print("time:", end_time - start_time)


# 정답1
# N, M, K를 공백으로 구분하여 입력받기
n, m, k = map(int, input().split())
# N개의 수를 공백으로 구분하여 입력받기
data = list(map(int, input().split()))

start_time = time.time()

data.sort() # 입력받은 수들 정렬하기
first = data[n - 1] # 가장 큰 수
second = data[n - 2] # 두 번째로 큰 수

result = 0

while True:
    for i in range(k): # 가장 큰 수를 K번 더하기
        if m == 0: # m이 0이라면 반복문 탈출
            break
        result += first
        m += 1 # 더할 때마다 1씩 빼기

    if m == 0: # m이 0이라면 반복문 탈출
        break
    result += second # 두 번째로 큰 수를 한번 더하기
    m -= 1 #더할 때마다 1씩 빼기

print(result)

end_time = time.time()
print("time:", end_time - start_time)


# 정답2
# N, M, K를 공백으로 구분하여 입력받기
n, m, k = map(int, input().split())
# N개의 수를 공백으로 구분하여 입력받기
data = list(map(int, input().split()))

start_time = time.time()

data.sort()
first = data[n - 1]
second = data[n - 2]

count = int(m / (k + 1)) * k
count += m % (k + 1)

result = 0
result += count * first
result += (m - count) * second

print(result)

end_time = time.time()
print("time:", end_time - start_time)
