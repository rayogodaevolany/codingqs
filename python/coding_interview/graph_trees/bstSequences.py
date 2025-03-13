from linkedlist import Node, LinkedList

class Node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None

def bst(node):
    res = []
    if not node:
        tmp = LinkedList()
        res = tmp + res
        return res

    # create prefix
    prefix = LinkedList()
    prefix.insert(node.val)

    leftAll = bst(node.left)
    rightAll = bst(node.right)
    for left in leftAll:
        for right in rightAll:
            weaved = []
            weaved.extend(weaveLists(left, right, weaved, prefix))
            res.extend(weaved)
    return res

def weaveLists(first, second, results, prefix):
    if first.first == None or second.first == None:
        clone = prefix.clone()
        clone.extend(first)
        clone.extend(second)
        res = clone + results;
        return res

    headFirst = first.removeFirst()
    prefix.insert(headFirst)
    weaveLists(first, second, results, prefix)
    prefix.removeLast(headFirst)
    first.addFirst(headFirst)

    headSecond = second.removeFirst()
    prefix.insert(headSecond)
    weaveLists(first, second, results, prefix)
    prefix.removeLast(headSecond)
    second.addFirst(headSecond)

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
print(bst(head))



