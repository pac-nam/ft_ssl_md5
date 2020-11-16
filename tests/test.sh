#!/usr/bin/env bash
source './functions.sh'

bin=.././ft_ssl
RED="\033[31;1m"
GREEN="\033[32;1m"
BLUE="\033[34;1m"
RESET="\033[0m"

algosShaX=$(ls -l1d ../srcs/sha* | cut -d '/' -f 3 | tr '\n' ' ')
success=0
failed=0
total_tests=0
LINUX=$(uname -ar | awk '{print $1}')
IS_LINUX=false
if [[ ${LINUX} == "Linux" ]]; then
	IS_LINUX=true
fi
if [ $# -eq 0 ]; then
	testFunction "md5"
	testShaFunction ${algosShaX}
	testBase64Function
else
	for algo in $@
	do
		if [[ ${algo} == 'md5' ]]; then
			testFunction "md5"
		else
			for algoShaX in $(echo ${algosShaX})
			do
				if [[ ${algo} == ${algoShaX} ]]; then
					testShaFunction ${algo}
				fi
			done
		fi
	done
fi

printf "%b" "\n\n"
printf "%b" "${BLUE}Success ${success}/${total_tests}${RESET}\n"
printf "%b" "${RED}Fail ${failed}/${total_tests}${RESET}\n"
