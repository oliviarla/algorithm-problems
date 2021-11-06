H, M = map(int, input().split())

if M < 45:
    print(23 if H-1<0 else H-1, end=" ")
    print(60-45+M)
else:
    print(H, end=" ")
    print(M-45)