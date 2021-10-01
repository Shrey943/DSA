
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