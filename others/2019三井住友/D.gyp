import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n=int(input())
    s=input()
    ans=0
    for i in range(10):
        for j in range(10):
            for k in range(10):
                if str(i) in s:
                    index_i=s.index(str(i))
                    s1=s[index_i+1:]
                    if str(j) in s1:
                        index_j=s1.index(str(j))
                        s2=s1[index_j+1:]
                        if str(k) in s2:
                            ans+=1
    print(ans)

if __name__=='__main__':
    main()