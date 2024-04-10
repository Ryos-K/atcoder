# setup.py : create directory and files for atcoder contest

problem_count_dict = {
    "ABC": 6,
    "ARC": 6,
    "AGC": 4
}

print("1. ABC")
print("2. ARC")
print("3. AGC")

contest_type = ""
while True:
    contest_type = input("Enter contest type: ")
    if contest_type in ["1", "2", "3"]:
        break

contest_type_names = ["ABC", "ARC", "AGC"]
contest_type_name = contest_type_names[int(contest_type) - 1]

contest_number = input("Enter contest number: ")
contest_number = contest_number.zfill(3)
contest_name = contest_type_name.lower() + contest_number

problem_count = input("Enter the number of problems: ")
if problem_count == "":
    problem_count = problem_count_dict[contest_type_name]
else:
    problem_count = int(problem_count)

import os
import shutil

path = os.getcwd() + "/" + contest_type_name + "/" + contest_name

if not os.path.exists(path):
    os.makedirs(path)
    print("Directory created")

for i in range(0, problem_count):
    problem_name = chr(ord('A') + i)
    problem_path = path + "/" + problem_name + ".cpp"
    if os.path.exists(problem_path):
        print("File already exists")
    else:
        shutil.copyfile("template.cpp", problem_path)

print("Files created")