cnt=0
for var in *.sh
do
if [ -x $var ]
then
cnt=$((cnt + 1))
echo "$var"
fi
done
echo "Total number of executable files are $cnt"

