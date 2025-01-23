import ll

def checkLoop(head):
    slow, fast = head, head
    while slow.next and fast.next:
        slow = slow.next
        fast = fast.next.next
        if slow == fast:
            return (True, slow, fast)
    return (False, slow, fast)

def returnStart(head, slow, fast):
    slow = head
    while slow != fast:
        slow = slow.next
        fast = fast.next

    return slow

def isLoopReturnStart(head):
    if not head:
        return False
    flag, slow, fast = checkLoop(head)
    if flag:
        return returnStart(head, slow, fast).data
    return False

def visualizeLoop(head):
    counter = 0
    print ("here is the loop:")
    while counter <= 20 and head:
        print(head.data)
        head = head.next
        counter += 1

    print("\n")

def checkAnswer():
    array = [1,2,3,4,5,6,7,8,9]
    myList = ll.LinkedList(array)
    myList.makeLoop(2)
    visualizeLoop(myList.getStart())

    print(isLoopReturnStart(myList.getStart()))

checkAnswer()
