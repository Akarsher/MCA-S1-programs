#Write a Python program to read a file line by line and store it into a list.

a = open("demo.txt","r")
b = [i.split() for i in a]
print(b)
a.close()
