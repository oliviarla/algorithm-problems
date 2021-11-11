n, m, k = map(int, input().split())

teams = 0
remain_ppl = 0
while n>=2 and m>=1:
    n-=2
    m-=1
    teams +=1
remain_ppl = m+n

while k>0:
    # 남은 사람보다 k가 크면
    if k>remain_ppl:
        teams-=1 #남은사람을 추가한다
        remain_ppl+=3
    k-=remain_ppl #남은 사람은 k로 채워진다
    remain_ppl = 0

print(teams)