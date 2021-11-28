import sys
def input(): return sys.stdin.readline().rstrip()
from collections import Counter
def main():
	s=input()
	len_s=len(s)
	T=[0]*(len_s+1)
	T[-1],T[-2]=0,int(s[-1])
	mod=2019
	for i in range(len_s-2,-1,-1):
		T[i]=(T[i+1]+int(s[i])*pow(10,len_s-i-1,mod))%mod
	tc=list(Counter(T).values())
	ans=0
	for tcc in tc:
		ans+=tcc*(tcc-1)//2
	print(ans)

if __name__=='__main__':
    main()