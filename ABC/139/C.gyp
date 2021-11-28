import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n=int(input())
    H=[int(_) for _ in input().split()]
    count=0
    max_count=0
    for i in range(n-1):
        if H[i+1]<=H[i]:
            count+=1
            max_count=max(count,max_count)
        else:count=0
    print(max_count)
if __name__=='__main__':
    main()