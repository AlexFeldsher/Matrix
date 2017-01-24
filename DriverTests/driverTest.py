from subprocess import Popen, PIPE, STDOUT, TimeoutExpired
from random import randint, uniform
import sys

MAX_DIM = 10
MIN_INT = -10
MAX_INT = 10
ENCODING = 'ASCII'
DRIVER_EXE = 'test.out'
SCHOOL_EXE = 'GenericMatrixDriver'


def main():
    run = True
    while(run):
        inp = generateInput()
        p_school = Popen(SCHOOL_EXE, stdout=PIPE, stdin=PIPE, stderr=STDOUT)
        school_output = p_school.communicate(input=bytes(inp, ENCODING))[0]
        school_output = school_output.decode(ENCODING)
        p_my = Popen(DRIVER_EXE, stdout=PIPE, stdin=PIPE, stderr=STDOUT)
        my_output = p_my.communicate(input=bytes(inp, ENCODING))[0]
        my_output = my_output.decode(ENCODING)
        if (my_output == school_output):
            print('.', end='')
            sys.stdout.flush()
        else:
            run = False
            print("============= INPUT=============")
            print(inp)
            print("================================")
            print("============= SCHOOL=============")
            print(school_output)
            print("================================")
            print("============= MY =============")
            print(my_output)
            print("================================")


def generateInput():
    field = randint(1,3)
    operation = randint(1,3)
    if operation == 1:
        matricesSize = getMatricesSize(operation)
        inp = additionInput(field, matricesSize)
    if operation == 2:
        matricesSize = getMatricesSize(operation)
        inp = multInput(field, matricesSize)
    if operation == 3:
        matrixSize = getMatricesSize(operation)
        inp = transInput(field, matrixSize)
    return inp

def additionInput(field, matricesSize):
    if field == 1:
        matrix1 = generateIntMatrix(matricesSize[0])
        matrix2 = generateIntMatrix(matricesSize[1])
    elif field == 2:
        matrix1 = generateDoubleMatrix(matricesSize[0])
        matrix2 = generateDoubleMatrix(matricesSize[1])
    elif field == 3:
        matrix1 = generateComplexMatrix(matricesSize[0])
        matrix2 = generateComplexMatrix(matricesSize[1])
    inp = str(field) + '\n1\n'
    inp += str(matricesSize[0][0]) + '\n'
    inp += str(matricesSize[0][1]) + '\n'
    inp += matrix1
    inp += str(matricesSize[1][0]) + '\n'
    inp += str(matricesSize[1][1]) + '\n'
    inp += matrix2
    return inp

def multInput(field, matricesSize):
    if field == 1:
        matrix1 = generateIntMatrix(matricesSize[0])
        matrix2 = generateIntMatrix(matricesSize[1])
    elif field == 2:
        matrix1 = generateDoubleMatrix(matricesSize[0])
        matrix2 = generateDoubleMatrix(matricesSize[1])
    elif field == 3:
        matrix1 = generateComplexMatrix(matricesSize[0])
        matrix2 = generateComplexMatrix(matricesSize[1])
    inp = str(field) + '\n2\n'
    inp += str(matricesSize[0][0]) + '\n'
    inp += str(matricesSize[0][1]) + '\n'
    inp += matrix1
    inp += str(matricesSize[1][0]) + '\n'
    inp += str(matricesSize[1][1]) + '\n'
    inp += matrix2
    return inp

def transInput(field, matrixSize):
    if field == 1:
        matrix = generateIntMatrix(matrixSize)
    elif field == 2:
        matrix = generateDoubleMatrix(matrixSize)
    elif field == 3:
        matrix = generateComplexMatrix(matrixSize)
    inp = str(field) + '\n3\n'
    inp += str(matrixSize[0]) + '\n'
    inp += str(matrixSize[1]) + '\n'
    inp += matrix
    return inp

def generateIntMatrix(matrixSize):
    string = ""
    for i in range(matrixSize[0]):
        for j in range(matrixSize[1]):
            string += str(randint(MIN_INT, MAX_INT)) + ','
        string += '\n'
    return string

def generateDoubleMatrix(matrixSize):
    string = ""
    for i in range(matrixSize[0]):
        for j in range(matrixSize[1]):
            string += str(round(uniform(MIN_INT, MAX_INT), 4)) + ','
        string += '\n'
    return string

def generateComplexMatrix(matrixSize):
    string = ""
    for i in range(matrixSize[0]):
        for j in range(matrixSize[1]):
            if (randint(0,1) == 1):
                sign = '+'
            else:
                sign = '-'
            string += str(round(uniform(MIN_INT, MAX_INT), 2)) + sign + str(round(uniform(MIN_INT, MAX_INT), 2)) + 'i,'
        string += '\n'
    return string

def getMatricesSize(operation):
    if operation == 1:
        N = randint(1,MAX_DIM)
        M = randint(1,MAX_DIM)
        I = randint(1,MAX_DIM)
        J = randint(1,MAX_DIM)
        return ((N, M),(I,J))
    if operation == 2:
        N = randint(1,MAX_DIM)
        M = randint(1,MAX_DIM)
        I = randint(1,MAX_DIM)
        K = randint(1,MAX_DIM)
        return ((N, M), (I, K))
    if operation == 3:
        N = randint(1,MAX_DIM)
        M = randint(1,MAX_DIM)
        return (N, N)

main()