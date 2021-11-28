import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n, k =map(int,input().split())
    A = list(map(int,input().split())) + [0]
    while k > 0:
        B = [0] * (n + 1) 
        for i, a in enumerate(A):
            B[max(0, i - a)] += 1
            B[min(n, i + a + 1)]  -= 1
        if B[0] == n:
            flag = True
        for i in range(1, n+1):
            B[i] += B[i-1]
            if B[i] != n and i < n:
                flag = False
        A = B[:]
        if flag:
            break
        k -= 1
    print(" ".join(map(str, B[:-1])))

if __name__=='__main__':
    main()