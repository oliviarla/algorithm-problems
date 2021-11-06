cnt = 0
L, P, V = [], [], []
while True:
    cnt+=1
    l, p, v = map(int, input().split())
    if l==0 and p==0 and v==0:
        break
    L.append(l)
    P.append(p)
    V.append(v)

for i in range(len(L)):
    date = (V[i]//P[i])*L[i]
    #나머지가 L[i], 즉 사용 가능한 최대 날짜보다 클 경우 사용 가능한 최대날짜로 변경하여 더해줌
    date += min(L[i], V[i]%P[i])
    print('Case {}: {}'.format(i+1, date))