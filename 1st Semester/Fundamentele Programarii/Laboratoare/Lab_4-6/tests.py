from domain import (makeNumber, addToEndOfList, addToGivenPos, listFromPositions, getImaginaryPart, extractImaginaryParts, numbersWModulusEqual,
                    numbersWModulusLess, removeGivenCondition, removePrimeNumbers, lessThan, biggerThan, equalTo, removeAtPosition,
                    removeBetweenPositions, replaceComplexNumber, sortDescending, calculateSum, calculateProduct, isPrime, undo,
                    addToUndoList, copyListOfDicts)



def test_makeNumber():
    testRealPart = 5.2
    testImaginaryPart = 7
    assert(makeNumber(testRealPart, testImaginaryPart) == {'Re': testRealPart, 'Im': testImaginaryPart})

def test_addToEndOfList():
    testNumber1 = makeNumber(5.2, 7)
    testNumber2 = makeNumber(5.5, 8)
    testNumber3 = makeNumber(2, 0)
    testNumberToAdd = makeNumber(6,6 )

    testList = [testNumber1, testNumber2, testNumber3]
    lengthBeforeAdd = len(testList)

    addToEndOfList(testList, testNumberToAdd)
    assert(len(testList) == lengthBeforeAdd + 1)
    assert(testList[len(testList)-1] == testNumberToAdd)

def test_addToGivenPos():
    testNumber1 = makeNumber(4, 2)
    testNumber2 = makeNumber(5.5, 8)
    testNumber3 = makeNumber(2, 0)
    testNumberToAdd = makeNumber(6,6)

    testList = [testNumber1, testNumber2, testNumber3]
    testPosition = 1
    lengthBeforeAdd = len(testList)

    addToGivenPos(testList, testNumberToAdd, testPosition)
    assert(len(testList) == lengthBeforeAdd + 1)
    assert(testList[testPosition] == testNumberToAdd)

def test_imaginaryParts():
    testNum1 = makeNumber(0, 2.1)
    testNum2 = makeNumber(5.5, 8)
    testNum3 = makeNumber(2, 0)
    testNum4 = makeNumber(4, 2.3)
    testNum5 = makeNumber(2.9, 210.5)
    testNum6 = makeNumber(1, 0.5)
    testNum7 = makeNumber(1, 1.37)
    testList = [testNum1, testNum2, testNum3, testNum4, testNum5, testNum6, testNum7]
    testPos1 = 2
    testPos2 = 6

    splitList = listFromPositions(testList, testPos1, testPos2)
    imaginaryPartsList = extractImaginaryParts(splitList)
    assert(imaginaryPartsList == [getImaginaryPart(testList[i]) for i in range(testPos1, testPos2 + 1)])

def test_modulusLess():
    testNum1 = makeNumber(4, 2)
    testNum2 = makeNumber(5.5, 8)
    testNum3 = makeNumber(2, 0)
    testNum4 = makeNumber(10, 1)
    testNum5 = makeNumber(10, 12)
    testNum6 = makeNumber(1, 1)
    testNum7 = makeNumber(12, 7)
    testList = [testNum1, testNum2, testNum3, testNum4, testNum5, testNum6, testNum7]

    numsWModulusLess = numbersWModulusLess(testList, 10)
    assert(numsWModulusLess == [testNum1, testNum2, testNum3, testNum6])

def test_modulusEqual():
    testNum1 = makeNumber(8, 6)
    testNum2 = makeNumber(5.5, 8)
    testNum3 = makeNumber(2, 0)
    testNum4 = makeNumber(-6, -8)
    testNum5 = makeNumber(6, -8)
    testNum6 = makeNumber(-6, 8)
    testNum7 = makeNumber(2, 0)
    testNum8 = makeNumber(0, 10)
    testList = [testNum1, testNum2, testNum3, testNum4, testNum5, testNum6, testNum7, testNum8]

    numsWModulusEqual = numbersWModulusEqual(testList, 10)
    assert(numsWModulusEqual == [testNum1, testNum4, testNum5, testNum6, testNum8])

