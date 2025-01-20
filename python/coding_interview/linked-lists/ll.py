class Node:
    def __init__(self, data=0, nnext=None):
        self.data = data
        self.next = nnext


def createLinkedList(array):
    head = Node(array[0])
    node = head
    for data in array[1:]:
        node.next = Node(data)
        node = node.next
    return head

def printPretty(head):
    array = []
    array.append(head.data)
    while head.next:
        array.append(head.next.data)
        head = head.next
    print(array)
    return array


n1 = ll.createLinkedList([0,1,1,1,2,3,4])
n2 = ll.createLinkedList([0,2,3,4])
