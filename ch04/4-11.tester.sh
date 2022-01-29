start_directory=$1
iteration_num=$2

function exec_and_time(){
	tot=0
	for((i=0;i<$iteration_num;i++))
	do
		echo -ne "\033[1K\r"
		echo -n "$i / $iteration_num"
		t=$(/usr/bin/time --format="%e" $1 $start_directory 2>&1 > /dev/null)
		tot=$(echo "$tot + $t" | bc -l)
	done

	echo -e "\033[2K\r"
	echo "$tot / $iteration_num" | bc -l 
}
chdir_ver="./4-11"
origin_ver="./4-11.origin"

exec_and_time $chdir_ver
exec_and_time $origin_ver



