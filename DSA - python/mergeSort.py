def mergeSort(array, low, high):

    if (low < high):

        mid = int((low+high)/2)
        # print(mid)
        array = mergeSort(array, low, mid)
        array = mergeSort(array, mid+1, high)

        return merge(array, low, mid, high)
    else:
        return array


def merge(array, low, mid, high):

    i = low
    j = mid 
    result = []
    print(array)

    while(i < mid+1 and j < high+1):
        print(i,j)

        if (array[i] < array[j]):
            result.append(array[i])
            i += 1
        else:
            result.append(array[j])
            j += 1

    if (i < mid+1):
        result.extend(array[i:mid+1])
    elif(j < high+1):
        result.extend(array[mid+1:high+1])

    return result


if __name__ == '__main__':

    array = list(map(int, input("Enter array: ").split()))
    # print(array)
    print("\nSorted Array is: ", mergeSort(array, 0, len(array)-1))
