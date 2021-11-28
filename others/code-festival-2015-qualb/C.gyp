import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n,m=map(int,input().split())
    A=[int(_) for _ in input().split()]
    B=[int(_) for _ in input().split()]
    A.sort(reverse=True)
    B.sort(reverse=True)
    room=0
    for i in range(m):
        if room ==n or A[room]<B[i]:
            print("NO")
            break
        else:
            room+=1
    else:
        print("YES")

if __name__=='__main__':
    main()