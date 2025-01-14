#Write a Python program to read specific columns of a given CSV file and print the content of the columns.

import csv
with open("example.csv",mode="r") as a:
	f= csv.reader(a)
	for row in f:
		print(row[1],row[2])
