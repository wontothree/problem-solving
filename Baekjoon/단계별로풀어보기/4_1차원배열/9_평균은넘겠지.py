n = int(input())

test_case = []
for i in range(n):
    test_case.append(list(map(int, input().split())))

for i in test_case:
    sum = 0
    for j in i:
        sum += j
    sum -= i[0]

    avg = sum / (len(i) - 1)

    count = 0
    for k in i:
        if k > avg:
            count += 1

    ppr = count / (len(i) - 1) * 100

    print(float("{:.3f}".format(ppr)), '%', sep='')
