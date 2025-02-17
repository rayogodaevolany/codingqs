class Node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

def rec(node):
    if not node:
        return []
    if not node.right and not node.left:
        return [[node.val]]
    res = []
    nodeArr = [node.val]
    leftAll = rec(node.left)
    for x in leftAll:
        res.append(nodeArr + x)
    rightAll = rec(node.right)
    for x in rightAll:
        res.append(nodeArr + x)
    return res


def insert(node, value):
    if not node:
        return Node(value)
    if node.val == value:
        return node
    # bst with same vals are to the left
    if node.val >= value:
        node.left = insert(node.left, value)
    else:
        node.right = insert(node.right, value)
    return node

def createBST(array):
    head = Node(array[len(array)//2])
    print(head.val)
    for x in array:
        insert(head, x)

def inorder(head):
    if head:
        inorder(head.left)
        print(head.val, end=" ")
        inorder(head.right)
    
array = [4,3,2,5,1,6,7,7,8]
head = createBST(array)
inorder(head)
print(rec(head))

