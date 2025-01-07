#a
l=[int(i) for i in input("Enter list of integers : ").split()] 
p=[i for i in l if i>=0] 
print("Positive Integers : ",p) 
#b
l=[int(i) for i in input("Enter List Elements: ").split()] 
l1=[i*i for i in l] 
print(l1) 
#c
word=input("Enter a word : ") 
vowels = "aeiouAEIOU" 
vowel_list = [i for i in word if i in vowels] 
print("Vowels in ",word," : ",vowel_list) 
