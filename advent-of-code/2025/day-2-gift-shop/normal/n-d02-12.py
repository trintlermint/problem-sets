import re
import sys

def part1(data):
    l = data.strip("\n")
    t = 0
    for r in l.split(","):
        left, right = map(int, r.split("-"))
        for n in range(left, right + 1):
            s_n = str(n)
            if s_n[: len(s_n) // 2] == s_n[len(s_n) // 2 :]:
                t += n

    return t


def part2(data):
    l = data.strip("\n")
    t = 0
    for r in l.split(","):
        left, right = map(int, r.split("-"))
        for n in range(left, right + 1):
            s_n = str(n)
            if re.search(r"^(.+)\1+$", s_n):
                t += n
    return t


def main():
    data = sys.stdin.read()
    p1 = part1(data)
    p2 = part2(data)
    print(p1, p2)


if __name__ == "__main__":
    main()
