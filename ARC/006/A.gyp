import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    E =[int(_) for _ in input().split()]
    b=int(input())
    L=[int(_) for _ in input().split()]
    cunt=0
    for l in L:
        if l  in E:
            cunt+=1
    if cunt==5:
        if b in L:
            print(2)
        else:
            print(3)
    elif cunt==6:
        print(1)
    elif cunt<=2:
        print(0)
    else:
        print(8-cunt)


if __name__=='__main__':
    main()