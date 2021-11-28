import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n=int(input())
    ng=[int(input())for _ in range(3)]
    ng.sort()
    if (ng[2]==ng[1]+1 and ng[1]==ng[0]+1 and ng[0]<n) or (n in ng):
        print("NO")
        sys.exit()
    cunt=0
    while n>0:
        cunt+=1
        if n-3 in ng:
            if n-2 in ng:
                n-=1
                continue
            n-=2
            continue
        n-=3
    if cunt<=100:
        print("YES")
    else:
        print("NO")

    

if __name__=='__main__':
    main()