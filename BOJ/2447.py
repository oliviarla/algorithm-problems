#별 찍기

def star(n):
    if n == 3:
        for i in range(n):
            if(i%2==0):
                print('*' * n)
            else:
                print('*'+' '+'*')
        return
    star(int(n/3))
    for i in range(n):
        print('*')

#n은 3의 거듭제곱
n = int(input())

star(n)