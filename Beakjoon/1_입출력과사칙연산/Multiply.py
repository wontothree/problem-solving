# 몫과 나머지를 이용한 방법
# a = int(input())
# b = int(input())

# print(a * (b % 10))
# print(a * (b // 10 % 10))
# print(a * (b // 100))
# print(a * b)

# 문자열을 이용하는 방법
a = int(input())
b = input()

print(a * int(b[2]))
print(a * int(b[1]))
print(a * int(b[0]))
print(a * int(b))