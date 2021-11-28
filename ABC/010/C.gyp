import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    tx_a,ty_a,tx_b,ty_b,T,V=map(int,input().split())
    n=int(input())
    for i in range(n):
        x,y=map(int,input().split())
        if ((tx_a-x)**2+(ty_a-y)**2)**0.5+((tx_b-x)**2+(ty_b-y)**2)**0.5<=T*V:
            print("YES")
            break
    else:
        print("NO")

if __name__=='__main__':
    main()