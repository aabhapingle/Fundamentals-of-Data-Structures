# Write a python program to compute following computation on matrix:
# a) Addition of two matrices
# b) Subtraction of two matrices
# c) Multiplication of two matrices
# d) Transpose of a matrix


class MatrixOperations:
    def __init__(self, matrix, m, n):
        self.matrix = matrix  # this is the matrix created according to the order of the matrix
        self.m = m  # m is the number of rows
        self.n = n  # n is the number of columns

    # for creating a matrix of dimensions m*n
    def create_matrix(self):
        self.matrix = []
        for i in range(self.m):
            self.matrix.append([])
        for i in self.matrix:
            for j in range(self.n):
                i.append(0)
        return self.matrix

    # create matrix for transpose
    def create_for_transpose(self):
        self.matrix = []
        for i in range(self.n):
            self.matrix.append([])
        for i in self.matrix:
            for j in range(self.m):
                i.append(0)
        return self.matrix

    # for creating matrix for multiplication
    # create matrix of order m*l
    def create_for_multiplication(self, m, l):
        self.matrix = []
        for i in range(m):
            self.matrix.append([])
        for i in self.matrix:
            for j in range(l):
                i.append(0)
        return self.matrix

    # for adding two matrices
    def addition(self, matrix_1, matrix_2):
        for i in range(0, self.m):
            for j in range(0, self.n):
                self.matrix[i][j] = matrix_1[i][j] + matrix_2[i][j]
        return self.matrix

    # for subtraction of two matrices
    def subtraction(self, matrix_1, matrix_2):
        for i in range(0, self.m):
            for j in range(0, self.n):
                self.matrix[i][j] = matrix_1[i][j] - matrix_2[i][j]
        return self.matrix

    # for transpose of a matrix
    def transpose(self, matrix_1):
        for i in range(0, self.m):
            for j in range(0, self.n):
                self.matrix[j][i] = matrix_1[i][j]
        return self.matrix

    def multiplication(self, matrix_1, matrix_2, m, n, l):
        for i in range(m):
            for j in range(l):
                add = 0
                for k in range(n):
                    add = add + matrix_1[i][k]*matrix_2[k][j]
                self.matrix[i][j] = add
        return self.matrix


def display_matrix(matrix):
    for i in matrix:
        for j in i:
            print(j, end=" ")
        print("")


def get_matrix(m):
    matrix = []
    for i in range(m):
        arr = list(map(int, input().split()))
        matrix.append(arr)
    return matrix


matrix_demo = []
n = 0
while n != 5:
    print("Choose an option:")
    print("1.Addition")
    print("2.Subtraction")
    print("3.Transpose")
    print("4.Multiplication")
    print("5.Exit")
    n = int(input())

    # addition
    if n == 1:
        # m and n should be same for both the matrices
        m = int(input("Enter the number of rows:"))
        n = int(input("Enter the number of columns:"))
        print("--- Matrix 1 ---")
        matrix_one = get_matrix(m)
        print("--- Matrix 2 ---")
        matrix_two = get_matrix(m)

        obj_add = MatrixOperations(matrix_demo, m, n)
        obj_add.create_matrix()  # for addition
        add_matrix = obj_add.addition(matrix_one, matrix_two)
        print("The addition of given matrices is: ")
        display_matrix(add_matrix)

    if n == 2:
        # m and n should be same for both the matrices
        m = int(input("Enter the number of rows:"))
        n = int(input("Enter the number of columns:"))
        print("--- Matrix 1 ---")
        matrix_one = get_matrix(m)
        print("--- Matrix 2 ---")
        matrix_two = get_matrix(m)

        obj_sub = MatrixOperations(matrix_demo, m, n)
        obj_sub.create_matrix()  # for subtraction
        sub_matrix = obj_sub.subtraction(matrix_one, matrix_two)
        print("The subtraction of given matrices is: ")
        display_matrix(sub_matrix)

    if n == 3:
        m = int(input("Enter the number of rows:"))
        n = int(input("Enter the number of columns:"))
        print("--- Matrix ---")
        matrix = get_matrix(m)
        print(matrix)
        obj_trans = MatrixOperations(matrix_demo, m, n)
        obj_trans.create_for_transpose()
        transpose_mat = obj_trans.transpose(matrix)
        print("Transpose of the matrix is:")
        display_matrix(transpose_mat)

    if n == 4:
        # m*n and n*p
        m = int(input("Enter number of rows:"))
        n = int(input("Enter number of columns:"))
        print('--- Matrix 1 ---')
        matrix_one = get_matrix(m)

        p = int(input("Enter number of columns:"))
        print('--- Matrix 2 ---')
        matrix_two = get_matrix(n)

        obj_mul = MatrixOperations(matrix_demo, m, p)
        obj_mul.create_for_multiplication(m, p)
        multiplication = obj_mul.multiplication(matrix_one, matrix_two, m, n, p)
        print('The multiplication of given matrices is:')
        display_matrix(multiplication)

    if n == 5:
        print("Bye Bye")










