def bfs(Alist, A, B):
    q = []
    visited = []
    q.append(A)
    while q:
        current = q.pop(0)
        if current == B:
            return True
        visited.append(current)
        for neighbor in Alist[current]:
            if neighbor not in visited:
                q.append(neighbor)
    return False


AdjList = { 
           'A':['E'],
           'E':['A', 'C', 'D'],
           'C':['E'],
           'D':['E'],
           'F':[]
        }

print(bfs(AdjList,'A','F'))
