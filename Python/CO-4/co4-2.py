class Bank:
	#getting inputs
	def __init__(self):
		self.accno = int(input("Enter Account Number : "))
		self.name = input("Enter Name : ")
		self.acctype = input("Enter Account Type : ")
		self.balance = 0
	
	#deposite
	def deposite(self,depo):
		self.balance = self.balance + depo
		return self.balance
		
	
	#withdraw
	def withDraw(self,debit):
		if self.balance == 0:
			print("Account is empty !")
		elif self.balance < debit:
			print("Amount cannot be debitted!")
		else:
			self.balance = self.balance - debit
		return self.balance
			
	#display
	def displayDetails(self):
		print("Account Number : ",self.accno)
		print("Name of Holder : ",self.name)
		print("Account Type : ",self.acctype)
		print("Balance: ",self.balance,"\n")
		
	
#object creation	
customer1 = Bank()
print("\n1. Deposite\n2. Withdraw\n3. Display Account Details\n4. Exit\n")

while True:
	a = int(input("Enter Option : "))
	if a == 1:
		depo = int(input("Enter Amount to Deposite : "))
		b = customer1.deposite(depo)
		print("Current Balance : ",b,"\n")
		
	elif a == 2:
		debit = int(input("Enter Amount to Withdraw : "))
		b =customer1.withDraw(debit)
		print("Current Balance : ",b,"\n")
		
	elif a == 3:
		customer1.displayDetails()
		
	else:
		break

	
	
	
	
	
