n = int(input())
score_arr = sorted(list(map(int, input().split())))

new_score_arr = []
for i in score_arr:
    new_score = i / score_arr[n - 1] * 100
    new_score_arr.append(new_score)

sum = 0
for i in new_score_arr:
    sum += i

average = sum / n

print(average)
