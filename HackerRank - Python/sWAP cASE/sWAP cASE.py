def swap_case(s):
    s = list(s)
    i = 0
    for c in s:
        if c.islower():
            s[i] = c.upper()
        else:
            s[i] = c.lower()
        i+=1
    return ''.join(s)


if __name__ == '__main__':
    s = input()
    result = swap_case(s)
    print(result)

    