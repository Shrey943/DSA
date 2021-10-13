import matplotlib.pyplot as plt


def intersection(lst1, lst2):
    lst3 = [value for value in lst1 if value in lst2]
    return lst3


def layoutConst(a, w, h, fs, odr, ori):

    LC, RC, lr, ul, R = [], [], [], [], []

    n = len(fs)
    print("N : ", n)

    # LC[0] = fs
    LC.insert(0, fs)

    for i in range(0, n):

        # lr[i] = (w, 0)
        # ul[i] = (0, h)
        lr.append((w, 0))
        ul.append((0, h))

    print("LR : ", lr)
    print("ul : ", ul)
    j = 0  # SUS

    while j != n-1:
        k = n-1
        while k >= 0:
            try:
                if (fs[odr[j]] in LC[k]):
                    print(f"*********hua******** k ={k}")
                    # print(LC)
                    R = LC[k]
                    print("R = ", R)

                    break

                elif (fs[odr[j]] in RC[k]):
                    print("*******hua**********")
                    R = RC[k]
                    print("R = ", R)
                    break
                k = k-1
            except IndexError:
                # print("\nERror AAi")
                k = k-1

        temp = odr[j]

        print("\ntemp :", temp)
        if (j == 0):
            LC[j] = intersection(fs[0: temp], R)
        else:
            LC.insert(j, intersection(fs[0: temp], R))
        # LC[j].extend(R)
        print(f"LC[{j}] : ", LC[j])

        RC.insert(j, intersection(fs[temp:], R))
        # RC[j].extend(R)
        print(f"RC[{j}] : ", RC[j])

        sumA = 0
        for i in LC[j]:
            sumA = sumA + a[i-1]  # SUS
        print("Sum LC : ", sumA)
        sumRC = 0
        for i in RC[j]:
            sumRC = sumRC + a[i-1]  # SUS
        print("Sum RC : ", sumRC)

        if ori[j] == 0:  # Vertical

            for i in LC[j]:

                # lr.insert(i,  ((ul[i])[0] + (sumA/(ul[i])[1]), (lr[i])[1]))
                lr[i-1] = ((ul[i-1])[0] + (sumA/(ul[i-1])[1]), (lr[i-1])[1])

            for i in RC[j]:

                # ul.insert(i, ((ul[i])[0] + (sumA/(ul[i])[1]), (ul[i])[1]))

                ul[i-1] = ((ul[i-1])[0] + (sumA/(ul[i-1])[1]), (ul[i-1])[1])

        elif ori[j] == 1:  # Horizontal

            for i in LC[j]:
                if(i-1 == 1):
                    print("\n In 2")
                    print("LR : ", lr)
                    print("UL : ", ul)

                # lr.insert(i, ((lr[i])[0],  (ul[i])[1] - (sumA/(lr[i])[0])))
                lr[i-1] = ((lr[i-1])[0],  (ul[i-1])[1] - (sumRC/(lr[i-1])[0]))

            for i in RC[j]:

                # ul.insert(i, ((ul[i])[0], (ul[i])[1] - (sumA/(lr[i])[0])))
                ul[i-1] = ((ul[i-1])[0], (ul[i-1])[1] - (sumRC/(lr[i-1])[0]))

        j = j + 1

    print("\n\n")
    print("lr : ", lr)
    print("ul : ", ul)

    for i in range(0, n):
        print(f"lr[{i+1}] : ", lr[i])
        print(f"ul[{i+1}] : ", ul[i])
        print("\n")

    xs = [x[0] for x in lr]
    ys = [x[1] for x in ul]

    plt.scatter(xs, ys)
    plt.show()
    return


layoutConst([750, 600, 800, 450, 450, 500, 450], 80, 50,
            [1, 5, 6, 3, 2, 7, 4], [4, 1, 5, 3, 6, 2], [0, 1, 1, 0, 1, 1])
