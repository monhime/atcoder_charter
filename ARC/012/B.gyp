import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n,v_a,v_b,l=map(int,input().split())
    for i in range(n):
        l=l/v_a*v_b
    print("{:.8f}".format(l))

if __name__=='__main__':
    main()