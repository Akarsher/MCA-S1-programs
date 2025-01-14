#Create a class Time with private attributes hour, minute and second. Overload ‘+’ operator to find sum of 2 time.
class Time:
	#getting values attributes
	def __init__(self,__hr,__min,__sec):
		self.__hr=__hr
		self.__min=__min
		self.__sec=__sec
		self.normalize()

		
	#normalize time
	def normalize(self):
		if self.__sec >= 60:
			self.__min += self.__sec // 60
			self.__sec = self.__sec % 60
		if self.__min >= 60:
			self.__hr += self.__min // 60
			self.__min = self.__min % 60
		
	#adding time
	def __add__(self,obj2):
		n_hr = self.__hr + obj2.__hr
		n_min = self.__min + obj2.__min
		n_sec = self.__sec + obj2.__sec
		return Time(n_hr,n_min,n_sec)
		
	def __str__(self):
		return f"{self.__hr:02}:{self.__min:02}:{self.__sec:02}"
		
		
	
	
hr=int(input("Enter Hour : "))
mint=int(input("Enter Minute : "))
sec=int(input("Enter Second : "))
t1 = Time(hr,mint,sec)
print("Time : ",hr,":",mint,":",sec,"\n")
print()

hr1=int(input("Enter Hour : "))
mint1=int(input("Enter Minute : "))
sec1=int(input("Enter Second : "))
t2 = Time(hr1,mint1,sec1)
print("Time : ",hr1,":",mint1,":",sec1,"\n")
print()


#calling add
t3 = t1 + t2
print("Sum of Time : ",t3)
