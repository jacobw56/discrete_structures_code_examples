# Some set stuff
# All of these set operations are pretty poor, O(n), but it's python, so meh.
# Also notice that the order of the output is (usually) neither the order of 
# the input, nor lexicographical order.
 
math_students = {"Imelda", "Dante", "Freyja"}
gym_students = {"Ahmad", "Robin", "Dante"}

print("\nMath students:")
print(math_students)
print("\nGym students:")
print(gym_students)
 
# Union using union()
# function
population = math_students.union(gym_students)
 
print("\nUnion using union() function")
print(population)
 
# Union using "|"
# operator
population = math_students|gym_students
 
print("\nUnion using '|' operator")
print(population)

# Intersection using
# intersection() function
both_classes = math_students.intersection(gym_students)
 
print("\nIntersection using intersection() function")
print(both_classes)
 
# Intersection using
# "&" operator
both_classes = math_students & gym_students
 
print("\nIntersection using '&' operator")
print(both_classes)

# Difference of two sets
# using difference() function
math_not_gym = math_students.difference(gym_students)
 
print("\nDifference of two sets using difference() function")
print(math_not_gym)
 
# Difference of two sets
# using '-' operator
math_not_gym = math_students - gym_students
 
print("\nDifference of two sets using '-' operator")
print(math_not_gym)