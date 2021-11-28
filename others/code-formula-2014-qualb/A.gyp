import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n=input()
    n_len=len(n)
    sum_ev,sum_odd=0,0
    for i in range(n_len,0,-2):
        sum_odd+=int(n[i-1])
    for i in range(n_len-1,0,-2):
        sum_ev+=int(n[i-1])
    print(sum_ev,sum_odd)
    

if __name__=='__main__':
    main()