def test_removePrimeNumbers():
    testNum1 = makeNumber(5, 5)
    testNum2 = makeNumber(2, 44)
    testNum3 = makeNumber(9, 11)
    testNum4 = makeNumber(4, 0)
    testNum5 = makeNumber(-4, 5)
    testNum6 = makeNumber(-13, 13)
    testNum7 = makeNumber(29, 3)
    testNum8 = makeNumber(0, 12)
    testList = [testNum1, testNum2, testNum3, testNum4, testNum5, testNum6, testNum7, testNum8]
    assert(removePrimeNumbers(testList) == [testNum3, testNum4, testNum5, testNum6, testNum8])

def test_removeGivenCondition():
    testNum1 = makeNumber(4, 9.3)
    testNum2 = makeNumber(0.6, 5)
    testNum3 = makeNumber(1.2, 44)
    testNum4 = makeNumber(0, -6)
    testNum5 = makeNumber(2.5, 1)
    testNum6 = makeNumber(-4.4, 12)
    testNum7 = makeNumber(-13, -9)
    testNum8 = makeNumber(2.35, -2.2)
    testNum9 = makeNumber(6, 0)
    testList = [testNum1, testNum2, testNum3, testNum4, testNum5, testNum6, testNum7, testNum8, testNum9]
    testValue = 6
    expectedResult1 = [testNum1, testNum3, testNum4, testNum6, testNum7, testNum9]
    expectedResult2 = [testNum1, testNum2, testNum3, testNum5, testNum6, testNum7, testNum8]
    expectedResult3 = [testNum2, testNum4, testNum5, testNum8, testNum9]
    assert(removeGivenCondition(testList, lessThan, testValue) == expectedResult1)
    assert(removeGivenCondition(testList, equalTo, testValue) == expectedResult2)
    assert(removeGivenCondition(testList, biggerThan, testValue) == expectedResult3)

def test_listFromPositions():
    testNum1 = makeNumber(6, 0)
    testNum2 = makeNumber(-3.5, 7)
    testNum3 = makeNumber(0.5, 3)
    testNum4 = makeNumber(1.6, -2)
    testNum5 = makeNumber(2.2, -1)
    testNum6 = makeNumber(-6.6, 0)
    testList = [testNum1, testNum2, testNum3, testNum4, testNum5, testNum6]
    testPos1 = 1
    testPos2 = 4
    assert(listFromPositions(testList, testPos1, testPos2) == [testNum2, testNum3, testNum4, testNum5])

def test_isPrime():
    assert(isPrime(7) == True)
    assert(isPrime(1) == False)
    assert(isPrime(2.1) == False)
    assert(isPrime(2) == True)

def test_lessThan():
    testValue = 10
    assert(lessThan(4, testValue) == True)
    assert(lessThan(11, testValue) == False)
    assert(lessThan(10, testValue) == False)

def test_biggerThan():
    testValue = 5
    assert(biggerThan(4, testValue) == False)
    assert(biggerThan(11, testValue) == True)
    assert(biggerThan(5, testValue) == False)

def test_equalTo():
    testValue = 30.2
    assert(equalTo(4, testValue) == False)
    assert(equalTo(11, testValue) == False)
    assert(equalTo(30.2, testValue) == False)

def test_removeAtPosition():
    testNum1 = makeNumber(1, 0)
    testNum2 = makeNumber(-2, 4)
    testNum3 = makeNumber(0.25, 3)
    testNum4 = makeNumber(-1.6, -2)
    testNum5 = makeNumber(2.2, 99)
    testNum6 = makeNumber(-63, -0.13)
    testList = [testNum1, testNum2, testNum3, testNum4, testNum5, testNum6]
    testPosition = 3
    removeAtPosition(testList, testPosition)
    assert(testList == [testNum1, testNum2, testNum3, testNum5, testNum6] )

def test_removeBetweenPositions():
    testNum1 = makeNumber(24, -0.23)
    testNum2 = makeNumber(-19, 4)
    testNum3 = makeNumber(0.35, 44)
    testNum4 = makeNumber(-1.6, -2)
    testNum5 = makeNumber(2.2, -2.9)
    testNum6 = makeNumber(-1.3, -0.13)
    testList = [testNum1, testNum2, testNum3, testNum4, testNum5, testNum6]
    testPosition1 = 1
    testPosition2 = 4
    removeBetweenPositions(testList, testPosition1, testPosition2)
    assert(testList == [testNum1, testNum6])

