# b) Write a python program to store roll numbers of student array who attended training
# program in sorted order. Write function for searching whether particular student
# attended training program or not, using Binary search and Fibonacci search


class Search:
    def bin_search(self, arr, n, x):
        low = 1
        high = n
        r = 0
        mid = 0
        while low < high:
            mid = int(((low+high)/2)//1)
            if x < arr[mid]:
                high = mid - 1
            elif x > arr[mid]:
                low = mid + 1
            else:
                r = 1
                break
                #return mid
        if r == 1:
            print(mid)
        else:
            print("The student did not attend the program")



    def length(self, arr):
        count = 0
        for _ in arr:
            count += 1
        return count

    def sort_arr(self, arr):
        n = self.length(arr)
        for i in range(n - 1, -1, -1):
            big = arr[0]
            for j in range(0, i):
                if big < arr[j]:
                    big = arr[j]
            arr.remove(big)
            arr.append(big)
        arr.reverse()
        return arr

    # function to find the smallest fibonacci number greater than or equal to the length of the array

    def fib_search(self, arr, x, n):
        # fibonacci numbers
        a = 0  # (m-2)
        b = 1  # (m-1)
        c = a + b  # m

        # c is going to store the smallest
        # Fibonacci Number greater than or equal to n
        while c < n:
            a = b
            b = c
            c = a + b

            # Marks the eliminated range from front
        last = -1

        # while there are elements in the array
        # compare arr[a] with x.
        # When c = 1, a = 0, cause fib nos - 0,1,1,2...

        while c > 1:

            # 'a' validity check
            i = min(last + a, n - 1)

            # x > arr[i]
            # consider array from last to i
            if arr[i] < x:
                c = b
                b = a
                a = c - b
                last = i

            # if x < arr[i]
            # consider array from first element to i
            elif arr[i] > x:
                c = a
                b = b - a
                a = c - b

            # if x == arr[i]
            # return i
            else:
                return i

        # last element
        if b and arr[last + 1] == x:
            return last + 1

        # element not found. return -1
        return -1


# students_roll = [2, 3, 56, 77]
# obj1 = Search()
# print(obj1.bin_search(students_roll, 4, 77))
# obj2 = Search()
# print(obj2.fib_search(students_roll, 56, obj2.length(students_roll)))

# get array from user
n = int(input("Enter the number of students who attended the training program:"))
student_rolls = []
for _ in range(n):
    student_rolls.append(int(input("Roll no of student "+str(_)+":")))

# object creation
ob1 = Search()


# menu
choice = 0
while choice != 3:
    print("Choose an option:\n 1.Binary Search\n 2.Fibonacci Search\n 3.Exit")
    choice = int(input())
    if choice == 1:
        element = int(input("Enter the element whose index is to be found:"))
        print("The element was found at:", str(ob1.bin_search(student_rolls, ob1.length(student_rolls), element)))

    elif choice == 2:
        element = int(input("Enter the element whose index is to be found:"))
        print("The element was found at:", str(ob1.fib_search(student_rolls, element, ob1.length(student_rolls))))

    elif choice == 3:
        print("Bye Bye")

    else:
        print("Enter a valid option")










