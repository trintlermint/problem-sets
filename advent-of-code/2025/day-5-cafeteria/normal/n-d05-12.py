
def part1(data):
    l = data.split("\n")
    ranges = []
    for i in range(len(l)):
        if l[i] == "":
            break
        L, R = l[i].split("-")
        ranges.append((int(L), int(R)))

    t = 0
    for i in range(i + 1, len(l)):
        n = int(l[i])
        for j in range(len(ranges)):
            if ranges[j][0] <= n <= ranges[j][1]:
                t += 1
                break
    return t


def part2(data):
    l = data.split("\n")
    ranges = []
    for i in range(len(l)):
        if l[i] == "":
            break
        L, R = l[i].split("-")
        ranges.append((int(L), int(R)))

    t = 0
    while ranges:
        new_ranges = []
        r = ranges[0]
        left, right = r
        t += right - left + 1
        for r in ranges:
            new_left, new_right = r
            if left <= new_left <= right and right <= new_right:
                if right + 1 <= new_right:
                    new_ranges.append((right + 1, new_right))
            elif new_left <= left and left <= new_right <= right:
                if new_left <= left - 1:
                    new_ranges.append((new_left, left - 1))
            elif new_left < left and right < new_right:
                new_ranges.append((new_left, left - 1))
                new_ranges.append((right + 1, new_right))
            elif left <= new_left <= right and left <= new_right <= right:
                pass
            else:
                new_ranges.append(r)

        ranges = new_ranges

    return t


def main():
    day = int(__file__.split("/")[-2][-2:])
    data = get_data(day=day, year=YEAR)
    p1 = part1(data)
    if p1:
        submit(p1, part="a", day=day, year=YEAR)
    p2 = part2(data)
    if p2:
        submit(p2, part="b", day=day, year=YEAR)
