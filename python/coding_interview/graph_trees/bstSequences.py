class Node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

def recbst(node):
    if not node.right and not node.left:
        return [[node.val]]
    res = []
    nodeArr = [node.val]
    if node.left:
        leftAll = recbst(node.left)
        for x in leftAll:
            res.append(nodeArr + x)
    if node.right:
        rightAll = recbst(node.right)
        for x in rightAll:
            res.append(nodeArr + x)
    return res

def rec(array):
    if not array:
        return None
    l = len(array)//2
    node = Node(None)
    node.left = rec(array[:l])
    node.val = array[l]
    node.right = rec(array[l+1:])
    return node


def printList(listhead):
    queue = [listhead]
    print(listhead.val)

    while queue:
        queuelength = len(queue)
        arr = []
        for _ in range(queuelength):
            current = queue.pop(0)
            if current.left:
                queue.append(current.left)
                arr.append(current.left.val)
            else:
                arr.append('None')
            if current.right:
                queue.append(current.right)
                arr.append(current.right.val)
            else:
                arr.append('None')
        print(arr)


array = [1,2,3,4,5,6,7,8,9,10,11]
head = rec(array)
print(recbst(head))



