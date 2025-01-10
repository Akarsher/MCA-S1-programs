#Program to find the factorial of a number
def fact(a):
	f=1
	for i in range(1,a+1):
		f=f*i
	return f
	
	
def factorial(a):
	if a==0:
		return 1
	return a * factorial(a-1)

a=int(input("Enter a number :"))
print("Factorial of ",a," is ",factorial(a))
