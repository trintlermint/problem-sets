import sys

def solve(data):
    lines = data.strip().split('\n')
    max_len = max(len(line) for line in lines)
    lines = [line.ljust(max_len) for line in lines]
    
    cols = [''.join(lines[r][c] for r in range(len(lines))) for c in range(max_len)]
    
    problems = []
    i = 0
    while i < len(cols):
        if cols[i]. strip() == '':
            i += 1
            continue
        j = i
        while j < len(cols) and cols[j].strip() != '':
            j += 1
        prob_cols = cols[i:j]
        op = prob_cols[0][-1]
        nums = []
        for col in prob_cols:
            num_str = col[:-1]. strip()
            if num_str: 
                nums.append(int(num_str))
        problems.append((op, nums))
        i = j
    
    p1 = 0
    for op, nums in problems:
        if op == '+':
            p1 += sum(nums)
        else: 
            r = 1
            for n in nums:
                r *= n
            p1 += r
    cols_rev = cols[::-1]
    problems2 = []
    i = 0
    while i < len(cols_rev):
        if cols_rev[i].strip() == '':
            i += 1
            continue
        j = i
        while j < len(cols_rev) and cols_rev[j].strip() != '':
            j += 1
        prob_cols = cols_rev[i:j]
        op = prob_cols[0][-1]
        nums = []
        for col in prob_cols: 
            digits = col[:-1].replace(' ', '')
            if digits: 
                nums.append(int(digits))
        problems2.append((op, nums))
        i = j
    
    p2 = 0
    for op, nums in problems2:
        if op == '+':
            p2 += sum(nums)
        else:
            r = 1
            for n in nums: 
                r *= n
            p2 += r
    
    return p1, p2

if __name__ == "__main__": 
    p1, p2 = solve(sys.stdin.read())
    print(p1)
    print(p2)
