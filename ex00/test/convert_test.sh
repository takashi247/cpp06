#!/bin/bash

GREEN="\033[32m"
RESET="\033[39m"

converter_test () {
	echo -e ${GREEN}${1}${RESET}
	eval $1
	echo ""
}

print_header () {
	echo -e ${GREEN}${1}${RESET}
	echo ""
}

print_header '*----Subject test---*'
converter_test '../convert 0'
converter_test '../convert nan'
converter_test '../convert 42.0f'

print_header '*----char test----*'
converter_test '../convert a'
converter_test '../convert " "'
converter_test '../convert ""'

print_header '*----int test----*'

converter_test '../convert 0'
converter_test '../convert 1'
converter_test '../convert 42'
converter_test '../convert -42'
converter_test '../convert `getconf INT_MAX`'
converter_test '../convert `getconf INT_MIN`'
converter_test '../convert `getconf LONG_MAX`'
converter_test '../convert `getconf LONG_MIN`'
converter_test '../convert 9223372036854775808' # overflow
converter_test '../convert -9223372036854775809' # overflow

print_header '*----float test----*'

converter_test '../convert 0.0f'
converter_test '../convert +0.0f'
converter_test '../convert -0.0f'
converter_test '../convert 3.40282e+38f'
converter_test '../convert 1.17549e-38f'
converter_test '../convert 3.40282e+39f'
converter_test '../convert 1.17549e-39f'
converter_test '../convert 4.2f'
converter_test '../convert 4.2ef'
converter_test '../convert 4.2e1f'
converter_test '../convert 4.2e2f'
converter_test '../convert 4.2e-2f'
converter_test '../convert 4.2e10f'
converter_test '../convert 4.2e+10f'
converter_test '../convert 4.2e-10f'
converter_test '../convert 42e10f'
converter_test '../convert 42e+10f'
converter_test '../convert 42e-10f'
converter_test '../convert inff'
converter_test '../convert Inff'
converter_test '../convert INFf'
converter_test '../convert iNff'
converter_test '../convert -inff'
converter_test '../convert -Inff'
converter_test '../convert -INFf'
converter_test '../convert -iNff'
converter_test '../convert -iNfF'
converter_test '../convert nanf'
converter_test '../convert Nanf'
converter_test '../convert NANf'
converter_test '../convert nAnf'
converter_test '../convert nanF'
converter_test '../convert 2.14748e+09.0f'
converter_test '../convert infff'
converter_test '../convert -infff'
converter_test '../convert nanff'

print_header '*----double test----*'

converter_test '../convert 0.0'
converter_test '../convert +0.0'
converter_test '../convert -0.0'
converter_test '../convert 1.79769e+308'
converter_test '../convert 2.22507e-308'
converter_test '../convert 1.79769e+309'
converter_test '../convert 2.22507e-309'
converter_test '../convert 4.2'
converter_test '../convert 4.2e'
converter_test '../convert 4.2E'
converter_test '../convert 4.2e1'
converter_test '../convert 4.2E1'
converter_test '../convert 4.2e2'
converter_test '../convert 4.2e-2'
converter_test '../convert 4.2e10'
converter_test '../convert 4.2e+10'
converter_test '../convert 4.2e-10'
converter_test '../convert 42e10'
converter_test '../convert 42e+10'
converter_test '../convert 42e-10'
converter_test '../convert inf'
converter_test '../convert Inf'
converter_test '../convert INF'
converter_test '../convert iNf'
converter_test '../convert -inf'
converter_test '../convert -Inf'
converter_test '../convert -INF'
converter_test '../convert -iNf'
converter_test '../convert nan'
converter_test '../convert Nan'
converter_test '../convert NAN'
converter_test '../convert nAn'
converter_test '../convert 2.14748e+09.0'
