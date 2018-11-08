if __name__ == '__main__':
    l = []
    for _ in range(int(input())):
        name = input()
        score = float(input())
        l.append([score, name])
    l.sort()
    second_lowest = l[0]
    
    while True:
        if (l[0][0] == second_lowest[0]):
            l.remove(l[0])
        else:
            break
    
    second_lowest = l[0]
    final_l = []
    for i in range(len(l)):
        if (second_lowest[0] == l[i][0]):
            final_l.append(l[i][1])
    
    final_l.sort()
    for i in range(len(final_l)):
        print(final_l[i])
        

        