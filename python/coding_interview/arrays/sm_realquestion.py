def parity(n1, n2):
    return int(n1) % 2 == int(n2) % 2

def sortArray(array):
    array.sort(reverse=True)
    return array


def biggestNum(s):
    if s == '':
        return ''
    res, tmp = [], []
    for index in range(len(s)):
        if not tmp or parity(s[index],tmp[-1]):
            tmp.append(s[index])
        else:
            partial = sortArray(tmp)
            partial = ''.join(partial)
            res.append(partial)
            tmp = [s[index]]
    return ''.join(res)


s = '13792886025'
print(biggestNum(s))


