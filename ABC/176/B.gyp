import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n = int(input())
    C = input()
    cunt_left, cunt_right = 0, 0
    cunt_r, cunt_w = 0, 0
    if n % 2 == 0:
        for i in range(n//2):
            if C[i] == 'W':
                cunt_left += 1
                cunt_w += 1
            else:
                cunt_r += 1
        for i in range(n//2,n):
            if C[i] == 'R':
                cunt_right += 1
                cunt_r += 1
            else:
                cunt_w += 1 
    else:
        for i in range(n//2):
            if C[i] == 'W':
                cunt_left += 1
                cunt_w += 1
            else:
                cunt_r += 1
        if C[n//2] == 'W':
            cunt_w += 1
        else:
            cunt_r += 1
        for i in range(n//2+1, n):
            if C[i] == 'R':
                cunt_right += 1
                cunt_r += 1
            else:
                cunt_w += 1 
    if cunt_r*cunt_w == 0:
        print(0)
    else:
        print(max(cunt_left, cunt_right))


if __name__=='__main__':
    main()