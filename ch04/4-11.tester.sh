tot=0
execute=$1
n=$2

for((i=0;i<$n;i++))
do
	echo -ne "\033[1K\r"
	echo -n "$i / $n"
	t=$(/usr/bin/time --format="%e" sudo $execute / 2>&1 > /dev/null)
	tot=$(echo "$tot + $t" | bc -l)
done

echo -e "\033[2K\r"
echo "$tot / $n" | bc -l 

