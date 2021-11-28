import sys
def input(): return sys.stdin.readline().rstrip()
from collections import Counter
from operator import itemgetter
def main():
    n=int(input())
    V=[int(_) for _ in input().split()]
    even,odd=V[0::2],V[1::2]
    even_c,odd_c=Counter(even),Counter(odd)
    even_ci,odd_ci=list(even_c.items()),list(odd_c.items())
    even_ci.sort(key=itemgetter(1),reverse=True)
    odd_ci.sort(key=itemgetter(1),reverse=True)
    if even_ci[0][0]==odd_ci[0][0]:
        if len(even_ci)>1 and len(odd_ci)>1:
            print(min(sum(even_c.values())-even_ci[1][1]+sum(odd_c.values())-odd_ci[0][1],
                        sum(even_c.values())-even_ci[0][1]+sum(odd_c.values())-odd_ci[1][1]))
        elif len(even_ci)>1 and len(odd_ci)==1:
            print(sum(even_c.values())-even_ci[1][1])        
        elif len(even_ci)==1 and len(odd_ci)>1:
            print(sum(odd_c.values())-odd_ci[0][1])        
        else:
            print(n//2)   
    else:
        print(sum(even_c.values())-even_ci[0][1]+sum(odd_c.values())-odd_ci[0][1])

if __name__=='__main__':
    main()