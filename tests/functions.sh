#!/usr/bin/env bash

####################################################
####################### TEST #######################
######################## MD5 #######################
####################################################
function testFunction() {
	for algo in $@
	do
		printf "%b" "\n\n"
		printf "%b" "${BLUE}Test ${algo} with fd 0\n${RESET}"
		printf "%b" "\n\n"
		for line in $(cat str_to_test)
		do
			mine=$(echo -n ${line} | ${bin} ${algo})
			if [[ ${IS_LINUX} == "true" ]]; then
				real=$(echo -n ${line} | openssl md5 | awk '{print $2}')
			else
				real=$(echo -n ${line} | ${algo})
			fi
			if [[ -z $(diff <(echo ${mine}) <(echo ${real})) ]]; then
				printf "%b" "${GREEN}md5 ok for ${line}${RESET}\n"
				success=$((success + 1))
			else
				printf "%b" "${RED}md5 fail for ${line}\nft_md5: ${mine}\n  ${algo}: ${real}\n"
				failed=$((failed + 1))
			fi
			total_tests=$((total_tests + 1))
		done
		printf "%b" "\n\n"
		printf "%b" "${BLUE}Test${algo} with -s${RESET}"
		printf "%b" "\n\n"
		for line in $(cat str_to_test)
		do
			mine=$(${bin} ${algo} -q -s ${line})
			if [[ ${IS_LINUX} == "true" ]]; then
				real=$(echo -n ${line} | openssl md5 | awk '{print $2}')
			else
				real=$(md5 -q -s ${line})
			fi
			if [[ -z $(diff <(echo ${mine}) <(echo ${real})) ]]; then
				printf "%b" "${GREEN}md5 ok for ${line}\n"
				success=$((success + 1))
			else
				printf "%b" "${RED}md5 fail for ${line}\nft_md5: ${mine}\n  ${algo}: ${real}\n"
				failed=$((failed + 1))
			fi
			total_tests=$((total_tests + 1))
		done
		for line in $(cat str_to_test)
		do
			mine=$(${bin} ${algo} -q -s ${line})
			if [[ ${IS_LINUX} == "true" ]]; then
				real=$(echo -n ${line} | openssl md5 | awk '{print $2}')
			else
				real=$(md5 -q -s ${line})
			fi
			if [[ -z $(diff <(echo ${mine}) <(echo ${real})) ]]; then
				printf "%b" "${GREEN}md5 ok for ${line}\n"
				success=$((success + 1))
			else
				printf "%b" "${RED}md5 fail for ${line}\nft_md5: ${mine}\n  ${algo}: ${real}\n"
				failed=$((failed + 1))
			fi
			total_tests=$((total_tests + 1))
		done

		printf "%b" "\n\n"
		printf "%b" "${BLUE}Test${algo} with file${RESET}"
		printf "%b" "\n\n"
		for file in $(ls -1d ../srcs/**/*.c)
		do

			mine=$(cat ${file} | ${bin} ${algo})
			if [[ ${IS_LINUX} == "true" ]]; then
				real=$(cat ${file} | openssl md5 | awk '{print $2}')
			else
				real=$(cat ${file} | ${algo})
			fi
			if [[ ${IS_LINUX} == "true" ]]; then
				real=$(cat ${file} | openssl md5 | awk '{print $2}')
			else
				real=$(cat ${file} | ${algo})
			fi
			if [[ -z $(diff <(echo ${mine}) <(echo ${real})) ]]; then
				printf "%b" "${GREEN}md5 ok for ${file}${RESET}\n"
				success=$((success + 1))
			else
				printf "%b" "${RED}md5 fail for ${file}\nft_md5: ${mine}\n  ${algo}: ${real}\n"
				failed=$((failed + 1))
			fi
			total_tests=$((total_tests + 1))
		done
		for file in $(ls -1d ../objects/**/*.o)
		do

			mine=$(cat ${file} | ${bin} ${algo})
			if [[ ${IS_LINUX} == "true" ]]; then
				real=$(cat ${file} | openssl md5 | awk '{print $2}')
			else
				real=$(cat ${file} | ${algo})
			fi
			if [[ -z $(diff <(echo ${mine}) <(echo ${real})) ]]; then
				printf "%b" "${GREEN}md5 ok for ${file}${RESET}\n"
				success=$((success + 1))
			else
				printf "%b" "${RED}md5 fail for ${file}\nft_md5: ${mine}\n  ${algo}: ${real}\n"
				failed=$((failed + 1))
			fi
			total_tests=$((total_tests + 1))
		done
		for file in $(ls -1d /bin/*)
		do
			mine=$(cat ${file} | ${bin} ${algo})
			if [[ ${IS_LINUX} == "true" ]]; then
				real=$(cat ${file} | openssl md5 | awk '{print $2}')
			else
				real=$(cat ${file} | ${algo})
			fi
			if [[ -z $(diff <(echo ${mine}) <(echo ${real})) ]]; then
				printf "%b" "${GREEN}md5 ok for ${file}${RESET}\n"
				success=$((success + 1))
			else
				printf "%b" "${RED}md5 fail for ${file}\nft_md5: ${mine}\n  ${algo}: ${real}\n"
				failed=$((failed + 1))
			fi
			total_tests=$((total_tests + 1))
		done
	done
}
####################################################
####################### TEST #######################
###################### SHAx ######################
####################################################
function testShaFunction() {
	for algo in $@
	do
		printf "%b" "\n\n"
		printf "%b" "${BLUE}Test ${algo} with fd 0"
		printf "%b" "\n\n"

		for line in $(cat str_to_test)
		do
			mine=$(echo -n ${line} | ${bin} ${algo})
			if [[ ${IS_LINUX} == "true" ]]; then
				real=$(echo -n ${line} | openssl ${algo} | awk '{print $2}')
			else
				real=$(echo -n ${line} | openssl ${algo})
			fi
			if [[ -z $(diff <(echo ${mine}) <(echo ${real})) ]]; then
				printf "%b" "${GREEN}${algo} ok for ${line}${RESET}\n"
				success=$((success + 1))
			else
				printf "%b" "${RED}${algo} fail for ${line}\nft_${algo}: ${mine}\n   ${algo}: ${real}\n"
				failed=$((failed + 1))
			fi
			total_tests=$((total_tests + 1))
		done

		printf "%b" "\n\n"
		printf "%b" "${BLUE}Test ${algo} with -s"
		printf "%b" "\n\n"

		for line in $(cat str_to_test)
		do
			mine=$(${bin} ${algo} -q -s ${line})
			if [[ ${IS_LINUX} == "true" ]]; then
				real=$(echo -n ${line} | openssl ${algo} | awk '{print $2}')
			else
				real=$(echo -n ${line} | openssl ${algo})
			fi
			if [[ -z $(diff <(echo ${mine}) <(echo ${real})) ]]; then
				printf "%b" "${GREEN}${algo} ok for ${line}\n"
				success=$((success + 1))
			else
				printf "%b" "${RED}${algo} fail for ${line}\nft_${algo}: ${mine}\n   ${algo}: ${real}\n"
				failed=$((failed + 1))
			fi
			total_tests=$((total_tests + 1))
		done
		printf "%b" "\n\n"
		printf "%b" "${BLUE}Test ${algo} with file${RESET}"
		printf "%b" "\n\n"

		for file in $(ls -1d ../srcs/**/*.c)
		do
			mine=$(cat ${file} | ${bin} ${algo})
			if [[ ${IS_LINUX} == "true" ]]; then
				real=$(cat ${file} | openssl ${algo} | awk '{print $2}')
			else
				real=$(cat ${file} | openssl ${algo})
			fi
			if [[ -z $(diff <(echo ${mine}) <(echo ${real})) ]]; then
				printf "%b" "${GREEN}${algo} ok for ${file}${RESET}\n"
				success=$((success + 1))
			else
				printf "%b" "${RED}${algo} fail for ${file}\nft_${algo}: ${mine}\n   ${algo}: ${real}\n"
				failed=$((failed + 1))
			fi
			total_tests=$((total_tests + 1))
		done
		for file in $(ls -1d ../objects/**/*.o)
		do
			mine=$(cat ${file} | ${bin} ${algo})
			if [[ ${IS_LINUX} == "true" ]]; then
				real=$(cat ${file} | openssl ${algo} | awk '{print $2}')
			else
				real=$(cat ${file} | openssl ${algo})
			fi
			if [[ -z $(diff <(echo ${mine}) <(echo ${real})) ]]; then
				printf "%b" "${GREEN}${algo} ok for ${file}${RESET}\n"
				success=$((success + 1))
			else
				printf "%b" "${RED}${algo} fail for ${file}\nft_${algo}: ${mine}\n   ${algo}: ${real}\n"
				failed=$((failed + 1))
			fi
			total_tests=$((total_tests + 1))
		done
		for file in $(ls -1d /bin/*)
		do
			mine=$(cat ${file} | ${bin} ${algo})
			if [[ ${IS_LINUX} == "true" ]]; then
				real=$(cat ${file} | openssl ${algo} | awk '{print $2}')
			else
				real=$(cat ${file} | openssl ${algo})
			fi
			if [[ -z $(diff <(echo ${mine}) <(echo ${real})) ]]; then
				printf "%b" "${GREEN}${algo} ok for ${file}${RESET}\n"
				success=$((success + 1))
			else
				printf "%b" "${RED}${algo} fail for ${file}\nft_${algo}: ${mine}\n   ${algo}: ${real}\n"
				failed=$((failed + 1))
			fi
			total_tests=$((total_tests + 1))
		done
	done
}

####################################################
####################### TEST #######################
###################### base64 ######################
###################### encode ######################
####################################################
function testBase64Function() {
	printf "%b" "\n\n"
	printf "%b" "${BLUE}Test ${algo} with fd 0"
	printf "%b" "\n\n"

	algo="base64"
	for line in $(cat str_to_test)
	do
		mine=$(echo -n ${line} | ${bin} ${algo} -e)
		if [[ ${IS_LINUX} == "true" ]]; then
			real=$(echo -n ${line} | base64)
		else
			real=$(echo -n ${line} | base64)
		fi
		if [[ -z $(diff <(echo ${mine}) <(echo ${real})) ]]; then
			printf "%b" "${GREEN}${algo} ok for ${line}${RESET}\n"
			success=$((success + 1))
		else
			printf "%b" "${RED}${algo} fail for ${line}\nft_${algo}: ${mine}\n   ${algo}: ${real}\n"
			failed=$((failed + 1))
		fi
		total_tests=$((total_tests + 1))
	done

	for file in $(ls -1d ../srcs/**/*.c)
		do
			mine=$(cat ${file} | ${bin} ${algo} -e)
			if [[ ${IS_LINUX} == "true" ]]; then
				real=$(cat ${file} | base64)
			else
				real=$(cat ${file} | base64)
			fi
			if [[ -z $(diff <(echo ${mine}) <(echo ${real})) ]]; then
				printf "%b" "${GREEN}${algo} ok for ${file}${RESET}\n"
				success=$((success + 1))
			else
				printf "%b" "${RED}${algo} fail for ${file}\nft_${algo}: ${mine}\n   ${algo}: ${real}\n"
				failed=$((failed + 1))
			fi
			total_tests=$((total_tests + 1))
		done
		for file in $(ls -1d ../objects/**/*.o)
		do
			mine=$(cat ${file} | ${bin} ${algo} -e)
			if [[ ${IS_LINUX} == "true" ]]; then
				real=$(cat ${file} | base64)
			else
				real=$(cat ${file} | base64)
			fi
			if [[ -z $(diff <(echo ${mine}) <(echo ${real})) ]]; then
				printf "%b" "${GREEN}${algo} ok for ${file}${RESET}\n"
				success=$((success + 1))
			else
				printf "%b" "${RED}${algo} fail for ${file}\nft_${algo}: ${mine}\n   ${algo}: ${real}\n"
				failed=$((failed + 1))
			fi
			total_tests=$((total_tests + 1))
		done
		for file in $(ls -1d /bin/*)
		do
			mine=$(cat ${file} | ${bin} ${algo} -e)
			if [[ ${IS_LINUX} == "true" ]]; then
				real=$(cat ${file} | base64)
			else
				real=$(cat ${file} | base64)
			fi
			if [[ -z $(diff <(echo ${mine}) <(echo ${real})) ]]; then
				printf "%b" "${GREEN}${algo} ok for ${file}${RESET}\n"
				success=$((success + 1))
			else
				printf "%b" "${RED}${algo} fail for ${file}\nft_${algo}: ${mine}\n   ${algo}: ${real}\n"
				failed=$((failed + 1))
			fi
			total_tests=$((total_tests + 1))
		done
}