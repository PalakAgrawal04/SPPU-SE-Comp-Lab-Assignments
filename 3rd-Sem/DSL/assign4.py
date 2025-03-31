n = int(input("enter number of total elements: "))
numbers = []
for i in range (n):
    element = int(input("enter elements: "))
    numbers.append(element)
print(numbers)

key = int(input("enter the element to be searched: "))

def linearsearch(list1):
    for i in range (len(list1)):
        if (numbers[i] == key):
            return i
    return -1


def sentinel_search(arr, target):
    n = len(arr)
    
    last_element = arr[n - 1]
    arr[n - 1] = target
    
    i = 0
    while arr[i] != target:
        i += 1
    
    arr[n - 1] = last_element
    
    if i < n - 1 or arr[n - 1] == target:
        return i  
    else:
        return -1 


def binary_search(numbers, key):
    low = 0
    high = len(numbers) - 1
    mid = 0

    while low <= high:
        mid = (high + low) // 2 

        if numbers[mid] < key:
            low = mid + 1


        elif numbers[mid] > key:
            high = mid - 1

        else:
            return mid

    return -1


def fibonaccianSearch(numbers, key, n):


    a = 0
    b = 1
    c = a + b

    while (c < n): 
        a = b
        b = c
        c = a + b

    offset = -1

    while (c > 1):

        i = min(offset + a, n - 1)

        if (numbers[i] < key):
            c = b
            b = a
            a = c - b
            offset = i

        elif (numbers[i] > key):
            c = a
            b = b - a
            a = c - b

        else:
            return i

    if (b and numbers[n - 1] == key):
        return n - 1

    return -1

print(
        """
            enter 1 for linear search
            enter 2 for sentinal search
            enter 3 for binary search
            enter 4 for fibonacci search
            enter 0 for stop getting output
""")
while (True):
    
    
    choice = int(input("enter your choice: "))

    if (choice == 1):
        result = linearsearch(numbers)
        if result != -1:
            print(f"Element {key} found at index {result}")
        else:
            print(f"Element {key} not found.")
    
    elif (choice == 2):
        result = sentinel_search(numbers, key)
        if result != -1:
            print(f"Element {key} found at index {result}")
        else:
            print(f"Element {key} not found.")

    elif (choice == 3):
        result = binary_search(sorted(numbers), key)

        if result != -1:
            print("Element is present at index", str(result))
            break
        else:
            print("Element is not present in list")

    elif (choice == 4):
        ind = fibonaccianSearch(sorted(numbers), key, n)
        if ind >= 0:
            print("Found at index:", ind)
            break
        else:
            print(key, "isn't present in the list")

    
    elif (choice == 0):
        break

    else:
        print("enter valid choice")