import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    k=int(input())
    a=1
    b=0
    for i in range(k):
        a,b=a+b,a
        if i==0:a=5
    print(a,b)

if __name__=='__main__':
    main()