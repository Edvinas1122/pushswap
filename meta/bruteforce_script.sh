while read p; do
  printf "\n\n$p\n"
  ./../brute_force $p | cut -c 5-
    printf "\n"
done <5_digit_cambo.txt
