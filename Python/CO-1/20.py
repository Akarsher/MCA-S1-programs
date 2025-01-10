#From a list of integers, create a list removing even numbers.

l1=[int(i) for i in input("Enter integers : ").split()]

l2=[i for i in l1 if i%2!=0]

print("Result : ",l2)
