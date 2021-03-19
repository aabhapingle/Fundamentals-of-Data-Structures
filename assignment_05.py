# Write a python program to store second year percentage of students in array. Write function for
# sorting array of floating-point numbers in ascending order using a) Insertion sort b) Shell Sort
# and display top five scores


class Sort:
    def __init__(self, arr):
        self.arr = arr

    def length(self, arr):
        count = 0
        for _ in arr:
            count += 1
        return count

    def insertion_sort(self, arr):
        for k in range(1, self.length(arr)):
            curr = arr[k]
            j = k
            while j > 0 and arr[j - 1] > curr:
                arr[j] = arr[j - 1]
                j -= 1
            arr[j] = curr
        return arr

    def shell_sort(self, arr):
        h = 0  # interval calculation

        # to find the maximum interval
        # compare with the floor value

        while h < self.length(arr) // 3:
            h = h * 3 + 1

        while h > 0:
            # i is the outer variable
            for i in range(h, self.length(arr)):
                a = arr[i]  # value to insert
                j = i
                while j > (h - 1) and arr[j - h] >= a:
                    arr[j] = arr[j - h]
                    j = j - h

                arr[j] = a

            # formula reversed
            h = (h - 1) // 3
        return arr

    def display_top(self, arr):
        print("****** Top 5 scores: ******")
        i = 1
        for _ in range(-1, -6, -1):
            print(str(i) + '. ' + str(arr[_]))
            i += 1
        return '***************************'

#mrk_list = [23.90, 45.45, 10.90, 50.87, 80.34, 23.78]

# print(obj1.insertion_sort(mrk_list))
# print(obj1.shell_sort(mrk_list))
# print(obj1.display_top(mrk_list))




mark_list = []
obj1 = Sort(mark_list)
choice = 0

while choice != 5:
    # menu
    print('Choose an option:')
    print(' 1. Enter student details\n 2. Sort using insertion sort\n 3. Sort using shell sort\n 4. Display first five toppers\n 5. Exit')
    # choice = 0
    choice = int(input('Enter choice:'))

    if choice == 1:
        no = int(input('What is the total number of students in the class?'))

        for _ in range(no):
            print('Student '+str(_) + '(%) : ', end='')
            percentage = float(input())
            mark_list.append(percentage)

    if choice == 2:
        print('---Sorted using insertion sort---')
        print(obj1.insertion_sort(mark_list))

    if choice == 3:
        print('---Sorted using shell sort---')
        print(obj1.shell_sort(mark_list))

    if choice == 4:
        obj1.display_top(mark_list)

print("Bye Bye")



