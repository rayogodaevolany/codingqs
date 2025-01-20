import ll

def addNodes(head, d1, carry, d2=0):
    ssum = d1+d2+carry
    tba = ssum % 10
    carry = ssum //10
    head.data = tba
    head.next = ll.Node(0)
    head = head.next
    return (carry, head)

def sum(n1, n2):
    if not n1 and not n2:
        return None
    elif not n1:
        return n2
    elif not n2:
        return n1
    head = ll.Node()
    carry = 0
    result = head
    while n1 and n2:
        carry, head = addNodes(head, n1.data, carry, n2.data)
        n1 = n1.next
        n2 = n2.next
    if n1:
        while carry != 0:
            if n1:
                carry, head = addNodes(head, n1.data, carry)
                n1 = n1.next
            else:
                carry, head = addNodes(head, 0, carry)
        if n1:
            head.next = n1
    if n2:
        while carry != 0:
            if n2:
                carry, head = addNodes(head, n2.data, carry)
                n2 = n2.next
            else:
                carry, head = addNodes(head, 0, carry)
        if n2:
            head.next = n2
    return result


n1 = ll.createLinkedList([9,9,9])
n2 = ll.createLinkedList([9,9])

ll.printPretty(sum(n1, n2))
