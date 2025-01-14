#Accept a list of words and return length of longest word.

s=[i for i in input("Enter some words :").split()]
print(len(max(s, key=len)))

