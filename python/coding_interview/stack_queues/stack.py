class Node:
    def __init__(self, data=0, nxt=None):
        self.data = data
        self.next = nxt

class Stack:
    def __init__(self):
        self.head = Node()

    def push(self, value):
        node = Node(value)
        node.next = self.head
        self.head = node

    def pop(self):
        if not self.head.next:
            raise valueError("stack is empty")
        tmp = self.head
        self.head = self.head.next
        return tmp

    def peek(self):
        return self.head.data

    def isEmpty(self):
        flag = True
        if self.head.next:
            flag = False
        return flag

# Making sure stack works 
#
# array = [1,2,3,4,5]
# print(array, "\n")

# myStack = Stack()
# for i in range(len(array)):
#     myStack.push(array[i])

# for i in range(len(array)):
#     print(myStack.peek())
#     print(myStack.pop().data)

# print(myStack.isEmpty())
