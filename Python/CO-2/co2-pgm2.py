n = int(input("Enter size: "))  
  
a, b = 0, 1 
fibonacci = [] 
for i in range(n):     
    fibonacci.append(a)  
    a, b = b, a + b  
  
print(f"Fibonacci series : {fibonacci }") 
