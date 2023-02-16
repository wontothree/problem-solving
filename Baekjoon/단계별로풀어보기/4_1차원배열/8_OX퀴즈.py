n = int(input())

test_case = []
for i in range(n):
    test_case.append(input())


for i in test_case:
    score = 0
    k = 0
    for fac in i:
        if fac == 'X':
            score += 0
            k = 0

        elif fac == 'O':
            score += k + 1
            k += 1

    print(score)

