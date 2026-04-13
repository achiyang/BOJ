import sys

input = sys.stdin.readline

def is_div_points(line, a, b):
    f1 = (line[2] - line[0]) * (a[1] - line[1]) - (line[3] - line[1]) * (a[0] - line[0])
    f2 = (line[2] - line[0]) * (b[1] - line[1]) - (line[3] - line[1]) * (b[0] - line[0])
    return f1*f2 < 0

def is_cross(a, b):
    return is_div_points(a, (b[0], b[1]), (b[2], b[3])) and is_div_points(b, (a[0], a[1]), (a[2], a[3]))

def main():
    line_1 = tuple(map(int, input().strip().split()))
    line_2 = tuple(map(int, input().strip().split()))

    if (is_cross(line_1, line_2)):
        print(1)
    else:
        print(0)

if __name__ == "__main__":
    main()
