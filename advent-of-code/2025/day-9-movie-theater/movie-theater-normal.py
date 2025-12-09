def is_point_on_edge(y, x, vertices):
    n = len(vertices)
    for i in range(n):
        y1, x1 = vertices[i]
        y2, x2 = vertices[(i+1) % n]
        if y1 == y2 and y == y1 and min(x1, x2) <= x <= max(x1, x2):
            return True
        if x1 == x2 and x == x1 and min(y1, y2) <= y <= max(y1, y2):
            return True
    return False

def is_point_inside_polygon(y, x, vertices):
    if is_point_on_edge(y, x, vertices):
        return True
    n = len(vertices)
    inside = False
    for i in range(n):
        y1, x1 = vertices[i]
        y2, x2 = vertices[(i+1) % n]
        if x > min(x1, x2) and x <= max(x1, x2):
            if y <= max(y1, y2):
                if x1 != x2:
                    intersection_y = (x - x1) * (y2 - y1) / (x2 - x1) + y1
                else:
                    intersection_y = y1 # vertical edge case
                if y1 == y2 or y <= intersection_y:
                    inside = not inside
    return inside

def find_max_rectangle_area(vertices):
    max_area = 0
    n = len(vertices)
    for i in range(n):
        for j in range(i+1, n):
            y1, x1 = vertices[i]
            y2, x2 = vertices[j]
            area = (abs(y1 - y2) + 1) * (abs(x1 - x2) + 1)
            max_area = max(max_area, area)
    return max_area

def find_max_rectangle_area_inside_polygon(vertices):
    max_area = 0
    n = len(vertices)
    for i in range(n):
        for j in range(i+1, n):
            y1, x1 = vertices[i]
            y2, x2 = vertices[j]
            area = (abs(y1 - y2) + 1) * (abs(x1 - x2) + 1)
            if area <= max_area:
                continue
            y_min, y_max = min(y1, y2), max(y1, y2)
            x_min, x_max = min(x1, x2), max(x1, x2)
            # Top & bottom edges
            if not all(is_point_inside_polygon(y_min, x, vertices) for x in range(x_min, x_max + 1)):
                continue
            if not all(is_point_inside_polygon(y_max, x, vertices) for x in range(x_min, x_max + 1)):
                continue
            # Left & right edges
            if not all(is_point_inside_polygon(y, x_min, vertices) for y in range(y_min+1, y_max)):
                continue
            if not all(is_point_inside_polygon(y, x_max, vertices) for y in range(y_min+1, y_max)):
                continue
            max_area = area

    return max_area

def parse_vertices(data):
    return [tuple(map(int, line.split(","))) for line in data.strip().split("\n")]

def part1(data):
    vertices = parse_vertices(data)
    max_area = find_max_rectangle_area(vertices)
    print(max_area)
    return max_area

def part2(data):
    vertices = parse_vertices(data)
    max_area = find_max_rectangle_area_inside_polygon(vertices)
    return max_area
