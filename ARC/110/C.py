import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n = int(input())
    P = list(map(int,input().split()))
    T = [0] * n
    cunt = 0
    ANS = []
    if P[0] == 1:
        print(-1)
        sys.exit()
        
    num = 1 #探す数
    pre_idx = 0 
    while num < n:
        for i in range(n):
            if P[i] == num: 
                idx = i #numがある場所
        
        for i in range(idx - 1, pre_idx - 1, -1):
            P[i], P[i + 1] = P[i + 1], P[i]
            ANS.append(i + 1)

        for i in range(pre_idx, idx):
            if P[i] != i + 1:
                print(-1)
                sys.exit()
        print(idx, pre_idx)
        pre_idx = idx
        num = idx + 1 #次に探す数字
    
    print('\n'.join(map(str,ANS)))
    
        


if __name__=='__main__':
    main()