if __name__ == '__main__':
    n = int(input())
    arr = list(map(int, input().split()))
    
    max_n = max(arr)
    while max(arr) == max_n:
        arr.remove(max_n)
        
    print(max(arr))

    