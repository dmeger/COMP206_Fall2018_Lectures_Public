days_of_week=" Su  M  Tu  W Th  F Sa"
echo $days_of_week

day_of_month=1
curr_position=3
echo -n "         "

while [[ $day_of_month -le 30 ]]
do
  printf " %02d" ${day_of_month}
  
  day_of_month=$((day_of_month+1))
  
  curr_position=$(($curr_position+1))
  
  if [[ $curr_position == 7 ]]
  then
     curr_position=1
     echo ""
  fi  
done

