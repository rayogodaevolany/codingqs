N = int(input())
A = list(map(int, input().split()))

dp = [[0 for col in range(N)] for row in range(N)] 

count = 0;
for i in range(N):
    for j in range(N):
        if dp[i][j] == 1:
            count+=1
        elif dp[i][j] == -1:
            continue
        elif dp[i][j] == 0:
            if j - i == A[j] + A[i]:
                count += 1
                dp[i][j] = 1
            else:
                dp[i][j] = -1

print(count)

            

