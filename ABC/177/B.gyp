import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    S = input()
    T = input()
    len_s = len(S)
    len_t = len(T)
    ans = 1000
    for i in range(len_s-len_t+1):
        cunt = 0
        for j in range(len_t):
            if S[i+j] != T[j]:
                cunt += 1
        ans = min(ans, cunt)
    print(ans)

if __name__=='__main__':
    main()