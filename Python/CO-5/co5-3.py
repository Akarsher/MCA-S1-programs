#Write a Python program to read each row from a given csv file and print a list of strings.

import csv
with open("example.csv",mode ="r") as a:
	File = csv.reader(a)
	b = [i for i in File]
	print(b)
