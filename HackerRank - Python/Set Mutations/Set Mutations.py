n = int(input())
s1 = set(input().split())

q = int(input())

for i in range(q):
    input_ = input().split()
    s2 = set(input().split())
    eval('s1.'+input_[0]+'(s2)')

sum_list = list(map(int, s1))
print(sum(sum_list))
    
