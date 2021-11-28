import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    x=int(input())
    year=0
    yen=100
    while True:
        year+=1
        yen=yen*1.01//1
        if yen>=x:
            print(year)
            break

if __name__=='__main__':
    main()