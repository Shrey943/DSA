class Node:
    def __init__(self, data):
        self.data = data
        self.nextNode = None


class CircularLL:
    def __init__(self):
        self.head = None

    def append(self, data):

        new = Node(data)

        if self.head is None:

            self.head = new
            new.nextNode = self.head  # next node points to its own object

        else:
            temp = self.head

            while temp.nextNode is not self.head:
                temp = temp.nextNode

            temp.nextNode = new
            new.nextNode = self.head

    def insert(self, index, data):

        new = Node(data)
        temp = self.head

        if index == 0:
            new.nextNode = self.head

            while temp.nextNode != self.head:
                temp = temp.nextNode

            self.head = new
            temp.nextNode = self.head
        else:
            try:  # Since its a circular linked list hence it would not give attribute error, infact would start index again from 0
                for i in range(index - 1):
                    temp = temp.nextNode
                    if (temp == self.head):      # To only take correct index, add this
                        print("Invalid index.")
                        return

                new.nextNode = temp.nextNode
                temp.nextNode = new
            except AttributeError:
                print("\nOut of index.")

    def pop(self, index=None):

        temp1 = self.head
        temp2 = self.head.nextNode

        if index is None:

            while temp2.nextNode is not self.head:
                temp1 = temp2
                temp2 = temp2.nextNode

            temp1.nextNode = self.head
            temp2 = None
        elif index == 0:

            while temp2.nextNode != self.head:
                temp2 = temp2.nextNode

            self.head = self.head.nextNode
            temp2.nextNode = self.head
            temp1 = None
        else:
            try:
                for i in range(index-1):
                    temp1 = temp2
                    temp2 = temp2.nextNode
                    if (temp2 == self.head):      # To only take correct index, add this
                        print("Invalid index.")
                        return

                temp1.nextNode = temp2.nextNode
                temp2 = None
            except AttributeError:
                print("\nOut of index.")

    def remove(self, val):

        temp1 = self.head
        temp2 = self.head.nextNode
        if temp1.data == val:
            self.pop(0)
        else:
            try:
                while temp2.data != val:
                    temp1 = temp2
                    temp2 = temp2.nextNode

                temp1.nextNode = temp2.nextNode
                temp2 = None
            except AttributeError:
                print("\nValue not found.")

    def display(self):

        temp = self.head

        print("\nLinked List: ", end=" ")
        while temp.nextNode != self.head:
            print(temp.data, end=", ")
            temp = temp.nextNode
        print(temp.data)


if __name__ == '__main__':
    cll = CircularLL()
    cll.append(1)
    cll.append(2)
    cll.append(3)
    cll.append(4)
    cll.append(5)

    cll.display()

    cll.insert(0, 0)
    cll.insert(4, 555)
    cll.insert(7, 777)
    cll.insert(8, 888)
    # Since its a circular linked list, hence in place of error, it starts again from index 0, But i have added condition to only take correct
    cll.insert(10, 9999)
    cll.insert(15, 9999)

    cll.display()

    print("\nPoping last element(without any index): ")
    cll.pop()
    cll.display()

    print("\nPoping first element: ")
    cll.pop(0)
    cll.display()

    print("\nPoping element at index 3: ")
    cll.pop(3)
    cll.display()

    print("\nPoping last element(with index): ")
    cll.pop(5)
    cll.display()

    print("\nwrong index: ")
    cll.pop(45)
    cll.display()

    cll.append(1234)
    cll.append(342534)
    cll.append(3245)
    cll.append(1234)
    cll.insert(0, 101)

    cll.display()

    print("\nDeleting first element using value : ")
    cll.remove(101)
    cll.display()

    cll.remove(1234)
    cll.display()

    cll.remove(1234)
    cll.display()
 
