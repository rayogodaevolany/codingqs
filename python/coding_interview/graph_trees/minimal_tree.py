class Node:
    def __init__(self):
        self.left = None
        self.right = None
        self.val = None

def rec(array):
    if not array:
        return None
    l = len(array)//2
    node = Node()
    node.left = rec(array[:l])
    node.val = array[l]
    node.right = rec(array[l+1:])
    return node

array = [1,2,3,4,5,6,7,8,9,10,11]

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


printList(rec(array))
