#Write lambda functions to find area of square, rectangle and triangle.

#Square
s=int(input("Enter Side of Square :"))
areaSq=lambda s:s*s
print("Area of Square = ",areaSq(s),"\n")


#Rectangle
l=int(input("Enter Length of Rectangle :"))
b=int(input("Enter Breadth of Rectangle :"))
areaRect= lambda l, b : l * b
print("Area of Rectangle = ",areaRect(l,b),"\n")


#Triangle
b=int(input("Enter Base of Triangle :"))
h=int(input("Enter Height of Triangle :"))
areaTri=lambda b,h: .5*b*h
print("Area of Triangle = ",areaTri(b,h),"\n")


