def interclasare(sir1, sir2):
    i = 0
    j = 0
    sir3 = list()

    while i < len(sir1) and j < len(sir2):
        if sir1[i] <= sir2[j]:
            sir3.append(sir1[i])
            i += 1
        else:
            sir3.append(sir2[j])
            j += 1

    while i < len(sir1):
        sir3.append(sir1[i])
        i += 1

    while j < len(sir2):
        sir3.append(sir2[j])
        j += 1

    return sir3

def mergesort(sir):
    if len(sir) == 1:
        return sir

    lowerhalf = sir[:len(sir) // 2]
    upperhalf = sir[len(sir) // 2:]

    arr1 = mergesort(lowerhalf)
    arr2 = mergesort(upperhalf)

    return interclasare(arr1, arr2)

print(mergesort([5, 3, 2, 10, 5, 8, 9, 2, 1]))