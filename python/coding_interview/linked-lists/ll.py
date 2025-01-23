# Node and Linked list class for doing linked list problems

class Node:
    def __init__(self, data=0, nxt=None):
        self.data = data
        self.next = nxt

class LinkedList:
    def __init__(self, array):
        self.head = Node(array[0])
        tmp = self.head
        for data in array[1:]:
            tmp.next = Node(data)
            tmp = tmp.next

    def getStart(self):
        return self.head

    def makeLoop(self, offset):
        tmp = self.head
        for _ in range(offset):
            tmp = tmp.next
        pointer = tmp
        while pointer.next:
            pointer = pointer.next
        pointer.next = tmp

    def printList(self):
        array = []
        tmp = self.head
        while tmp:
            array.append(tmp.data)
            tmp = tmp.next
        print(array)
        return array
