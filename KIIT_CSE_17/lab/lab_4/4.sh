echo "Parent process id- $1"
cnt=`ps -ef | grep -w $1 | wc -l`
ps -ef | grep -w $1>file.txt
i=1
j=0
while [ $i -lt $cnt ]
do 
ppid=`cat file.txt | head -$i |  tail -1 | tr -s " " | cut -d " " -f 3` 
if [ $ppid -eq $1 ]
then 
cat file.txt | head -$i | tail -1
j=`expr $j + 1`
fi 
i=`expr $i + 1`
done   
echo "no of child processes: $j"
