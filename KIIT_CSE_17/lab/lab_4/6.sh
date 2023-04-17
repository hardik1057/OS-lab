filename=meeting_saved_chat.txt 
echo "Extracting from = $filename"
if [ -f $filename ]
then 
echo "File present"
sed -ri `/\s+$/s///` $filename
cat $filename | rev | cut -d " " -f1 | rev | sort > result.txt 
cat result.txt 
echo -n "No of students present-  "
cat result.txt | wc -l 
else 
echo "File not present in your system"
fi
