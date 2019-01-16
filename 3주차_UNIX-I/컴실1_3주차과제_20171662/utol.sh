echo "working directory:"
check=0
read thisdir

if [ "$thisdir" != "" ]
then
	if [ -d "$thisdir" ] && [ -x "$thisdir" ]
	then
		cd $thisdir
		check=1
	else
		check=0
	fi
else
	check=1
fi

if [ $check -eq 0 ]
then
	echo "ERROR:No such directory exists."
else
	for filename in *
	do
		newfilename=""
		step=0
		while [ $step -lt ${#filename} ]
		do
			tmp=`echo ${filename:$step:1}`
			tmp=`echo $tmp | tr "[a-zA-Z]" "[A-Za-z]"`
			step=`expr $step + 1`
			newfilename+=$tmp
		done
		mv $filename $newfilename
	done
fi
