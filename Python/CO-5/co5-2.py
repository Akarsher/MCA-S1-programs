#Python program to copy odd lines of one file to other

a = open("demo.txt","r")
b = open("demo2.txt", "w")

reada = a.readlines()
for i in range(0, len(reada)):
	if i % 2 == 0:
		b.write(reada[i])
print("File Copied!\n")
a.close()
b.close()
