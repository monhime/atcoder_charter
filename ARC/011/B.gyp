import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    n=int(input())
    S=input().lower()
    lis=dict()
    lis['b']=1
    lis['c']=1
    lis['d']=2
    lis['w']=2
    lis['t']=3
    lis['j']=3
    lis['f']=4
    lis['q']=4
    lis['l']=5
    lis['v']=5
    lis['s']=6
    lis['x']=6
    lis['p']=7
    lis['m']=7
    lis['h']=8
    lis['k']=8
    lis['n']=9
    lis['g']=9
    lis['z']=0
    lis['r']=0
    ans=''
    for s in S:
        if s==',' or s=='.' or s=='a' or s=='i' or s=='u' or s=='e' or s=='o' or s=='y':
            continue
        elif s==' ':
            ans+=' '
        else:
            ans+=str(lis[s])
    print(*list(ans.split()))


if __name__=='__main__':
    main()