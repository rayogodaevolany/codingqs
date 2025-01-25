class Node:
    def __init__(self, data=0, nxt=None):
        self.data = data
        self.next = nxt

def printList(self):
    array = []
    tmp = self.head
    while tmp:
        array.append(tmp.data)
        tmp = tmp.next
    print(array)
    return array


class Animal(Node):
    def __init__(self, name, typ, timestamp):
        Node.__init__(self)
        self.timestamp = timestamp
        self.typ = typ
        self.name = name

class AnimalShelter:
    def __init__(self):
        self.dogList = None
        self.dogOldest = None

        self.catList = None
        self.catOldest = None

        self.logicalTime = 0

    def enq(self, typ, name):
        if typ == 'dog':
            if self.dogList == None:
                self.dogList = Animal(name, typ, self.logicalTime)
                self.dogOldest = self.dogList
            else:
                new = Animal(name, typ, self.logicalTime)
                self.dogList.next = new
                self.dogList = new

            self.logicalTime += 1

        if typ == 'cat':
            if self.catList == None:
                self.catList = Animal(name, typ, self.logicalTime)
                self.catOldest = self.catList
            else:
                new = Animal(name, typ, self.logicalTime)
                self.catList.next = new
                self.catList = new
            self.logicalTime += 1

    def deqAll(self):
        if self.dogOldest.timestamp < self.catOldest.timestamp:
            res = self.dogOldest
            self.dogOldest = self.dogOldest.next
            return res
        else:
            res = self.catOldest
            self.catOldest = self.catOldest.next

    def deqCat(self):
        return catOldest

    def deqDog(self):
        return dogOldest


    # Test:
myShelter = AnimalShelter()

animals = {'dog': 'mark', 'cat': 'tony'}

for typ, name in animals.items():
    myShelter.enq(typ, name)

print(myShelter.deqAll().name)
print(myShelter.deqAll().name)


