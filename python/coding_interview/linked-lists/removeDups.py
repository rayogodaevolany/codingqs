def deleteDup(head):
    duplicates = set()
    duplicates.add(head.data)
    node = head
    while node.next:
        if node.next.data in duplicates:
            node.next = node.next.next
        else:
            duplicates.add(node.next.data)
            node = node.next
    return head

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


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
    return array


array = [5,5,4,1,4,5,3,6]
# array = [1,1]
print(printPretty(createLinkedList(array)))

print(printPretty(deleteDup(createLinkedList(array))))


