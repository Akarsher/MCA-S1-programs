class Rectangle():   
  def __init__(self,l,b):  
     self.l=l      
     self.b=b   
  def area(self):  
     return self.l*self.b  
      
   def perimeter(self):  
     return 2*(self.l+self.b)  
  
l=int(input("Enter Length of Rectangle 1 : "))    
b=int(input("Enter Breadth of Rectangle 1: "))  
rect1 = Rectangle(l,b)  
a1=rect1.area()  
print("Area of Rectangle 1 is : ",a1)  
print("Perimeter of Rectangle 1 is : ",rect1.perimeter(),"\n")  
  
p=int(input("Enter Length of Rectangle 2 : "))    
q=int(input("Enter Breadth of Rectangle 2: "))  
rect2 = Rectangle(p,q)  
a2=rect2.area()  
print("Area of Rectangle 2 is : ",a2)  
print("Perimeter of Rectangle 2 is : ",rect2.peri(),"\n")  
  
  
if a1 > a2:  
  print("Rectangle 1 has bigger area")  
elif a1 < a2:      
  print("Rectangle 2 has bigger area")   
 else:  
    print("Both Rectangle has Same Area ")
