import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n = int(input())
    A = list(map(int,input().split()))
    max_pos = 0
    now_pos = 0
    move_all = 0
    max_move = - 10**8
    for i in range(n):
        move_all += A[i]
        max_move = max(max_move, move_all)
        max_pos = max(max_pos, now_pos + max_move)
        now_pos += move_all
    print(max_pos)

if __name__=='__main__':
    main()