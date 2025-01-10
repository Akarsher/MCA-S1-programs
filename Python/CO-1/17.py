#Sort dictionary in ascending and descending order.

d={
	"Apple" : 10,
	"Strawberry": 40,
	"Mango" : 30
}

a = sorted(d.items())
b = sorted(d.items(),reverse=True)
print("Original :")
for i in d:
	print(i,":",d[i])

print("\n")
print("Ascending Order :",a)
print("Descending Order :",b)
