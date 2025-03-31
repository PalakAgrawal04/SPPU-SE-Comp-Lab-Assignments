from array import *

def partition(a,low,high):
    pivot = a[low]
    start = low
    end = high
    while start < end :
        while a[start] <= pivot:
            start += 1
        while a[end] > pivot:
            end -= 1
        if(start < end):
            a[start],a[end] = a[end],a[start]
    a[low],a[end] = a[end],a[low]
    return end

def quickSort(a,low,high):
    if low<high :
        part = partition(a,low,high)
        quickSort(a,low,part-1)
        quickSort(a,part+1,high)

A = array('i',[])
print("Enter 5 numbers ")
for i in range(5):
    x = int(input("Enter : "))
    A.append(x)
print("Before : ",A)
quickSort(A,0,len(A)-1)

print("After : ",A)