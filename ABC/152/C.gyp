import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n=int(input())
    P=[int(_) for _ in input().split()]
    count=0
    min_p=10**6
    for i in range(n):
        if min_p>P[i]:
            count+=1
            min_p=P[i]
    print(count)

if __name__=='__main__':
    main()