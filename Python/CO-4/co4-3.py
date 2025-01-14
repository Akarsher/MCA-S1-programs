class Rectangle():
	def __init__(self,l,b):
		self.__l=l
		self.__b=b
		
		
	def area(self):
		return self.__l*self.__b
		
	def __lt__(self,obj2):
		print("Area of Rectangle 1 : ",self.area(),"\n")
		print("Area of Rectangle 2 : ",obj2.area(),"\n")
		if self.area() < obj2.area():
			print("Rectangle 2 has bigger area\n")
		elif  self.area() > obj2.area():
			print("Rectangle 1 has bigger area\n")
		else:
			print("Same Area\n")
		


l=int(input("Enter Length of Rectangle 1 : "))
b=int(input("Enter Breadth of Rectangle 1: "))
r1 = Rectangle(l,b)
print()

p=int(input("Enter Length of Rectangle 2 : "))
q=int(input("Enter Breadth of Rectangle 2: "))
r2 = Rectangle(p,q)
print()


#comparison
r1 < r2
