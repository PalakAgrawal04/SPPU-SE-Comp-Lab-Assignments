str1 = input("Enter the string:")
class STR:
    def word_lng(self):
        sen_list = str1.split()
        max = 0
        word=""
        for i in sen_list:
            if len(i) > max:
                max = len(i)
                word = i
        return word
    
    def freq_count(self):
        a = input("Character whose frequency is to be found: ")
        count = 0
        for i in str1:
            if i == a:
                count +=1
        return count
    
    def substring(self):
        substr = input("Enter a substring: ")
        for i in range(len(str1) - len(substr) + 1):
            if str1[i : i + len(substr)] == substr:
                return i
        return -1
    
    def word_count(self):
        words = str1.split()
        count = {}
        for i in words:
            if i not in count:
                count[i] = 1
            else:
                count[i] +=1
        return count
    
    def palindrome(self):
            if str1 == str1[::-1]:
                return True
            return False

obj = STR()
print("Enter operation:")
print("a. To display word with the longest length \n b. To determine the frequency of occurrence of particular character in the string\n"
    "c. To check whether the given string is palindrome or not.\n"
    "d. To display the index of first appearance of the string.\n"
    "e. To count the occurrence of each word in a given string.\n")
    
def operation():
    choice = int(input("Do you want to perform the operation?(1/0):"))
    while choice == 1:
        op = input("Enter operation: ")
        if op == 'a':
            num = obj.word_lng()
            print("The longest word in the string is: ", num) 
        elif op == 'c':
            num4 = obj.palindrome()
            if num4 == True:
                print("The given string is palindrome.")
            else:
                print("The given string is not a palindrome.") 
        elif op == 'd':
            num2 = obj.substring()
            print("To check whether the substring is present or not: ", num2) 
        elif op == 'b':
            num1 = obj.freq_count()
            print("The frequency of the given character is: ", num1) 
        elif op == 'e':
            num3 = obj.word_count()
            print("The no. of each word in the given string is: ", num3) 
        else:
            print("INVALID INPUT")
        choice = int(input("Do you want to repeat the operation?(1/0):")) 
        if choice == 0:
            break

operation()