import sys
def input(): return sys.stdin.readline().rstrip()
import math
def main():
    a,b,h,m=map(int,input().split())
    theta_a=(60*h+m)*2*math.pi/720
    theta_b=m*2*math.pi/60
    print(math.sqrt((a*math.cos(theta_a)-b*math.cos(theta_b))**2+(a*math.sin(theta_a)-b*math.sin(theta_b))**2))

if __name__=='__main__':
    main()