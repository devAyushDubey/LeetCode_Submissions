from importlib.resources import path
import os
from pathlib import Path
from typing import Any, List
from mdutils.mdutils import MdUtils
import requests


home = os.path.abspath(Path(__file__).parent)

submission_architecture = {"Week1": 1}

class Student:
    def __init__(self, name, githubID):
        self.name = name
        self.githubID = githubID
        self.solved = 0
        self.completed = True
        self.logs = ""
        self.fetch_img_url()

    def add_questions_solved(self, count):
        self.solved += count

    def __repr__(self) -> str:
        return f"""
            Name: {self.name}
            GitHubID: {self.githubID}
            Questions Solved: {self.solved}
            Logs: {self.logs}
        """

    def log_value(self, val):
        self.logs += val

    def fetch_img_url(self):
        resp = requests.get(url=f"https://api.github.com/users/{self.githubID}")
        data = resp.json()
        try:
            self.url = data["avatar_url"] + "&s=100"
        except KeyError:
            self.url = "https://avatars.githubusercontent.com/u/84376218?v=4&s=100"


def check_structure(path, student: Student):
    # print(path)
    folderName = os.listdir(path)
    folderNameLowered = [x.lower() for x in folderName]

    for key, value in submission_architecture.items():
        if key.lower() in folderNameLowered:
            solved = len(
                os.listdir(
                    os.path.join(path, folderName[folderNameLowered.index(key.lower())])
                )
            )
            if solved < value:
                student.completed = False

            student.add_questions_solved(solved)
            student.log_value(
                f"Completed `{solved}` with minimum `{value}` in `{key}`, "
            )
        else:
            student.completed = False
            student.log_value(f"`{key}` Folder not found, ")


def write_to_readme(filename, students_list):

    mdFile = MdUtils(file_name=filename, title="Coderspree")

    mdFile.new_paragraph(
        mdFile.new_inline_image(
            text="Status badge",
            path="https://github.com/InnogeeksOrganization/coderspree/actions/workflows/checkSubmission.yml/badge.svg",
        )
    )
    mdFile.new_line()

    mdFile.new_paragraph("Please visit the [Guide](./Guide/README.md)")

    mdFile.new_line()

    mdFile.new_paragraph(
        "Minimum problems to complete | "
        + "".join(
            f"**{key}**: `{value}` | " for key, value in submission_architecture.items()
        )
    )

    list_of_strings: List[Any] = ["No", "Profile", "Name", "Solved"]

    cols_count = len(list_of_strings)
    mdFile.new_line()

    count = 0
    for x in range(len(students_list)):
        student = students_list[x]
        count += 1
        list_of_strings.extend(
            [
                count,
                mdFile.new_inline_image(
                    text=student.name,
                    path=student.url,
                ),
                mdFile.new_inline_link(
                    link=f"https://github.com/{student.githubID}"
                    if student.githubID != "Invalid Foldername"
                    else "https://github.com/InnogeeksOrganization",
                    text=student.name,
                ),
                str(student.solved),
            ]
        )

    mdFile.new_header(level=1, title="Stats")
    mdFile.new_line()
    mdFile.new_table(
        columns=cols_count,
        rows=len(students_list) + 1,
        text=list_of_strings,
        text_align="center",
    )

    mdFile.create_md_file()



completed_student_list: List[Student] = []
incompleted_student_list: List[Student] = []

names1 = os.listdir(home)
names = [i for i in names1 if i not in ["README.md",".github","check_submissions.py",".git"]]
for folder in names:
    name = "Invalid Foldername"
    githubid = "Invalid Foldername"
    try:
        [githubid, name] = folder.split("_")
    except ValueError:
        print(folder, "is not correct")

#     for filename in os.listdir(os.path.join(home, name)):
#         name = "Invalid Foldername"
#         githubid = "Invalid Foldername"
        

    student = Student(name, githubid)
    check_structure(os.path.join(home, folder), student)
    if student.completed:
        completed_student_list.append(student)
    else:
        incompleted_student_list.append(student)

incompleted_student_list.sort(key=lambda x: x.solved, reverse=True)
completed_student_list.sort(key=lambda x: x.solved, reverse=True)
print(completed_student_list)
write_to_readme("README.md", completed_student_list)
