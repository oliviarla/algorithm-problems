T=int(input())
for _ in range(T):
    n = int(input())
    dp = [[0 for _ in range(100001)],[0 for _ in range(100001)]]
    stickers = [] # [1][n-1]공간만큼 사용
    stickers.append(list(map(int, input().split())))
    stickers.append(list(map(int, input().split())))
    dp[0][1]=stickers[0][0]
    dp[1][1]=stickers[1][0]
    for i in range(2, n+1):
        dp[0][i]=max(dp[1][i-1], dp[1][i-2])+stickers[0][i-1]
        dp[1][i]=max(dp[0][i-1], dp[0][i-2])+stickers[1][i-1]
    print(max(dp[0][n],dp[1][n]))