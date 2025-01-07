cy = int(input("Enter Current Year: ")) 
ey = int(input("Enter Ending Year: ")) 
print("Leap years are:") 
for i in range(cy, ey + 1):   
  if (i % 400 == 0) or (i % 4 == 0 and i % 100 != 0):   
    print(i, end=" ")
