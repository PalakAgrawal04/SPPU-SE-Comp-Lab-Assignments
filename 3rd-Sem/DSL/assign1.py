student = []
n = int(input("Total no. of students: "))
for i in range(1, n + 1):
    student.append(i)

print(student)

def remove_dulpicate(set1):
    lst = []
    for i in set1:
        if i not in lst:
            lst.append(i)
    return lst

cricket = []
badminton = []
football = []

c = int(input("No. of students who play cricket: "))
for i in range(0, c):
        c1 = int(input("Enter roll no."))
        if 0<c1<=n:
            cricket.append(c1)
        else:
            print("Invalid input")
cricket = remove_dulpicate(cricket)
print("List of students playing cricket:",cricket)

b = int(input("No. of students who play badminton: "))
for i in range(0, b):
        b1 = int(input("Enter roll no."))
        if 0<b1<=n:
            badminton.append(b1)
        else:
            print("Invalid input")
badminton = remove_dulpicate(badminton)
print("List of students playing badminton:",badminton)

f = int(input("No. of students who play football: "))
for i in range(0, f):
        f1 = int(input("Enter roll no. "))
        if 0<f1<=n:
            football.append(f1)
        else:
            print("Invalid input")
football = remove_dulpicate(football)
print("List of students playing football:",football)

class sets:
    def union(self,set1, set2):
        result = []
        result = set1.copy()
        for value in set2:
            if value not in set1:
                result.append(value)
        return result

    def intersection(self,set1, set2):
        result = []
        for value in set1:
            if value in set2:
                result.append(value)
        return result

    def difference(self,set1, set2):
        result = []
        for value in set1:
            if value not in set2:
                result.append(value)
        return result

    def symm_difference(self,set1, set2):
        result = []
        A = self.union(set1, set2)
        B = self.intersection(set1, set2)
        result = self.difference(A, B)
        return result

s = sets()
print("Enter choice:")
print("a.List of students who play both cricket and badminton\n"
    "b.List of students who play either cricket or badminton not both\n"
    "c.No. of students who play neither cricket nor badminton\n"
    "d.No. of students who play cricket and football but not badminton")
def operation():
    choice = int(input("Do you want to perform the operation?(1/0):"))
    while choice == 1:
        op = input("Enter operation: ")
        if op == 'a':
            print("Students who play both cricket and badminton both: ",s.intersection(cricket, badminton))
        elif op == 'b':
            print("Students who play either cricket or badminton but not both: ",s.symm_difference(cricket, badminton))
        elif op == 'c':
            print("Students who play neither cricket nor badminton: ",s.difference(s.difference(student,badminton),cricket))
        elif op == 'd':
            print("Students who play cricket and football but not badminton: ",s.difference(s.intersection(cricket, football), badminton))
        else:
            print("INVALID INPUT")
        choice = int(input("Do you want to repeat the operation?(1/0):"))
        if choice == 0:
            break

operation()