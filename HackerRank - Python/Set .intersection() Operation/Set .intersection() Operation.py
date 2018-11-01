a = int(input())
arr_a = input().split(' ')

b = int(input())
arr_b = input().split(' ')

s1 = set(arr_a)
s2 = set(arr_b)

print(len(s1.intersection(s2)))
