import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    x=int(input())
    for a in range(-118,120):
        for diff in range(1,238):
            if a**5-(a-diff)**5>10**9:
                break
            if a**5-(a-diff)**5==x:
                print(a,a-diff)
                sys.exit()

if __name__=='__main__':
    main()