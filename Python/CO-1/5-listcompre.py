#prompt the user for a list of integers.For all values >100 store 'Over' instead using list comprehension.

l=[int(num) for num in input("Enter list :").split()]
r=['Over' if i>100 else i for i in l]
print("List : ",r)
