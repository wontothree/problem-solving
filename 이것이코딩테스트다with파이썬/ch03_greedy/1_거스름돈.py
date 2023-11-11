import time
start_time = time.time()


# 내 풀이
balance = 1260

count_500 = balance // 500

balance %= 500

count_100 = balance // 100

balance %= 100

count_50 = balance // 50

balance %= 50

count_10 = balance // 10

print("동전의 개수", count_500 + count_100 + count_50 + count_10)


end_time = time.time()
print("time:", end_time - start_time)


# 정답
start_time = time.time()

n = 1260
count = 0

# 큰 단위 화폐부터 차례대로 확인
coin_type = [500, 100, 50, 10]

for coin in coin_type:
    count += n // coin # 해당 화폐로 거슬러 줄 수 있는 동전의 개수 세기
    n %= coin

print(count)

"""
교훈: 반복되는 부분은 반복문을 이용해서 단순화할 수 있다.
"""
