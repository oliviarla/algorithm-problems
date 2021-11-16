import sys
n=int(input())
students = []
for _ in range(n):
    name, k, e, m = input().split()
    students.append((k,e,m,name))

students.sort(key=lambda students: (-int(students[0]), int(students[1]), -int(students[2]), students[3]))
for i in students:
    print(i[3])