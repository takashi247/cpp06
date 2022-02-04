#!/bin/bash

GREEN="\033[32m"
RESET="\033[39m"

converter_test () {
	echo -e ${GREEN}${1}${RESET}
	eval $1
	echo ""
}

converter_test './convert a'
converter_test './convert " "'
converter_test './convert ""'
converter_test './convert 1'
converter_test './convert `getconf INT_MAX`'
