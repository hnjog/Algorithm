import sys
input = sys.stdin.readline

class Node:
    def __init__(self,data : any,left = None,right = None) -> None:
        self.data = data
        self.left = left
        self.right = right

class Tree:
    def __init__(self,root : Node = None) -> None:
        self.root = root
    
    def insert(self,thisNode:Node,node:Node,targetData, bleft:bool = False):
        if self.root == None:
            self.root = node
            return

        if thisNode.data == targetData:
            if bleft:
                thisNode.left = node
            else:
                thisNode.right = node

        if thisNode.left:
            self.insert(thisNode.left,node,targetData,bleft)
        
        if thisNode.right:
            self.insert(thisNode.right,node,targetData,bleft)

    def getRootNode(self)->Node:
        return self.root

    #전위
    def poPrint(self,node : Node):
        print(node.data, end='')
        if node.left:
            self.poPrint(node.left)
        if node.right:
            self.poPrint(node.right)

    #중위
    def midPrint(self,node : Node):
        if node.left:
            self.midPrint(node.left)
        print(node.data, end='')
        if node.right:
            self.midPrint(node.right)

    #후위
    def postPrint(self,node : Node):
        if node.left:
            self.postPrint(node.left)
        if node.right:
            self.postPrint(node.right)
        print(node.data, end='')
            



if __name__ == "__main__":
    num = int(input().strip())
    tr = Tree(Node('A'))

    for i in range(num):
        findNodeData,left,right = input().split()

        if left != '.':
            lNode = Node(left)
            tr.insert(tr.root, lNode,findNodeData,True)
        if right != '.':
            rNode = Node(right)
            tr.insert(tr.root,rNode,findNodeData)

    tr.poPrint(tr.root)
    print()
    tr.midPrint(tr.root)
    print()
    tr.postPrint(tr.root)
    