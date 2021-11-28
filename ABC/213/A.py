import sys
def input(): return sys.stdin.readline().rstrip()
def xor(a, b):
    if a == b:
        return 0
    else:
        return 1

def main():
    a, b = map(int,input().split())
    c = 0
    for i in range(8):
        c +=  xor(a%2, b%2) * 2**i
        a //= 2
        b //= 2
    print(c)

if __name__=='__main__':
    main()