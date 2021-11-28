import sys
def input(): return sys.stdin.readline().rstrip()
import datetime
def main():
    sx=datetime.datetime(int(input()),int(input()),int(input()))
    sy= datetime.datetime(2014, 5, 17)
    print((sy-sx).days)

if __name__=='__main__':
    main()