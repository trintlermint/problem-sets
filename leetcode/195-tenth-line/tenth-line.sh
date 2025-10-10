# PASSED sol 1
#awk 'NR==10' file.txt

# BEST-CASE PASSED sol 2
#sed -n '10p' file.txt

# FAILED sol 3, inefficient for high n
# head -n 10 file.txt | tail -n 1

# PASSED sol4, like 3 but with handling for <10 lines
# [ $(wc -l < file.txt) -ge 10 ] && head -n 10 file.txt | tail -n 1

# sol5
# perl -ne 'print if $. == 10; exit if $. == 10' file.txt