def test_replaceComplexNumber():
    testNum1 = makeNumber(0.4, -5)
    testNum2 = makeNumber(-19, 4)
    testNum3 = makeNumber(0.4, -5)
    testNum4 = makeNumber(-2, -2)
    testNum5 = makeNumber(0.4, -5)
    testNum6 = makeNumber(-1.3, -0.13)
    testList = [testNum1, testNum2, testNum3, testNum4, testNum5, testNum6]
    complexNumToReplace = makeNumber(0.4, -5)
    newComplexNum = makeNumber(0, 0)
    replaceComplexNumber(testList, complexNumToReplace, newComplexNum)
    assert(testList == [newComplexNum, testNum2, newComplexNum, testNum4, newComplexNum, testNum6])

def test_calculateSum():
    testNum1 = makeNumber(991, -199)
    testNum2 = makeNumber(3, 444)
    testNum3 = makeNumber(-64, -899)
    testNum4 = makeNumber(115, 5212)
    testList = [testNum1, testNum2, testNum3, testNum4]

    expectedResult = makeNumber(1045, 4558)

    assert(calculateSum(testList) == expectedResult)

def test_calculateProduct():
    testNum1 = makeNumber(1, 3)
    testNum2 = makeNumber(3, 4)
    testNum3 = makeNumber(-5, -2)
    testNum4 = makeNumber(11, -1)
    testList = [testNum1, testNum2, testNum3, testNum4]

    expectedResult = makeNumber(734, -588)

    assert (calculateProduct(testList) == expectedResult)

def test_sortDescending():
    testNum1 = makeNumber(2, -5)
    testNum2 = makeNumber(-1, 4)
    testNum3 = makeNumber(33.33, -7)
    testNum4 = makeNumber(-22.22, 2)
    testNum5 = makeNumber(0.5, -1)
    testNum6 = makeNumber(-1.3, -0.13)
    testList = [testNum1, testNum2, testNum3, testNum4, testNum5, testNum6]

    expectedResult = [testNum2, testNum4, testNum6, testNum5, testNum1, testNum3]

    assert(sortDescending(testList) == expectedResult)

def test_undo():
    undoList = []

    testNum1 = makeNumber(2, -5)
    testNum2 = makeNumber(-1, 4)
    testNum3 = makeNumber(33.33, -7)
    testNum4 = makeNumber(-22.22, 2)
    testNum5 = makeNumber(0.5, -1)
    testNum6 = makeNumber(-1.3, -0.13)

    newNum = makeNumber(-1, -1)

    testList = [testNum1, testNum2, testNum3, testNum4, testNum5, testNum6]

    listaCopiata = copyListOfDicts(testList)
    addToUndoList(undoList, listaCopiata)

    addToEndOfList(testList, newNum)

    listaCopiata = copyListOfDicts(testList)
    addToUndoList(undoList, listaCopiata)

    removeAtPosition(testList, 1)

    assert testList == [testNum1, testNum3, testNum4, testNum5, testNum6, newNum]

    undo(undoList, testList)

    assert testList == [testNum1, testNum2, testNum3, testNum4, testNum5, testNum6, newNum]

    undo(undoList, testList)

    assert testList == [testNum1, testNum2, testNum3, testNum4, testNum5, testNum6]

def runTests():
    test_makeNumber()
    test_addToEndOfList()
    test_addToGivenPos()
    test_imaginaryParts()
    test_modulusLess()
    test_modulusEqual()
    test_removePrimeNumbers()
    test_removeGivenCondition()

    test_isPrime()
    test_lessThan()
    test_biggerThan()
    test_isPrime()
    test_listFromPositions()

    test_removeAtPosition()
    test_removeBetweenPositions()
    test_replaceComplexNumber()

    test_calculateSum()
    test_calculateProduct()
    test_sortDescending()
    test_undo()
