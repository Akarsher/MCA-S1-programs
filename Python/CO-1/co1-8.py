#Get a string from an input string where all occurrences of first character replaced with ‘$’, except first character.

s=input("Enter a String :")
c=s[0]
n=s[1:]

if c in s:
	new=n.replace(c,'$')
	
print(c+new)
