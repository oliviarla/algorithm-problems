str1 = input()


def palindrome(input_str):
    input_list = []
    for i in input_str:
        if i.isalnum():
            input_list.append(i.lower())

    while len(input_list) > 1:
        if input_list.pop(0) != input_list.pop():
            return False
    return True


print(palindrome(str1))