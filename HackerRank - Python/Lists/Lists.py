if __name__ == '__main__':
    n = int(input())
    list_ = []
    
    for i in range(n+1):
        input_list = input().split(' ')
        if input_list[0] == 'insert':
            list_.insert(int(input_list[1]), int(input_list[2]))
        elif input_list[0] == 'remove':
            list_.remove(int(input_list[1]))
        elif input_list[0] == 'append':
            list_.append(int(input_list[1]))
        elif input_list[0] == 'sort':
            list_.sort()
        elif input_list[0] == 'reverse':
            list_.reverse()
        elif input_list[0] == 'pop':
            list_.pop()
        elif input_list[0] == 'print':
            print(list_)
        
