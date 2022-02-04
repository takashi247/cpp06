#!/bin/bash

GREEN="\033[32m"
RESET="\033[39m"

converter_test () {
	echo -e ${GREEN}${1}${RESET}
	eval $1
	echo ""
}

converter_test '../convert a'
converter_test '../convert " "'
converter_test '../convert ""'
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
converter_test '../convert 0.0f'
converter_test '../convert +0.0f'
converter_test '../convert -0.0f'
converter_test '../convert 4.2f'
converter_test '../convert inff'
converter_test '../convert -inff'
converter_test '../convert nanf'
converter_test '../convert 0.0'
converter_test '../convert +0.0'
converter_test '../convert -0.0'
converter_test '../convert 4.2'
converter_test '../convert inf'
converter_test '../convert -inf'
converter_test '../convert nan'
