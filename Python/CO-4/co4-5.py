#Create a class Publisher (name). Derive class Book from Publisher with attributes title and author. Derive class Python from Book with attributes price and #no_of_pages. Write	a program that displays information about a Python book. Use base class constructor invocation and method overriding.


class Publisher:
	def __init__(self,name):
		self.name = name
		
	def display():
		pass
		
		
class Book(Publisher):
	def __init__(self,name,title,author):
		super().__init__(name)
		self.title = title
		self.author = author
		
	def display():
		pass
		
		
class Python(Book):
	def __init__(self,name,title,author,price,no_page):
		super().__init__(name,title,author)
		self.price = price
		self.no_page = no_page
		
	def display(self):
		print("\n\n")
		print("Book Details")
		print("Title : ",self.title)
		print("Author : ",self.author)
		print("Publisher : ",self.name)
		print("Price : ",self.price)
		print("Number of Pages : ",self.no_page)
		
		
title= input("Enter Book Title : ")
author= input("Enter Author of Book : ")
name= input("Enter Book Publisher : ")
price= int(input("Enter Price of Book : "))
no_page= int(input("Enter Number of Pages : "))

B = Python(name,title,author,price,no_page)
B.display()



