import stack

class Queue:
    def __init__(self):
        self.end = stack.Stack() 
        self.front = stack.Stack()
    
    def shift(self):
        if self.front.isEmpty():
            while not self.end.isEmpty():
                self.front.push(self.end.pop())

    def add(self, value):
        self.end.push(value)

    def remove(self):
        self.shift()
        if self.front.isEmpty():
            raise valueError("stack is empty")
        self.front.pop()

    def peek(self):
        self.shift()
        return self.front.peek()





# array = [1,2,3,4,5]
# print(array, "\n")

# myQueue = Queue()
# for i in range(len(array)):
#     myQueue.add(array[i])

# for i in range(len(array)):
#     print(myQueue.peek().data)
#     myQueue.remove()

# for i in range(5):
#     myQueue.add(array[-i])
    
# for i in range(5):
#     print(myQueue.peek().data)
#     myQueue.remove()

