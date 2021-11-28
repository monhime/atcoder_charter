import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    A=[[int(_) for _ in input().split()] for i in range(4)]
    for i in range(4):
        for j  in range(3):
            if A[i][j]==A[i][j+1]:
                print("CONTINUE")
                sys.exit()
    for i in range(3):
        for j  in range(4):
            if A[i][j]==A[i+1][j]:
                print("CONTINUE")
                sys.exit()  
    print("GAMEOVER")

if __name__=='__main__':
    main()