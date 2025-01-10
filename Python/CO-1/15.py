#Print out all colors from color-list1 not contained in color-list2.
#create color list given as user input , use list comprehension

l1=[i for i in input("Enter colors in List 1 : ").split()]
l2=[i for i in input("Enter colors in List 2 : ").split()]

r=[i for i in l1 if i not in l2]

print("List is : ",r)
