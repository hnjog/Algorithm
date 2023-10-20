import sys

sys.setrecursionlimit(20000)

class Node:
    def __init__(self,data,left = None,right = None) -> None:
        self.data = data
        self.left = left
        self.right = right

class bst:
    def __init__(self, node:Node = None) -> None:
        self.root = node

    def insert(self,data)->None:
        if self.root is None:
            self.root = Node(data)
            return

        p = self.root
        while p is not None:
            if p.data > data:
                if p.left is None:
                    p.left = Node(data)
                    break
                
                p = p.left
            else:
                if p.right is None:
                    p.right = Node(data)
                    break
                p = p.right

    def postPrint(self,inNode:Node):
        if inNode is None:
            return
        
        self.postPrint(inNode.left)
        self.postPrint(inNode.right)
        print(inNode.data)


if __name__ == "__main__":
    tr = bst()

    n = 0
    while n <= 10000:
        try:
            data = int(sys.stdin.readline().strip())
            tr.insert(data)
        except:
            break
        n+= 1

    tr.postPrint(tr.root)
