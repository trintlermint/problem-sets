# sol 1
awk 'NR==10' file.txt

# sol 2
sed -n '10p' file.txt

# sol 3, inefficient for high n
head -n 10 file.txt | tail -n 1
