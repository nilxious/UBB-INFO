def longestSublist(a):
    """
    Determines the longest increasing sub-list
    a - a list of elements
    return sublist of x, the longest increasing sublist
    """
    # Initialise l and p
    lg = len(a)
    l = [0] * lg
    p = [0] * lg

    l[lg - 1] = 1
    p[lg - 1] = -1

    for k in range(lg - 2, -1, -1):
        p[k] = -1
        l[k] = 1
        for i in range(k + 1, lg):
            if a[i] >= a[k] and l[k] < l[i] + 1:
                l[k] = l[i] + 1
                p[k] = i

    # Identify the longest sublist
    # Find the maximum length
    j = 0
    for i in range(0, lg):
        if l[i] > l[j]:
            j = i

    # Collect the results using the position list
    rez = []
    while j != -1:
        rez = rez + [a[j]]
        j = p[j]

    return rez


print(longestSublist([4, 1, -1, 3, 4, 5, -7, 4, 10]))