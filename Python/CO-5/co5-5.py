import csv

newdict=[{
		'Roll No' : '1', 'Name' : 'Messi',
		'Age' : '36', 'Course' : 'MCA'},
		{'Roll No' : '2', 'Name' : 'Neymar',
		'Age' : '32', 'Course' : 'MCA'},
		{'Roll No' : '3', 'Name' : 'Suarez',
		'Age' : '35', 'Course' : 'MCA'}]
field = ['Roll No','Name','Age','Course']

with open("msn.csv",mode="w") as a:
	writer = csv.DictWriter(a, fieldnames = field)
	writer.writeheader()
	writer.writerows(newdict)
	print("File Updated !")
	a.close()

with open("msn.csv",mode="r") as a:
	f= csv.reader(a)
	for row in f:
		print(row)
