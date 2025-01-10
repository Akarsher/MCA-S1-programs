#Accept a file name from user and print extension of that

f=input("Enter a file name :")
ext=f.split('.')[-1] if '.' in f else "Not a file name\n" 
print("Extension : "+ext)

'''if '.' in f:
	res = f.split('.', 1)
	ext = res[1]
	print("Extension : "+ext)
else:
	printf("Not a file name\n")'''

