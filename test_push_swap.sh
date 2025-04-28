echo "🔴 Test de errores:"
./push_swap " "; ./push_swap ""; ./push_swap "1 2 a"; ./push_swap "2147483648"; ./push_swap "-2147483649"; ./push_swap "1 2 2"; ./push_swap "- 42"

echo "🔵 Test de orden ya correcto:"
./push_swap 1 2; ./push_swap 0 1 2 3 4; ./push_swap -3 -2 -1 0 1

echo "🟢 Test de ordenación pequeña:"
./push_swap 3 2 1; ./push_swap 5 1 4 2 3; ./push_swap 2 1 3

echo "🟡 Test de memory leaks:"
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./push_swap 3 2 1
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./push_swap 1 50 2 99 4
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./push_swap 0 2147483647 -2147483648

echo "🟣 Test 1-100 números:"
ARG=$(seq 1 100 | sort -R); ./push_swap $ARG | ./checker_linux $ARG
ARG=$(seq 1 100 | sort -R); ./push_swap $ARG | wc -l

echo "🟤 Test 1-500 números:"
ARG=$(seq 1 500 | sort -R); ./push_swap $ARG | ./checker_linux $ARG
ARG=$(seq 1 500 | sort -R); ./push_swap $ARG | wc -l
