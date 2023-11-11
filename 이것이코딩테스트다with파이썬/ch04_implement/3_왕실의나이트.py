import time

# 내 풀이
p = input()

start_time = time.time()

if p == "a1" or p == "a8" or p == "h1" or p == "h8":
    count = 2
elif p == "a2" or p == "b1" or p == "a7" or p == "b8" or p == "g1" or p == "h2" or p == "g8" or p == "h7":
    count = 3
elif (p[0] == 'c' or p[0] == 'd' or p[0] == 'e' or p[0] == 'f') and (p[1] == '3' or p[1] == '4' or p[1] == '5' or p[1] == '6'):
    count = 8
elif ((p[0] == 'b' or p[0] == 'g') and (p[1] == '3' or p[1] == '4' or p[1] == '5' or p[1] == '6')) or ((p[1] == '2' or p[1] == '7') and (p[0] == 'c' or p[0] == 'd' or p[0] == 'e' or p[0] == 'f')):
    count = 6
else:
    count = 4

print(count)

end_time = time.time()
print("time: ", end_time - start_time)


# 답지 풀이
# 현재 나이트의 위치 입력받기
input_data = input()
row = int(input_data[1])
column = int(ord(input_data[0])) - int(ord('a')) + 1

# 나이트가 이동할 수 있는 8가지 방향 정의
steps = [(-2, -1), (-1, -2), (1, -2), (2, -1), (2, 1), (1, 2), (-1, 2), (-2, 1)]

# 8가지 방향에 대하여 각 위치로 이동이 가능한지 확인
result = 0
for step in steps:
    # 이동하고자 하는 위치 확인
    next_row = row + step[0]
    next_column = column + step[1]
    # 해당 위치로 이동이 가능하다면 카운트 증가
    if next_row >= 1 and next_row <= 8 and next_column >= 1 and next_column <= 8:
        result += 1

print(result)