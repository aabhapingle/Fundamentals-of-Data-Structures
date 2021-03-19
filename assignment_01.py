'''
Pseudo code
class Sports
    Algorithm __init__(self, group_a, group_b, group_c):
        self.group_a = group_a
        self.group_b = group_b
        self.group_c = group_c

    Algorithm find_intersection(self, array_1, array_2):
        intersection := []
        for i in array_1:
            for j in array_2:
                if i == j then intersection.append(i)
        return intersection

    Algorithm either_cric_or_bad(self, cricket, badminton):
        cric_and_bad := self.find_intersection(cricket, badminton)
        cricket2 := []
        for _ in cricket:
            cricket2.append(_)

        for j in cric_and_bad:
            for i in cricket:
                if i == j then cricket2.remove(i)

        badminton2 := []
        for _ in badminton:
            badminton2.append(_)

        for j in cric_and_bad:
            for i in badminton:
                if i == j then badminton2.remove(i)

        return cricket2 + badminton2

    Algorithm cric_nor_bad(self, cricket, badminton, football):
        foot_and_bad := self.find_intersection(football, badminton)
        for i in foot_and_bad:
            for j in football:
                if i == j then football.remove(j)


        foot_and_cric = self.find_intersection(cricket, football)
        for i in foot_and_cric:
            for j in football:
                if i == j then football.remove(j)
        return football

    Algorithm cric_and_foot_not_bad(self, cricket, football, badminton):
        cric_and_foot := self.find_intersection(cricket, football)
        common = self.find_intersection(badminton, cric_and_foot)  # common elements in cric_and_foot and badminton
        for i in common:
            for j in cric_and_foot:
                if i == j then cric_and_foot.remove(j)

        return cric_and_foot

   Algorithm get(name_of_sport):
    c = int(input("Enter the number of students playing " + name_of_sport + ":"))
    student_list := []
    for _ in range(c):
        name = input("Student " + str(_) + ":")
        student_list.append(name)
    return student_list

    n = 0
    Algorithm while n != 5:
    print("Choose an option:")
    print("1. List of students who play both cricket and badminton")
    print("2. List of students who play either cricket or badminton but not both")
    print("3. Number of students who play neither cricket nor badminton")
    print("4. Number of students who play cricket and football but not badminton")

    n = int(input("Enter a number:"))

    if n == 1:
        print(obj1.find_intersection(obj1.group_a, obj1.group_b))

    if n == 2:
        print(obj1.either_cric_or_bad(obj1.group_a, obj1.group_b))

    if n == 3:
        print(obj1.cric_nor_bad(obj1.group_a, obj1.group_b, obj1.group_c))

    if n == 4:
        print(obj1.cric_and_foot_not_bad(obj1.group_a, obj1.group_c, obj1.group_b))


'''



# group A students play cricket
# group B students play badminton
# group C students play football

# Write a Python program using functions to compute following: -
# a) List of students who play both cricket and badminton
# b) List of students who play either cricket or badminton but not both
# c) Number of students who play neither cricket nor badminton
# d) Number of students who play cricket and football but not badminton


class Sports:
    def __init__(self, group_a, group_b, group_c):
        self.group_a = group_a
        self.group_b = group_b
        self.group_c = group_c
       # self.group_d = group_d

    # for question 1
    def find_intersection(self, array_1, array_2):
        intersection = []
        for i in array_1:
            for j in array_2:
                if i == j:
                    intersection.append(i)
        return intersection

    # question 2
    def either_cric_or_bad(self, cricket, badminton):
        cric_and_bad = self.find_intersection(cricket, badminton)
        cricket2 = []
        for _ in cricket:
            cricket2.append(_)

        for j in cric_and_bad:
            for i in cricket:
                if i == j:
                    cricket2.remove(i)

        badminton2 = []
        for _ in badminton:
            badminton2.append(_)

        for j in cric_and_bad:
            for i in badminton:
                if i == j:
                    badminton2.remove(i)

        return cricket2 + badminton2

    # question 3
    def cric_nor_bad(self, cricket, badminton, football):
        foot_and_bad = self.find_intersection(football, badminton)
        for i in foot_and_bad:
            for j in football:
                if i == j:
                    football.remove(j)

        foot_and_cric = self.find_intersection(cricket, football)
        for i in foot_and_cric:
            for j in football:
                if i == j:
                    football.remove(j)

        return football

    # question 4
    def cric_and_foot_not_bad(self, cricket, football, badminton):
        cric_and_foot = self.find_intersection(cricket, football)
        common = self.find_intersection(badminton, cric_and_foot)  # common elements in cric_and_foot and badminton
        for i in common:
            for j in cric_and_foot:
                if i == j:
                    cric_and_foot.remove(j)
        return cric_and_foot


# function for taking input
def get(name_of_sport):
    c = int(input("Enter the number of students playing " + name_of_sport + ":"))
    student_list = []
    for _ in range(c):
        name = input("Student " + str(_) + ":")
        student_list.append(name)
    return student_list


obj1 = Sports(get("cricket"), get("badminton"), get("football"))

# choose an option

n = 0
while n != 5:
    print("Choose an option:")
    print("1. List of students who play both cricket and badminton")
    print("2. List of students who play either cricket or badminton but not both")
    print("3. Number of students who play neither cricket nor badminton")
    print("4. Number of students who play cricket and football but not badminton")

    n = int(input("Enter a number:"))

    if n == 1:
        print(obj1.find_intersection(obj1.group_a, obj1.group_b))

    if n == 2:
        print(obj1.either_cric_or_bad(obj1.group_a, obj1.group_b))

    if n == 3:
        print(obj1.cric_nor_bad(obj1.group_a, obj1.group_b, obj1.group_c))

    if n == 4:
        print(obj1.cric_and_foot_not_bad(obj1.group_a, obj1.group_c, obj1.group_b))
