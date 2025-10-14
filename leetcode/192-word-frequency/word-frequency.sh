cat words.txt | 
  tr -s ' ' '\n' | # one word / line
  grep -v '^$' |   # rm empty line
  sort |         
  uniq -c |        # count
  sort -nr |       # sort by count (descending)
  awk '{print $2 " " $1}'
