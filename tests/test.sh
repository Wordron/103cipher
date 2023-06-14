#!/bin/bash

make
clear


echo -e "\033[92mSimple test cryptage:\033[00m"
echo -e "\033[95mWanted :\033[00m"
echo "Key matrix:"; echo "72    111    109"; echo "101    114    32"; echo "83    0    0"; echo -e
echo -e "Encrypted message:";
echo -e "26690 21552 11810 19718 16524 13668 25322 22497 14177 28422 26097 16433 12333"
echo -e "11874 5824 27541 23754 14452 17180 17553 7963 26387 22047 13895 18804 14859 12033"
echo -e "27738 23835 15331 21487 16656 13238 21696 15978 6976 20750 23307 14093 16788 11751"
echo -e "8981 22339 24861 15619 21295 16524 13668 26403 23610 15190 29451 25764 16106 26394"
echo -e "23307 14093 3312 5106 5014"
echo -e "\033[31mGot :\033[00m"
./103cipher "Just because I don't care doesn't mean I don't understand." "Homer S" 0

echo
echo -e "\033[92mSimple test decryptage:\033[00m"
echo -e "\033[95mWanted :\033[00m"
echo "Key matrix:"; echo "0.0    0.0    0.012"; echo "-0.004    0.012    -0.012"; echo "0.013    -0.013    0.004"; echo -e
echo -e "Decrypted message:";
echo -e "Just because I don't care doesn't mean I don't understand."
echo -e "\033[31mGot :\033[00m"
./103cipher "26690 21552 11810 19718 16524 13668 25322 22497 14177 28422 26097 16433 12333 11874 5824 27541 23754 14452 17180 17553 7963 26387 22047 13895 18804 14859 12033 27738 23835 15331 21487 16656 13238 21696 15978 6976 20750 23307 14093 16788 11751 8981 22339 24861 15619 21295 16524 13668 26403 23610 15190 29451 25764 16106 26394 23307 14093 3312 5106 5014" "Homer S" 1

echo
echo -e "\033[92mSimple test too many arg:\033[00m"
echo -e "\033[95mWanted :\033[00m"
echo "84"
echo -e "\033[31mGot :\033[00m"
./103cipher "Just because I don't care doesn't mean I don't understand." "Homer S" 0 "hello"
echo $?

echo
echo -e "\033[92mSimple test not enough arg:\033[00m"
echo -e "\033[95mWanted :\033[00m"
echo "84"
echo -e "\033[31mGot :\033[00m"
./103cipher "Just because I don't care doesn't mean I don't understand." "Homer S"
echo $?

echo
echo -e "\033[92mSimple test incorrect arg:\033[00m"
echo -e "\033[95mWanted :\033[00m"
echo "84"
echo -e "\033[31mGot :\033[00m"
./103cipher "Just because I don't care doesn't mean I don't understand." "Homer S" "a"
echo $?

echo
echo -e "\033[92mSimple test decryptage:\033[00m"
echo -e "\033[95mWanted :\033[00m"
echo "Key matrix:"; echo "-0.00	-0.01"; echo "0.008696	0.009478"; echo -e
echo -e "Decrypted message:";
echo -e "message a crypted"
echo -e "\033[31mGot :\033[00m"
./103cipher "21981 12535 24035 13225 20873 11155 14209 11615 13773 11155 22191 11385 24389 13915 22744 13340 12426 13110" "msd" 1

echo
echo -e "\033[92mSimple test cryptage small key:\033[00m"
echo -e "\033[95mWanted :\033[00m"
echo "Key matrix:"; echo "-0.00	-0.01"; echo "0.008696	0.009478"; echo -e
echo -e "Decrypted message:";
echo -e "message a crypted"
echo -e "\033[31mGot :\033[00m"
./103cipher "bonjour" "a" 0

echo
echo -e "\033[92mSimple test decryptage small key:\033[00m"
echo -e "\033[95mWanted :\033[00m"
echo "Key matrix:"; echo "-0.00	-0.01"; echo "0.008696	0.009478"; echo -e
echo -e "Decrypted message:";
echo -e "bonjour"
echo -e "\033[31mGot :\033[00m"
./103cipher "9506 10767 10670 10282 10767 11349 11058 0" "a" 1
