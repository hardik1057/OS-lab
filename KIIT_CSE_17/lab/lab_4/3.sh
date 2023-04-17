var=`timeout 1 find / -name $1 2> /dev/null`
cd $var
cnt=`find -name "*.txt" | wc -l`
find -name "*.txt" | cat > files.txt
cut -c 3- files.txt | cat > files1.txt
cnt=$((cnt + 2))
#echo $cnt
count=0
i=1
while [ $i -lt $cnt ]
do
file=`cat files1.txt | head -$i | tail -1`
if [ ! -s "$file" ]
then
count=$((count + 1))
rm $file
fi
i=$((i + 1))
done
echo $count "files deleted"


