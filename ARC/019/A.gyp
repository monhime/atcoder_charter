import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    s=input()
    list_a=['O','D','I','Z','S','B']
    list_b=['0','0','1','2','5','8']
    ans=""
    for ss in s:
        if ss in list_a:
            ans+=list_b[list_a.index(ss)]
        else:
            ans+=ss
    print(ans)

if __name__=='__main__':
    main()