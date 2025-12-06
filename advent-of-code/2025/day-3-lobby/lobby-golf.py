import sys;print(sum(int(max(w[:-1])+max(w[w.index(max(w[:-1]))+1:]))for w in sys.stdin.read().split()))
