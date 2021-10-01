class Node:
    def __init__(self, data):
        self.data = data
        self.nextNode = None


class Linkedlist:
    def __init__(self):
        self.head = None

    def append(self, data):
        # Node(data) returns the address of object of Node i.e. <__main__.Node object at 0x0000020B2D189408>
        newNode = Node(data)

        if (self.head == None):
            self.head = newNode
        else:
            temp = self.head
            while temp.nextNode != None:
                temp = temp.nextNode
            temp.nextNode = newNode

    def insert(self, index, data):

        newNode = Node(data)

        if index == 0:

            newNode.nextNode = self.head
            self.head = newNode
        else:
            temp = self.head

            for i in range(0, index-1):            # as we want node of index-1
                try:  # Hn hn while ka bhi use kr skte the toh try na lagana padta pr accha h
                    temp = temp.nextNode
                except AttributeError:
                    print("Index Out OF Range.")
                    break
            try:
                newNode.nextNode = temp.nextNode
                temp.nextNode = newNode
            except AttributeError:
                print("Index Out OF Range.")

    def display(self):
        temp = self.head

        print("\nLinked List: ", end=" ")
        while temp != None:
            # print("Element : ", temp.data)
            print(temp.data, end=" ")
            temp = temp.nextNode

    def pop(self, index=None):

        try:
            temp1 = self.head
            temp2 = self.head.nextNode
            if index is None:
                while temp2.nextNode != None:
                    temp1 = temp2
                    temp2 = temp2.nextNode
                temp1.nextNode = None
                temp2 = None

            elif index == 0:
                self.head = temp2
                temp1 = None

            else:
                for i in range(0, index-1):
                    temp1 = temp2
                    temp2 = temp2.nextNode
                temp1.nextNode = temp2.nextNode
                temp2 = None        # Well.....Not necessary
        except AttributeError:
            print("Index Out OF Range.")

    def remove(self, value):

        try:
            temp1 = self.head
            temp2 = self.head.nextNode

            if (temp1.data == value):
                self.pop(0)  # Code reusability bhaiya
            else:
                while (temp2.data != value):
                    temp1 = temp2
                    temp2 = temp2.nextNode
                temp1.nextNode = temp2.nextNode
                temp2 = None            # Well.....Not necessary

        except AttributeError:
            print("\nValue not found.")

    def __str__(self):
        temp = self.head
        l = []

        print("\nLinked List: ", end=" ")
        while temp != None:
            # print("Element : ", temp.data)
            print(temp.data, end=" ")
            l.append(temp.data)
            temp = temp.nextNode
        return ", ".join(l)


if __name__ == "__main__":

    ll = Linkedlist()
    ll.append(1)
    ll.append(2)
    ll.append(3)
    ll.append(4)
    ll.append(5)

    ll.display()

    ll.insert(0, 0)
    ll.insert(4, 555)
    ll.insert(7, 777)
    ll.insert(8, 888)
    # ll.insert(10, 9999)
    # ll.insert(15, 9999)

    ll.display()

    print("\nPoping last element(without any index): ")
    ll.pop()
    ll.display()

    print("\nPoping first element: ")
    ll.pop(0)
    ll.display()

    print("\nPoping element at index 3: ")
    ll.pop(3)
    ll.display()

    print("\nPoping last element(with index): ")
    ll.pop(5)
    ll.display()

    print("\nwrong index: ")
    ll.pop(45)
    ll.display()

    ll.append(1234)
    ll.append(342534)
    ll.append(3245)
    ll.append(1234)
    ll.insert(0, 101)

    ll.display()

    print("\nDeleting first element using value : ")
    ll.remove(101)
    ll.display()

    ll.remove(1234)
    ll.display()

    ll.remove(1234)
    ll.display()
    
    # del ll

    print(ll)    # Yahi karne toh __str__ seekha tha
