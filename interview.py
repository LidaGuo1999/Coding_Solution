

class ListNode:
    def __init__(self, int val):
        self.val = val;
        self.next_one = NULl;

class Lianbiao:
    
    def __init__(self, ListNode l):
        self.head = l;

    def insert(self, ListNode l):

    def remove(self, ListNode l):

    def search(self, ListNode l):

    def reverse(self):
        ListNode tmp = self.head
        save = []
        while (tmp != NULL):
            save.append(tmp)
            tmp = tmp.next_one
        reverse(save)
        for i in range(len(save)):
            tmp = save[i+1]
            if (i == 0):
                self.head = save[i]
            else:
                save[i].next_one = tmp

def binary_search(l, start, end, target):
    if (end-start <= 1):
        if (l[end] != target)
            return -1
        else return end

    else:
        middle = start+(end-start)/2
        if (target == l[middle]):
            return middle
        elif (target < l[middle]):
            return binary_search(l, start, middle, target)
        else:
            return binary_search(l, middle+1, end, target)


def knapback(n, w, Max):
    matrix = []
    for i in range(n):
        matrix.append(list())
        for j in range(Max+1):
            matrix[i].append(0)

    for j in range(Max):
        if (w[j] <= j) matrix[0][j] = 1

    for i in range(1, n):
        for j in range(Max+1):
            if (j >= w[j]):
                matrix[i][j] = max(matrix[i-1][j], matrix[i-1][j-w[j]]+1)
    return matrix[-1][-1]








