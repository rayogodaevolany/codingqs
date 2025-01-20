def zeroMatrix(matrix):
    mLength,nLength = len(matrix),len(matrix[0])
    yset,xset = set(), set()
    
    for x in range(mLength):
        for y in range(nLength):
            if matrix[x][y] == 0:
                yset.add(y)
                xset.add(x)

    for x in xset:
        for value in range(nLength):
            matrix[x][value] = 0

    for y in yset:
        for value in range(mLength):
            matrix[value][y] = 0
    return matrix

def makeMatrix(M,N):
    count = 0 
    matrix = [[[] for _ in range(N)] for _ in range(M)]
    for x in range(M):
        for y in range(N):
            matrix[x][y] = count
            count += 1

    # if matrix[0][3] == 4:
    #     matrix[0][3] = 0
    return matrix

print(makeMatrix(1,1))
print(zeroMatrix(makeMatrix(1,1)))
