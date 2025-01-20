def rotate(original, N):
    print("original", original)
    rotated = [[[] for x in range(N)] for m in range(N)]
    for y in range(1,N+1,1):
        for x in range(1,N+1,1):
            rotatedX = N - x + 1
            rotated[y-1][x-1] = original[rotatedX-1][y-1]
    return rotated



def makematrix(N):
    original = [[[] for x in range(N)] for m in range(N)]
    count = 1 
    for y in range(N):
        for x in range(N):
            original[y][x] = count
            count += 1

    return original


print("rotated:", rotate(makematrix(5), 5))
