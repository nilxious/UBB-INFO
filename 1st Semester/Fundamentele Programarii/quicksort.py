def quickSort(sir):
    if len(sir) <= 1:
        return sir

    pivot = sir.pop()

    lesser = quickSort([x for x in sir if x < pivot])
    greater = quickSort([x for x in sir if x >= pivot])

    return lesser + [pivot] + greater

print(quickSort([5, 1, 3, 4, 10, 1, -5, 3, 200]))