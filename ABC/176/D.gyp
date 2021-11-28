import sys
def input(): return sys.stdin.readline().rstrip()
from collections import deque

def main():
    h, w = map(int,input().split())
    h += 4
    w += 4
    C_h, C_w = map(int,input().split())
    C_h += 1
    C_w += 1
    D_h, D_w = map(int,input().split())
    D_h += 1
    D_w += 1
    S = ["#"*w for hh in range(h)]
    for hh in range(2, h-2):
        S[hh] = "##" + input() + "##"
    queue = deque([C_h*w + C_w])
    ans = [-1]*(h*w)
    ans[C_h*w + C_w] = 0
    visited = [False]*(h*w)
    visited[C_h*w + C_w] = True

    queue_0 = deque([C_h*w + C_w])
    while queue_0:
        node = queue_0.popleft()
        for xnode in (node - 1, node + 1, node - w, node + w):
            if S[xnode//w][xnode%w] == "." and not visited[xnode]:
                visited[xnode] = True
                ans[xnode] = 0
                queue_0.append(xnode)
                queue.append(xnode)
    while queue:
        node = queue.popleft()
        node_h = node//w
        node_w = node%w
        for xnode_h in (node_h - 2, node_h - 1, node_h, node_h + 1, node_h + 2):
            for xnode_w in (node_w - 2, node_w - 1, node_w, node_w + 1, node_w + 2):
                xnode = xnode_h*w + xnode_w
                if S[xnode_h][xnode_w] == "." and not visited[xnode]:
                    next_ans = ans[node] + 1
                    ans[xnode] = next_ans
                    queue.append(xnode)
                    visited[xnode] = True

                    queue_0 = deque([xnode])
                    while queue_0:
                        node2 = queue_0.popleft()
                        for xnode2 in (node2 - 1, node2 + 1, node2 - w, node2 + w):
                            if S[xnode2//w][xnode2%w] == "." and not visited[xnode2]:
                                visited[xnode2] = True
                                ans[xnode2] = next_ans
                                queue_0.append(xnode2)
                                queue.append(xnode2)

#    for i in range(h):
#        print(ans[w*i:w*(i+1)])
#    gnode = D_h*w + D_w
    print(ans[D_h*w + D_w])
        
if __name__=='__main__':
    main()
