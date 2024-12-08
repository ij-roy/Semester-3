'''
Question 3. Create a list of student record by taking the student name, rollno and total marks (out of 100) as
input. Each record should be saved as a tuple element inside the list.
    1. Display the details of the student, who has the maximum marks
    2. Add an element to each student record corresponding to their Rank. The rank for student 
    with highest marks is 1, and with lowest marks is N. Display the student details in ascending 
    order of their ranks.
'''

num_students = int(input("Enter the number of students: "))
student_records = []

for _ in range(num_students):
    name = input("Enter student name: ")
    roll_no = input("Enter roll number: ")
    total_marks = int(input("Enter total marks (out of 100): "))
    student_records.append((name, roll_no, total_marks))

max_marks_student = max(student_records, key=lambda x: x[2])
print("\nStudent with the maximum marks:")
print("Name:", max_marks_student[0])
print("Roll No:", max_marks_student[1])
print("Total Marks:", max_marks_student[2])

sorted_records = sorted(student_records, key=lambda x: x[2], reverse=True)

ranked_records = [(record[0], record[1], record[2], rank + 1) for rank, record in enumerate(sorted_records)]

print("\nStudent details in ascending order of their ranks:")
for record in sorted(ranked_records, key=lambda x: x[3]):  # Sort by rank
    print("Name:", record[0], ", Roll No:", record[1], ", Total Marks:", record[2], ", Rank:", record[3])
    