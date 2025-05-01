# Getting into Linux Operating System

### Getting along with linux commands in terminal window

#### Commands and uses

1. ls - list the files of the current directory
2. ls -a - list all files including the hidden files 
3. touch file_name.exe - creating a new file
4. vi file_name.exe - using vi editor to edit the file
5. extension I used in the above file - 
    * tsv = tab separated file
    * csv = comma seperated file
    * txt = text file
6. After editing the file press ctrl + C to quit the editor 
7. Then type `:wq!` to save and quit

## Handling .tsv (Tab seperated files)

➤ `cut -d$'\t' -f1 file_name.tsv` -**print only the first column**

In the above command - 
  * `cut` -> Extract sections from each line of a file.
  * `-d$'\t'` -> Sets the delimitor `-d` to a tab Character (`\t`). 
  * `-f1` -> Tells `cut` to extract the first field.

➤ `cut -d$'\t' -f3 newfile.tsv` - **prints the 3rd column from each line of newfile.tsv**

➤ `head -n2 newfile.tsv` - **prints the first 2 lines of newfile.tsv**

➤ `tail -n2 newfile.tsv` -  **prints the last 2 lines of newfile.tsv**

➤ `head -n8 newfile.tsv | tail -n1` - **prints the 8th line of newfile.tsv**
*  `|` (pipe) → sends that output as input to the next command.

➤ `gawk '{print'} newfile.tsv` - **print the whole contents of newfile.tsv**

➤ `gawk '{print NF; exit'} newfile.tsv` - **print the number of columns (fields) in the first line of newfile.tsv and then stop processing.**

➤ `gawk '{print $3'} newfile.tsv` - **print the third column from each line of newfile.tsv**

➤ `wc -l newfile.tsv` -**count and print the number of lines in newfile.tsv**

➤ `head -n5 newfile.tsv | grep 'dd'` - **print the lines from the first 5 lines of newfile.tsv that contain the substring "dd"**

➤ `head -n7 newfile.tsv | grep '6'` - **print the lines from the first 7 lines of newfile.tsv that contain the number "6"**


## Handling .csv (Comma seperated files)

👉 Shows lines containing "Engineering" (case-sensitive) 
`grep 'Engineering' csv.csv`


👉 Displays the first 5 lines of csv.csv
`head -5 csv.csv`

👉 Displays the last 3 lines of csv.csv
`tail -3 csv.csv`

👉 Prints the 3rd column (field) from each row, using , as the delimiter
`gawk -F',' '{print $3}' csv.csv`

👉 Also prints the 3rd column using cut (same result as above).
`cut -d, -f3 csv.csv`

👉 Prints the 7th line of csv.csv
`head -n7 csv.csv | tail -n1`

👉 Extracts the 4th column and sorts it alphabetically.
`gawk -F',' '{print $4}' csv.csv | sort`

👉 Appends the 2nd and 3rd columns (comma-separated) from csv.csv into a new file xyz.csv
`gawk  -F, '{print  $2","$3}' csv.csv >> xyz.csv`

👉 Views the contents of xyz.csv page by page
`more xyz.csv`

👉 Sorts csv.csv by 3rd column (numerically, in reverse order).
`sort -t',' -k3,3nr csv.csv`

👉 Sorts by the 4th column, numerically, in ascending order
`sort -t',' -k4,4n csv.csv`

👉 Sorts by the 4th column, reverse (descending) order, lexicographically (not numerically unless column contains only numbers).
`sort -t',' -k4,4 -r csv.csv`

👉 Sorts first by 5th column, then by 4th column, both in reverse order.
`sort -t',' -k5,5 -k4,4 -r csv.csv`