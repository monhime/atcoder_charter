import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    a,b=map(int,input().split())
    for x in range(1,1100):
        if int(x*0.08)==a and int(x*0.1)==b:
            print(x)
            break
    else:print(-1)

if __name__=='__main__':
    main()