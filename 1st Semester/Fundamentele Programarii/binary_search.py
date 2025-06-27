def binaryS(el, l, left, right):
    if right - left <= 1:
        return right
    m = (left + right) // 2
    if el <= l[m]:
        return binaryS(el, l, left, m)
    else:
        return binaryS(el, l, m, right)

def searchBinaryRec(el, l):
    if len(l) == 0:
        return 0
    if el < l[0]:
        return 0
    if el > l[len(l) - 1]:
        return len(l)
    return binaryS(el, l, 0, len(l))


def searchBinaryNonRec(el, l):
    if len(l) == 0:
        return 0
    if el <= l[0]:
        return 0
    if el >= l[len(l) - 1]:
        return len(l)

    right = len(l)-1
    left = 0
    while not (right - left <= 1):
        m = (left + right) // 2
        if el <= l[m]:
            right = m
        else:
            left = m

    return right

