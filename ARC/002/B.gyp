import sys
def input(): return sys.stdin.readline().rstrip()
import datetime
def main():
    s=input()
    s=datetime.datetime.strptime(s,'%Y/%m/%d')
    while True:
        year=s.year
        month=s.month
        day=s.day
        if year%(month*day)==0:
            print(s.strftime("%Y/%m/%d"))
            break
        s+=datetime.timedelta(days=1)
        

if __name__=='__main__':
    main()