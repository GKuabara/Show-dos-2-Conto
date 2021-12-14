import json

file = 'questions.txt'

curr_section = ''

with open(file, 'r') as f:
    lines = f.readlines()

question_idx = 0
questions = {}
line_idx = 0
while True:
    if lines[line_idx] == '### Fácil\n':
        curr_section = 'Easy'
        line_idx += 1
    
    elif lines[line_idx] == '### Médio\n':
        print("Entrou aqui")
        curr_section = 'Medium'
        line_idx += 1

    elif lines[line_idx] == '### Difícil\n': 
        curr_section = 'Hard'
        line_idx += 1
    
    elif lines[line_idx] == '### Answers\n':
        break

    if lines[line_idx] == '\n':
        line_idx += 1

    question = lines[line_idx].strip()
    line_idx += 1

    answers = []

    answers.append(" ".join(lines[line_idx].split()[1:]).lower())
    line_idx += 1
    
    answers.append(" ".join(lines[line_idx].split()[1:]).lower())
    line_idx += 1

    answers.append(" ".join(lines[line_idx].split()[1:]).lower())
    line_idx += 1

    answers.append(" ".join(lines[line_idx].split()[1:]).lower())
    line_idx += 1

    questions[question_idx] = {"question" : question, "options": answers, "answer": -1, "level": curr_section}

    line_idx += 1
    question_idx += 1

line_idx += 2
for question_id in questions.keys():
    questions[question_id]["answer"] = ord(lines[line_idx].strip()) - ord('1')
    line_idx += 1

with open("questions.json", 'w', encoding="utf8") as outfile:
    json.dump(questions, outfile, indent = 4,  ensure_ascii=False)