# n = int(input())
# a = list(map(int, input().split()))
# d = [0]*(1001)
# d[0]=a[0]
# res = 0
# for i in range(1, n):
#     d[i]=a[i]
#     for j in range(0, i):
#         if a[i]>a[j]:
#             if d[i]<d[j]+a[i]:
#                 d[i] = d[j]+a[i]
#     res = max(d[i], res)
# print(res)

n = int(input())
a = list(map(int, input().split()))
d = a[:] # i를 포함하는 증가 부분 수열의 합 중 최대 합을 저장
for i in range(1, n):
    for j in range(0, i):
        if a[i]>a[j]:
            d[i] = max(d[i], d[j]+a[i]) #(i보다 작은 값을 포함한 최대 합) + (현재 i값) -> i 포함 증가 수열의 최대 합이 됨

print(max(d))