# a) Write a python program to store roll numbers of student in array who attended
# training program in random order.
# Write function for searching whether particular
# student attended training program or not, using Linear search and Sentinel search.


class Search:
    def __init__(self, roll_no):
        self.roll_no = roll_no

    def length(self, arr):
        count = 0
        for _ in arr:
            count += 1
        return count

    def linear_search(self, arr, x):
        index = -1
        for _ in range(self.length(arr)):
            if x == arr[_]:
                index = _
        if index == -1:
            return "This student did not attend the training program."
        else:
            return "This element is present at index: " + str(index)

    def sentinel_search(self, arr, n, x):
        last = arr[n-1]
        arr[n-1] = x
        i = 0
        while arr[i] != x:
            i += 1
        arr[n-1] = last

        if (i < (n-1)) or (x == arr[n-1]):
            print("The roll number", x, "is present at index:", i)
        else:
            print("The roll number was not found!")


# arr1 = [45, 66, 23, 24]
# obj1 = Search(23)
# obj1.linear_search(arr1, obj1.roll_no)
# print(obj1.linear_search(arr1, obj1.roll_no))
#
# arr2 = [2, 4, 5, 6]
# obj2 = Search(6)
# obj2.sentinel_search(arr2, obj2.length(arr2), obj2.roll_no)

arr1 = []
a = int(input("Enter the number of students that attended the program: "))
for _ in range(a):
    x = int(input('Enter Roll No: '))
    arr1.append(x)

roll = int(input("Enter roll number of the Student to be searched:"))

n = 0
while n != 3:
    print("Choose an option:")
    print(" 1.Linear Search")
    print(" 2.Sentinel Search")
    n = int(input())
    if n == 1:
        obj1 = Search(roll)
        print(obj1.linear_search(arr1, obj1.roll_no))

    elif n == 2:
        obj2 = Search(roll)
        obj2.sentinel_search(arr1, obj2.length(arr1), obj2.roll_no)

    elif n == 3:
        print("Bye bye")

    else:
        print("Enter a valid option")







