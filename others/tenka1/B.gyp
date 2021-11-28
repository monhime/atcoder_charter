import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n=int(input())
    score=[tuple(map(int,input().split())) for i in range(n)]
    score.sort(reverse=True)
    print(score[0][0]+score[0][1])


if __name__=='__main__':
    main()