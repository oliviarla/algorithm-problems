n = int(input())

#dp table 구성: d[N][i] -> N자리수에서 끝자리가 i인 경우 생성할 수 있는 계단수 개수를 저장
d = [[0 for _ in range(10)]for _ in range(101)] #dp table은 n의 최댓값만큼 생성해두어야 runtimeerror 발생 안함
for i in range(1, 10):
    d[0][i]=1

for N in range(1, n):
    d[N][0]=d[N-1][1] #끝자리가 0이 될 경우는 이전에 1인 경우 뿐 -> 이전 끝자리가 1인 경우 그대로 가져옴
    d[N][9]=d[N-1][8] #끝자리가 9가 될 경우는 이전에 8인 경우 뿐 -> 이전 끝자리가 8인 경우 그대로 가져옴
    for i in range(1, 9):
            d[N][i]=(d[N-1][i-1]+d[N-1][i+1])%1000000000 #끝자리가 i가 될 경우는 이전 끝자리가 i-1이거나 i+1일 경우이므로 두 경우를 합함

print(sum(d[n-1])%1000000000)