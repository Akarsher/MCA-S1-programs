#Add ‘ing’ at the end of a given string. If it already ends with ‘ing’, then add ‘ly’

s=input("Enter a string :")
a=s[-3:]

if a=='ing':
	print(s+'ly')
else:
	print(s+'ing')	
