str1 = input()


def palindrome(input_str):
    input_list = []
    for i in input_str:
        input_list.append(i)

    for i in range(len(input_list)):
        if input_list[i] != input_list.pop():
            print(input_list.pop())
            print('false')
            return
    print('true')
    return


palindrome(str1)