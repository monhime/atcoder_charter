import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    w="DiscoPresentsDiscoveryChannelProgrammingContest2016"
    x=int(input())
    for i in range(-(-len(w)//x)):
        print(w[x*i:min(len(w),x*(i+1))])

if __name__=='__main__':
    main()