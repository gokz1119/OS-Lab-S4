#! /bin/bash
echo -n "Enter names: "
read -a names
echo "Name is ${names[0]} , ${names[1]}"
read -p 'Text Input:' text
echo "Text: $text"
read -sp "Secret stuff: " secret
echo
echo "Secrets: $secret"
