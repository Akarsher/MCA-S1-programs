from graphics import rectangle,circle 
from Graphics.3D-graphics import cuboid,sphere 

#rectangle 
l=int(input("Enter Length of Rectangle : ")) 
b=int(input("Enter Breadth of Rectangle : ")) 
print("Area of Rectangle : ",rectangle.area(l,b)) 
print("Perimeter of Rectanlge : ",rectangle.perimeter(l,b),"\n") 

#circle 
r=int(input("Enter Radius : ")) 
print("Area of Circle : ",round(circle.area(r),2)) 
print("Perimeter of Circle : ",round(circle.perimeter(r),2),"\n") 

#cuboid 
x=int(input("Enter Length of Cuboid : ")) 
y=int(input("Enter Breadth of Cuboid : ")) 
z=int(input("Enter Height of Cuboid : ")) 
print("Surface Area of Cuboid : ",cuboid.surf(x,y,z)) 
print("Volume of Cuboid : ",cuboid.vol(x,y,z),"\n") 

#sphere 
s=int(input("Enter Radius : ")) 
print("Surface Area of Sphere : ",round(sphere.surf(s),2)) 
print("Volume of Sphere : ",round(sphere.vol(s),2),"\n")
