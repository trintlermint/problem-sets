# sol 1
awk '

{
    for (i = 1; i <= NF; i++)
    {
        as[i, NR] = $i
    }
    max_fields = (NF > max_fields ? NF : max_fields)
    max_rows = NR
}

END {
    for (i = 1; i <= max_fields; i++)
    {
        for (j = 1; j <= max_rows; j++)
        {
            printf "%s%s", as[i,j], (j == max_rows ? ORS : OFS)
        }
    }
}

' OFS=' ' file.txt

# sol 2, inefficient


cols=$(awk '{print NF; exit}' file.txt)
for ((i=1; i<=cols; i++)); do
  awk -v col="$i" '{printf "%s%s", (NR>1?" ":""), $col}' file.txt
  echo
done

# sol 3, FAILED cannot edit file


#while :; do
#  # Print the first field of every line (the current "column")
#  awk '{printf "%s%s", NR==1?"":" ", $1} END{print ""}' file.txt
#  
#  # Remove the first field from every line, creating a new file
#  awk '{$1=""; sub(/^ /, ""); print}' file.txt > tmp && mv tmp file.txt
#  
#  # Stop when the first line is empty (no more columns)
#  [ -z "$(head -n1 file.txt)" ] && break
#done

# sol 4, need to trim new line

cols=$(sed -n '1s/[^ ]\+/&\n/gp' file.txt | wc -l)
for ((i=1; i<=cols; i++)); do
  sed -n "s/^\(\([^ ]* \)\{$((i-1))\}\)\([^ ]*\).*/\3/p" file.txt | paste -sd' ' -
done

# sol 4a, inefficient
cols=$(sed -n '1s/[^ ]\+/&\n/gp' file.txt | wc -l); for ((i=1; i<=cols; ++i)); do sed -n "s/^\(\([^ ]* \)\{$((i-1))\}\)\([^ ]*\).*/\3/p" file.txt | paste -sd' ' -; done | awk 'NR>1{printf "\n"}{printf "%s", $0}'

#sol 5 by another leetcode user
seq 1 $(head -1 file.txt | wc -w) | xargs -I '{}' bash -c "cut -d '"' '"' -f {} file.txt| xargs"
