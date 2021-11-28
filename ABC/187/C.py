import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n = int(input())
    S = [input() for i in range(n)]
    S.sort()
    for i, s in enumerate(S):
        if s[0] != '!':
            idx_s2 = i
            break
    else:
        print('satisfiable')
        sys.exit()
    #print(S)
    for i in range(idx_s2):
        s1 = S[i][1:]
        while True:
            #print(i, idx_s2)
            s2 = S[idx_s2]
            if s2 > s1:
                break
            if s2 == s1:
                print(s1)
                sys.exit()
            idx_s2 += 1
            if idx_s2 == n:
                print('satisfiable')
                sys.exit()
    print('satisfiable')            


if __name__=='__main__':
    main()