import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n=int(input())
    W=[int(input())for _ in range(n)]
    WL=[]
    for w in W:
        for i,wl in enumerate(WL):
            if w<=wl:
                WL[i]=w
                break
        else:
            WL.append(w)
    print(len(WL))

if __name__=='__main__':
    main()