import sys
def input(): return sys.stdin.readline().rstrip()
from collections import Counter
def main():
    n = int(input())
    C = input()
    C_cunt = Counter(C)
    cunt_r = C_cunt['R']
    ans = 0
    for i in range(cunt_r):
        if C[i] == 'W':
            ans += 1
    print(ans)

if __name__=='__main__':
    main()