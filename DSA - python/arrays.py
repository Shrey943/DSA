import array

# i is code for signed int, means i cant hold negative values now
arr = array.array('i', [12, 33, 42354, 436, 5476, 546])

print(arr) #prints every detail i.e above line

for i in arr: print (i,end = " ")
    

arr.append(999)
arr.insert(0, 1)  # index, value

print("\n")
for i in range (len(arr)):
    print(arr[i],end = " ")

arr.extend([35, 798, 78587]) #can also append another array using it

print("\n")
for i in range(len(arr)):
    print(arr[i], end=" ")

arr.pop(3)  # takes position of element to be removed
arr.pop()  # if nothing given, removes last element

print("\n")
for i in arr:
    print(i,end = " ")

arr.remove(436) #remove the first occrance

print("\n")
for i in arr:
    print(i,end = " ")
    
arr.reverse()
print("\n")
for i in arr:
    print(i,end = " ")

print("\n")
print("index of 33 is ", arr.index(33))

#*************************** Farely important functions*********************

print("DataType code : ",arr.typecode)#variables
print("Each item size : ",arr.itemsize)
print("Arrays address and no. of elements: ",arr.buffer_info())

print("No. of occarence of given element : ",arr.count(33))

# arr.tolist()
print("\n", arr.tolist()) # converts arr to list(it do not change original array, just returns a list with all elements)

