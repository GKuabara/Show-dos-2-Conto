import json

file = 'questions.txt'

curr_section = ''

with open(file, 'r') as f:
    lines = f.readlines()

questions = {}
line_idx = 0
while True:
    if lines[line_idx] == '### Fácil\n':
        questions['Easy'] = {}
        curr_section = 'Easy'
        line_idx += 1
    
    elif lines[line_idx] == '### Médio\n':
        print("Entrou aqui")
        questions['Medium'] = {}
        curr_section = 'Medium'
        line_idx += 1

    elif lines[line_idx] == '### Difícil\n': 
        questions['Hard'] = {}
        curr_section = 'Hard'
        line_idx += 1
    
    elif lines[line_idx] == '### Answers\n':
        break

    if lines[line_idx] == '\n':
        line_idx += 1

    question = lines[line_idx].strip()
    line_idx += 1

    answer_a = " ".join(lines[line_idx].split()[1:]).lower()
    line_idx += 1

    answer_b = " ".join(lines[line_idx].split()[1:]).lower()
    line_idx += 1

    answer_c = " ".join(lines[line_idx].split()[1:]).lower()
    line_idx += 1

    answer_d = " ".join(lines[line_idx].split()[1:]).lower()
    line_idx += 1

    questions[curr_section][question] = {'a': answer_a,'b': answer_b,'c': answer_c,'d': answer_d, 'answer': '0'}

    
    line_idx += 1

line_idx += 2
for sector, item in questions.items():
    for key, it in questions[sector].items():
        print(lines[line_idx].strip())
        questions[sector][key]['answer'] = chr(ord(lines[line_idx].strip()) - ord('1') + ord('a'))
        line_idx += 1

json_object = json.dumps(questions, indent = 4).encode('utf8')

with open("questions.json", 'w') as outfile:
    outfile.write(json_object.decode('utf8'))