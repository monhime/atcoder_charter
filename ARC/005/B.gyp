import sys
def input(): return sys.stdin.readline().rstrip()
def f(x,y,w):
    nw=""
    if 'R' in w:
        if x==8:
            nw+='L'
            x=7
        else:
            nw+='R'
            x+=1
    elif 'L' in w:
        if x==0:
            nw+='R'
            x=1
        else:
            nw+='L'
            x-=1
    if 'U' in w:
        if y==0:
            nw+='D'
            y=1
        else:
            nw+='U'
            y-=1
    elif 'D' in w:
        if y==8:
            nw+='U'
            y=7
        else:
            nw+='D'
            y+=1
    return x,y,nw

def main():
    x,y,w=map(str,input().split())
    x,y=int(x)-1,int(y)-1
    C=[input() for _ in range(9)]
    ans=C[y][x]
    for i in range(3):
        x,y,w=f(x,y,w)
        ans+=C[y][x]
    print(ans)
if __name__=='__main__':
    main()