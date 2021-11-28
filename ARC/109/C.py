import sys
def input(): return sys.stdin.readline().rstrip()
sys.setrecursionlimit(20000)
def zyanken(rps_a, rps_b):  #0以上ならaが勝ち
    if rps_a == rps_b:
        return rps_a
    else:
        if rps_a == 'R':
            if rps_b == 'P':
                return rps_b
            elif rps_b == 'S':
                return rps_a
        if rps_a == 'P':
            if rps_b == 'S':
                return rps_b
            elif rps_b == 'R':
                return rps_a
        if rps_a == 'S':
            if rps_b == 'R':
                return rps_b
            elif rps_b == 'P':
                return rps_a

def main():
    n, k  = map(int,input().split())
    s = input()*2 # s[i mod n] が得意な手

    for cunt in range(k):
        new_s = ""
        for i in range(0, len(s), 2):
            new_s += zyanken(s[i], s[i + 1])
        s = new_s * 2
    print(s[0])



if __name__=='__main__':
    main()