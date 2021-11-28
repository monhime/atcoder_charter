import sys
def input(): return sys.stdin.readline().rstrip()
def Base_n_to_10(n):
    ans=0
    n=str(n)
    for i in range(len(n)):
        ans+=int(n[-1-i])*(int(n)**i)
    return ans

def main():
    a=int(input())
    x=0
    i=10
    while x<=a:
        x=Base_n_to_10(i)
        if x==a:
            print(i)
            break
        i+=1
    else:
        print(-1)

if __name__=='__main__':
    main()