use feature 'say';

say $_%15==0 ? 'fizzbuzz' : $_%3==0 ? 'fizz' : $_%5==0 ? 'buzz' : $_ for 1..20;
