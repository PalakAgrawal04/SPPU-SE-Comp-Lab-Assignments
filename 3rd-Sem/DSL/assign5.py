
def insertionsort(arr):
    x = len(arr)
    if x <= 1:
        return  -1
    for i in range (1,x):
        key = arr[i]
        j = i - 1      
        while j >= 0 and key < arr[j]:
            arr[j+1],arr[j]= arr[j],arr[j+1]
            j = j - 1

def selectionsort(array ,n):

        for i in range(n):
            min_index = i

            for j in range(i + 1, n):
                if array[j] < array[min_index]:
                    min_index = j
            (array[i], array[min_index]) = (array[min_index], array[i])

def bubblesort(array):
    for i in range(len(array)):
        for j in range(0, len(array) - i - 1):
            if array[j] > array[j + 1]:
                temp = array[j]
                array[j] = array[j + 1]
                array[j + 1] = temp


def shellsort(array, size):
    gap = size // 2
    while gap > 0:
        for i in range(gap, size):
            temp = array[i]
            j = i
            while (j >= gap and array[j - gap] > temp):
                array[j] = array[j - gap]
                j -= gap
            array[j] = temp
        gap //= 2



n = int(input("enter total number of students: "))
sorted_list = [ ]
for i in range (n):
    element = float(input("enter percentage: "))
    sorted_list.append(element)


print('''
            Enter 1 for insertion sort
            Enter 2 for selection sort
            Enter 3 for bubble sort
            Enter 4 for shell sort
            Enter 0 for stop getting output
            ''')


while(True):
        choice = int(input("Enter your choice: "))

        if (choice == 0):
            break

        if (choice == 1):
            insertionsort(sorted_list)
            print("The array after sorting by insertion sort is: ", sorted_list)

        elif (choice == 2):
            selectionsort(sorted_list, n)
            print('The array after sorting by selection sort is: ', sorted_list)

        elif (choice == 3):
            bubblesort(sorted_list)
            print('The array after sorting by bubble sort is:    ', sorted_list)

        elif (choice == 4):
            shellsort(sorted_list, n)
            print("The array after sorting by shell sort is:     ", sorted_list)

        else:
            print("please enter valid choice !!")