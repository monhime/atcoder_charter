import sys
def input(): return sys.stdin.readline().rstrip()
def cunt(n):
    return n//4-n//100+n//400

def main():
    a,b=map(int,input().split())
    print(cunt(b)-cunt(a-1))

if __name__=='__main__':
    main()