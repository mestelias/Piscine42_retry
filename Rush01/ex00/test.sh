cc -Wall -Wextra -Werror -g3 -fsanitize=address -o rush-01 *.c

# Errors input
./rush-01 "" # Empty
./rush-01 "1 2 3 4 1 2 3 4 1 2 3 4 1 2 3" # 15
./rush-01 "1 2 3 4 1 2 3 4 1 2 3 4 1 2 3 4 1" # 17
./rush-01 "bonjour"
./rush-01 "1 2 3 4 1 2 3 b 4 1 2 3 4 1 2 3 4"
./rush-01 "1 2 34 1 2 3 4 1 2 3 4 1 2 3 4"
./rush-01 "                                    8"
./rush-01 "8                              "
./rush-01 $(cat ./weird)

echo "-------------------------"

# Errors algo
./rush-01 "1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1"
./rush-01 "1234123412341234"
#./rush-01 ""
#./rush-01 ""
#./rush-01 ""
#./rush-01 ""
#./rush-01 ""
#./rush-01 ""
#./rush-01 ""
