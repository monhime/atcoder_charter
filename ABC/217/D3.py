import copy
import sys
import math
import copy
from fractions import gcd
from collections import Counter, deque, defaultdict
from heapq import heappush, heappop, heappushpop, heapify, heapreplace, merge
from bisect import bisect_left, bisect_right, bisect, insort_left, insort_right, insort
from itertools import accumulate, product, permutations, combinations
from operator import itemgetter
# sys.setrecursionlimit(1000000)


def input(): return sys.stdin.readline().rstrip()


class Node:
    def __init__(self, key, val):
        self.key = key  # ノードのキー。比較可能なものであれば良い。(1, 4)などタプルも可。
        self.val = val  # ノードの値。
        self.lch = None  # 左の子ノード。
        self.rch = None  # 右の子ノード。
        self.bias = 0  # 平衡度。(左部分木の高さ)-(右部分木の高さ)。
        self.size = 1  # 自分を根とする部分木の大きさ


class AVLTree:
    # Reference: https://qiita.com/tomato1997/items/2f9b3ac919d230ac68ec
    """
    共通
    AVL.lower_bound(x), AVL.upper_bound(x)
    AVL.find_kth_element(k) (k(0-))
    AVL.popmin(), AVL.popmax()
    AVL.popkth(k) (k(0-))
    x in AVL
    list(AVL)
    len(AVL)

    平衡二分探木
    AVL = AVLTree()
    AVL.insert(x)

    辞書
    AVL = AVLTree()
    AVL[key] = value

    defaultdict
    AVL = AVLTree(valdefault = [])
    AVL[key].append(value)
    AVL[key].pop() #?

    Counter
    AVL = AVLTree(valdefault = 0)
    AVL[key] += x
    for key, value in AVL.items()
    """

    def __init__(self, valdefault=None):
        self.root = None  # 根ノード。初期値はNone。
        self.valdefault = valdefault  # ノード値のデフォルト値。デフォルトではNone。（数値、リストなど可）

    def rotate_left(self, v):
        u = v.rch
        u.size = v.size
        v.size -= u.rch.size + 1 if u.rch is not None else 1
        v.rch = u.lch
        u.lch = v
        if u.bias == -1:
            u.bias = v.bias = 0
        else:
            u.bias = 1
            v.bias = -1
        return u

    def rotate_right(self, v):
        u = v.lch
        u.size = v.size
        v.size -= u.lch.size + 1 if u.lch is not None else 1
        v.lch = u.rch
        u.rch = v
        if u.bias == 1:
            u.bias = v.bias = 0
        else:
            u.bias = -1
            v.bias = 1
        return u

    def rotateLR(self, v):
        u = v.lch
        t = u.rch
        t.size = v.size
        v.size -= u.size - (t.rch.size if t.rch is not None else 0)
        u.size -= t.rch.size + 1 if t.rch is not None else 1
        u.rch = t.lch
        t.lch = u
        v.lch = t.rch
        t.rch = v
        self.update_bias_double(t)
        return t

    def rotateRL(self, v):
        u = v.rch
        t = u.lch
        t.size = v.size
        v.size -= u.size - (t.lch.size if t.lch is not None else 0)
        u.size -= t.lch.size + 1 if t.lch is not None else 1
        u.lch = t.rch
        t.rch = u
        v.rch = t.lch
        t.lch = v
        self.update_bias_double(t)
        return t

    def update_bias_double(self, v):
        if v.bias == 1:
            v.rch.bias = -1
            v.lch.bias = 0
        elif v.bias == -1:
            v.rch.bias = 0
            v.lch.bias = 1
        else:
            v.rch.bias = 0
            v.lch.bias = 0
        v.bias = 0

    def insert(self, key, val=None):
        """
        keyを挿入する。valはkeyのノード値。同じキーがあった場合は上書きする。
            key (any): キー。
            val (any): 値。（指定しない場合はvaldefaultが入る）
        """
        if val == None:
            val = copy.deepcopy(self.valdefault)
        if self.root is None:
            self.root = Node(key, val)
            return
        v = self.root
        history = []
        while v is not None:
            if key < v.key:
                history.append((v, 1))
                v = v.lch
            elif v.key < key:
                history.append((v, -1))
                v = v.rch
            elif v.key == key:
                v.val = val
                return
        p, pdir = history[-1]
        if pdir == 1:
            p.lch = Node(key, val)
        else:
            p.rch = Node(key, val)
        while history:
            v, direction = history.pop()
            v.bias += direction
            v.size += 1
            new_v = None
            b = v.bias
            if b == 0:
                break
            if b == 2:
                u = v.lch
                if u.bias == -1:
                    new_v = self.rotateLR(v)
                else:
                    new_v = self.rotate_right(v)
                break
            if b == -2:
                u = v.rch
                if u.bias == 1:
                    new_v = self.rotateRL(v)
                else:
                    new_v = self.rotate_left(v)
                break
        if new_v is not None:
            if len(history) == 0:
                self.root = new_v
                return
            p, pdir = history.pop()
            p.size += 1
            if pdir == 1:
                p.lch = new_v
            else:
                p.rch = new_v
        while history:
            p, pdir = history.pop()
            p.size += 1

    def delete(self, key):
        """
        指定したkeyの要素を削除する。
        指定したキーが存在するならTrue、しないならFalse。
        """
        v = self.root
        history = []
        while v is not None:
            if key < v.key:
                history.append((v, 1))
                v = v.lch
            elif v.key < key:
                history.append((v, -1))
                v = v.rch
            else:
                break
        else:
            return False
        if v.lch is not None:
            history.append((v, 1))
            lmax = v.lch
            while lmax.rch is not None:
                history.append((lmax, -1))
                lmax = lmax.rch
            v.key = lmax.key
            v.val = lmax.val
            v = lmax
        c = v.rch if v.lch is None else v.lch
        if history:
            p, pdir = history[-1]
            if pdir == 1:
                p.lch = c
            else:
                p.rch = c
        else:
            self.root = c
            return True
        while history:
            new_p = None
            p, pdir = history.pop()
            p.bias -= pdir
            p.size -= 1
            b = p.bias
            if b == 2:
                if p.lch.bias == -1:
                    new_p = self.rotateLR(p)
                else:
                    new_p = self.rotate_right(p)
            elif b == -2:
                if p.rch.bias == 1:
                    new_p = self.rotateRL(p)
                else:
                    new_p = self.rotate_left(p)
            elif b != 0:
                break
            if new_p is not None:
                if len(history) == 0:
                    self.root = new_p
                    return True
                gp, gpdir = history[-1]
                if gpdir == 1:
                    gp.lch = new_p
                else:
                    gp.rch = new_p
                if new_p.bias != 0:
                    break
        while history:
            p, pdir = history.pop()
            p.size -= 1
        return True

    def member(self, key):
        """
        指定したkeyがあるかどうか判定する。
        指定したキーが存在するならTrue、しないならFalse。
        """
        v = self.root
        while v is not None:
            if key < v.key:
                v = v.lch
            elif v.key < key:
                v = v.rch
            else:
                return True
        return False

    def getval(self, key):
        """
        指定したkeyの値を返す。
        指定したキーが存在するならそのオブジェクト。存在しなければvaldefault
        """
        v = self.root
        while v is not None:
            if key < v.key:
                v = v.lch
            elif v.key < key:
                v = v.rch
            else:
                return v.val
        self.insert(key)
        return self[key]

    def lower_bound(self, key):
        """
        [key,inf)で最小条件を満たすようなキー。
        そのようなキーが一つも存在しないならNone。
        """
        ret = None
        v = self.root
        while v is not None:
            if v.key >= key:
                if ret is None or ret > v.key:
                    ret = v.key
                v = v.lch
            else:
                v = v.rch
        return ret

    def upper_bound(self, key):
        """
        [-inf,key)で最大の条件を満たすようなキー
        そのようなキーが一つも存在しないならNone。
        """
        ret = None
        v = self.root
        while v is not None:
            if v.key < key:
                if ret is None or ret < v.key:
                    ret = v.key
                v = v.rch
            else:
                v = v.lch
        return ret

    def find_kth_element(self, k):  # 小さい方からk番目のキーの値。
        v = self.root
        s = 0
        while v is not None:
            t = s+v.lch.size if v.lch is not None else s
            if t == k:
                return v.key
            elif t < k:
                s = t+1
                v = v.rch
            else:
                v = v.lch
        return None

    def getmin(self):  # 存在するキーの最小値
        if len(self) == 0:
            raise('empty')
        ret = None
        v = self.root
        while True:
            ret = v
            v = v.lch
            if v == None:
                break
        return ret.key

    def getmax(self):  # 存在するキーの最大値
        if len(self) == 0:
            raise('empty')
        ret = None
        v = self.root
        while True:
            ret = v
            v = v.rch
            if v == None:
                break
        return ret.key

    def popmin(self):  # 最小のkeyをpop
        if len(self) == 0:
            raise('empty')
        ret = None
        v = self.root
        while True:
            ret = v
            v = v.lch
            if v == None:
                break
        del self[ret.key]
        return ret.key

    def popmax(self):  # 最大のkeyをpop
        if len(self) == 0:
            raise('empty')
        ret = None
        v = self.root
        while True:
            ret = v
            v = v.rch
            if v == None:
                break
        del self[ret.key]
        return ret.key

    def popkth(self, k):  # k(0-)番目popして出力
        key = self.find_kth_element(k)
        del self[key]
        return key

    def get_key_val(self):  # {key: value}の辞書
        retdict = dict()
        for i in range(len(self)):
            key = self.find_kth_element(i)
            val = self[key]
            retdict[key] = val
        return retdict

    def values(self):  # dict.values()
        for i in range(len(self)):
            yield self[self.find_kth_element(i)]

    def keys(self):  # dict.keys()
        for i in range(len(self)):
            yield self.find_kth_element(i)

    def items(self):  # dict.items()
        for i in range(len(self)):
            key = self.find_kth_element(i)
            yield key, self[key]

    def __iter__(self): return self.keys()
    def __contains__(self, key): return self.member(key)
    def __getitem__(self, key): return self.getval(key)
    def __setitem__(self, key, val): return self.insert(key, val)
    def __delitem__(self, key): return self.delete(key)
    def __bool__(self): return self.root is not None
    def __len__(self): return self.root.size if self.root is not None else 0
    def __str__(self): return str(type(self))+'('+str(self.get_key_val())+')'


def main():
    mod = 10**9 + 7
    inf = math.inf

    l, q = map(int, input().split())

    AVL = AVLTree()
    AVL.insert(0)
    AVL.insert(l)
    for _ in range(q):
        c, x = map(int, input().split())
        if c == 1:
            AVL.insert(x)
        else:
            print(AVL.lower_bound(x) - AVL.upper_bound(x))


if __name__ == '__main__':
    main()
