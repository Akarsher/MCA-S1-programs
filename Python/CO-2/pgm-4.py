''' Generate a list of four digit numbers in a given range with all their digits even and the number is a perfect square.'''

import math  
  
def is_all_digits_even(num):     
    while num > 0:  
        digit = num % 10         
        if digit % 2 != 0:             
            return False         
        num //= 10  
    return True  
  
def even_digit_perfect_squares(start, end):     
    even_digit_squares = []    
    for num in range(start, end + 1):   
        if num >= 1000 and num <= 9999 and is_all_digits_even(num):  
            root = int(math.sqrt(num))             
            if root * root == num:                 
                even_digit_squares.append(num)    
    return even_digit_squares  
  
  
start = 1000  
end = 9999  
  
even_digit_squares = even_digit_perfect_squares(start, end)
print(even_digit_squares) 
