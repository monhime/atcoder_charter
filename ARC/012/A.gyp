import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    s=input()
    list_a=["Monday","Tuesday","Wednesday","Thursday","Friday"]
    if s in list_a:
        print(5-list_a.index(s))
    else:print(0)

if __name__=='__main__':
    main()