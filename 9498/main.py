ranges = {
    'A': range(90, 101),
    'B': range(80, 90),
    'C': range(70, 80),
    'D': range(60, 70),
    'F': range(0, 60)
}

n = int(input())

for grade, range_ in ranges.items():
    if n in range_:
        print(grade)