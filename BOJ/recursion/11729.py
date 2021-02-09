#하노이 탑 이동 순서
#위키백과를 참고하였음

def hanoi(n, from_pos, to_pos, aux_pos):
    if n == 1:
        print(from_pos, to_pos)
        return
    hanoi(n-1, from_pos, aux_pos, to_pos)
    print(from_pos, to_pos)
    hanoi(n-1, aux_pos, to_pos, from_pos)

def iter(n):
    print(pow(2, n)-1)

n = int(input())

iter(n)
hanoi(n, 1, 3, 2)
