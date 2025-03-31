A = []
r1 = int(input("Enter no. of rows:"))
c1 = int(input("Enter no. of columns:"))
for i in range(0, r1):
    row = []
    for j in range(0, c1):
        element = int(input("Enter the elements in the matrix:"))
        row.append(element)
    A.append(row)
print(A)

B = []
r2 = int(input("Enter no. of rows:"))
c2 = int(input("Enter no. of columns:"))
for i in range(0, r2):
    row = []
    for j in range(0, c2):
        element = int(input("Enter the elements in the matrix:"))
        row.append(element)
    B.append(row)
print(B)

class Matrix:

    def addition(self, A, B):
        if (r1 == r2) or (c1 == c2):
            M3 = []
            for i in range(0, r1):
                row = []
                for j in range(0, c1):
                    sum = A[i][j] + B[i][j]
                    row.append(sum)
                M3.append(row)
            return M3
        else:
            print("INVALID")

    def subtraction(self, A, B):
        if (r1 == r2) or (c1 == c2):
            M3 = []
            for i in range(0, r1):
                row = []
                for j in range(0, c1):
                    sum = A[i][j] - B[i][j]
                    row.append(sum)
                M3.append(row)
            return M3
        else:
            print("INVALID")

    def multiply(self, A, B):
        if (c1 == r2):
            M3 = []
            for i in range(0, r1):
                row = []
                for j in range(0, c2):
                    sum = 0
                    for k in range(0, r2):
                        sum = sum + A[i][k] * B[k][j]
                    row.append(sum)
                M3.append(row)
            return M3
        else:
            print("INVALID")

    def Transpose(self, A):
        M3 = []
        for i in range(0, r1):
                row = []
                for j in range(0, c1):
                    sum = A[j][i]
                    row.append(sum)
                M3.append(row)
        return M3

obj = Matrix()
print("a.Addition\nb.Subtraction\nc.Multiplication\nd.Transpose")
def operation():
    choice = int(input("Do you want to perform the operation?(1/0):"))
    while choice == 1:
        op = input("Enter operation: ")
        if op == 'a':
            num = obj.addition(A, B)
            print("Addition :", num)
        elif op == 'b':
            num1 = obj.subtraction(A, B)
            print("Subtraction:", num1)
        elif op == 'c':
            num2 = obj.multiply(A, B)
            print("Multiplication: ", num2)
        elif op == 'd':
            num3 = obj.Transpose(A)
            print("Transpose:", num3)
        else:
            print("INVALID INPUT")
        choice = int(input("Do you want to repeat the operation?(1/0):"))
        if choice == 0:
            break
operation()