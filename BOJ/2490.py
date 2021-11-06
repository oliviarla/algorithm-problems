for _ in range(3):
    yut = list(map(int, input().split()))
    # 배: 0 등: 1
    count = yut.count(1) # count 대신 sum을 통해 계산하는 방법도 존재

    if count==0:
        print("D")
    elif count==1:
        print("C")
    elif count==2:
        print("B")
    elif count==3:
        print("A")
    elif count==4:
        print("E")