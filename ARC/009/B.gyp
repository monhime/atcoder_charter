import sys
def input(): return sys.stdin.readline().rstrip()
def main():
    B=[_ for _ in input().split()]
    B_dict=dict()
    for i,b in enumerate(B):
        B_dict[b]=str(i)
    n=int(input())
    A=[]
    for i in range(n):
        a=input()
        new_a=""
        for aa in a:
            new_a+=B_dict[aa]
        A.append((int(new_a),int(a)))
    A.sort()
    for a in A:
        print(a[1])

if __name__=='__main__':
    main()