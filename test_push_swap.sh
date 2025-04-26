echo -e "\n\033[1;34m🚀 Empezando tests automáticos para PUSH_SWAP...\033[0m"

# Casos normales
echo -e "\n\033[1;36m🔹 Casos normales:\033[0m"
./push_swap 2 1
./push_swap 1 3 2
./push_swap 3 2 1
./push_swap 4 1 3 2
./push_swap 10 5 3 8 6 1 7 2 9 4

# Casos de error
echo -e "\n\033[1;36m🔹 Casos de error (debe mostrar 'Error'):\033[0m"
./push_swap 1 2 a
./push_swap 1 2 2147483648
./push_swap 1 2 2
./push_swap ""
./push_swap "  "
./push_swap "+42"
./push_swap "- 42"

# Casos límite
echo -e "\n\033[1;36m🔹 Casos límite:\033[0m"
./push_swap
./push_swap 1
./push_swap 2147483647 -2147483648
./push_swap 999 0 -999

# Pruebas de ordenación grandes
echo -e "\n\033[1;36m🔹 Pruebas grandes (100 números aleatorios):\033[0m"
ARG=$(seq 1 100 | sort -R | tr '\n' ' ')
MOVES=$(./push_swap $ARG | wc -l)
RESULT=$(./push_swap $ARG | ./checker_linux $ARG)
echo "Movimientos: $MOVES"
echo "Resultado: $RESULT"
if [ "$RESULT" = "OK" ] && [ "$MOVES" -le 700 ]; then
    echo -e "\033[1;32m✅ 100 números PASADO.\033[0m"
else
    echo -e "\033[1;31m❌ 100 números ERROR.\033[0m"
fi

echo -e "\n\033[1;36m🔹 Pruebas grandes (500 números aleatorios):\033[0m"
ARG=$(seq 1 500 | sort -R | tr '\n' ' ')
MOVES=$(./push_swap $ARG | wc -l)
RESULT=$(./push_swap $ARG | ./checker_linux $ARG)
echo "Movimientos: $MOVES"
echo "Resultado: $RESULT"
if [ "$RESULT" = "OK" ] && [ "$MOVES" -le 5500 ]; then
    echo -e "\033[1;32m✅ 500 números PASADO.\033[0m"
else
    echo -e "\033[1;31m❌ 500 números ERROR.\033[0m"
fi

echo -e "\n\033[1;34m🎯 Tests automáticos terminados.\033[0m"