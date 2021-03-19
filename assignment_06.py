# Write a python program to store first year percentage of students in array. Write function
# for sorting array of floating point numbers in ascending order using quick sort and display
# top five scores


class Sort:
    def __init__(self, marks):
        self.marks = marks

    def partition(self, arr, low, high):
        # index of smaller element
        i = (low - 1)

        # pivot is the last element of the unsorted list
        pivot = arr[high]

        for j in range(low, high):

            # If current element is smaller than the pivot
            if arr[j] < pivot:
                # increment index of smaller element
                i = i + 1
                arr[i], arr[j] = arr[j], arr[i]

        arr[i + 1], arr[high] = arr[high], arr[i + 1]
        return i + 1

    def quick_sort(self, arr, low, high):
        if low < high:

            pi = self.partition(arr, low, high)

            # Separately sort elements before
            # partition and after partition
            self.quick_sort(arr, low, pi - 1)
            self.quick_sort(arr, pi + 1, high)
        return arr

    def display_top(self, arr):
        print("****** Top 5 scores: ******")
        i = 1
        for _ in range(-1, -6, -1):
            print(str(i) + '. ' + str(arr[_]))
            i += 1
        return '***************************'


# arr = [10, 7, 8.89, 9, 1, 5, 45]
# n = len(arr)
# quickSort(arr, 0, n-1)
# print("Sorted array is:")
# print(arr)

# object creation
mark_list = []
obj1 = Sort(mark_list)
choice = 0

while choice != 4:
    # menu
    print('********** MENU **********')
    print('1. Add marks of students')
    print('2. Apply QuickSort')
    print('3. Display marks of top 5 students')
    print('4. Exit')

    choice = int(input('Enter choice:'))

    if choice == 1:
        no = int(input('What is the total number of students in the class?'))

        for _ in range(no):
            print('Student '+str(_) + '(%) : ', end='')
            percentage = float(input())
            mark_list.append(percentage)
        print(mark_list)

    if choice == 2:
        print('-----Sorted using QuickSort-----')
        print(obj1.quick_sort(mark_list, 0, len(mark_list)-1))

    if choice == 3:
        print('-----Top five Students-----')
        print(obj1.display_top(mark_list))

print('Bye Bye')









