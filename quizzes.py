#Generate 35 random state capital quizzes on the desktop

import os
import random

capitals = [('Alabama', 'Montgomery'), ('Alaska', 'Juneau'), ('Arizona', 'Phoenix'), ('Arkansas', 'Little Rock'),
            ('California', 'Sacramento'), ('Colorado', 'Denver'), ('Connecticut', 'Hartford'), ('Delaware', 'Dover'),
            ('Florida', 'Tallahassee'), ('Georgia', 'Atlanta'), ('Hawaii', 'Honolulu'), ('Idaho', 'Boise'),
            ('Illinois', 'Springfield'),
            ('Indiana', 'Indianapolis'), ('Iowa', 'Des Moines'), ('Kansas', 'Topeka'), ('Kentucky', 'Frankfort'),
            ('Louisiana', 'Baton Rouge'),
            ('Maine', 'Augusta'), ('Maryland', 'Annapolis'), ('Massachusetts', 'Boston'), ('Michigan', 'Lansing'),
            ('Minnesota', 'Saint Paul'),
            ('Mississippi', 'Jackson'), ('Missouri', 'Jefferson City'), ('Montana', 'Helena'), ('Nebraska', 'Lincoln'),
            ('Nevada', 'Carson City'),
            ('New Hampshire', 'Concord'), ('New Jersey', 'Trenton'), ('New Mexico', 'Santa Fe'), ('New York', 'Albany'),
            ('North Carolina', 'Raleigh'),
            ('North Dakota', 'Bismarck'), ('Ohio', 'Columbus'), ('Oklahoma', 'Oklahoma City'), ('Oregon', 'Salem'),
            ('Pennsylvania', 'Harrisburg'),
            ('Rhode Island', 'Providence'), ('South Carolina', 'Columbia'), ('South Dakota', 'Pierre'),
            ('Tennessee', 'Nashville'), ('Texas', 'Austin'),
            ('Utah', 'Salt Lake City'), ('Vermont', 'Montpelier'), ('Virginia', 'Richmond'), ('Washington', 'Olympia'),
            ('West Virginia', 'Charleston'),
            ('Wisconsin', 'Madison'), ('Wyoming', 'Cheyenne')]

if os.path.exists('C:\\Users\\moore\\Desktop\\quizzes'):
    os.chdir('C:\\Users\\moore\\Desktop\\quizzes')
else:
    os.mkdir('C:\\Users\\moore\\Desktop\\quizzes')
    os.chdir('C:\\Users\\moore\\Desktop\\quizzes')

for i in range(35):

    file1 = open('Quiz' + str(i+1) + '.txt', 'w')
    file2 = open('Answers' + str(i+1) + '.txt', 'w')

    used = []
    for j in range(50):
        question = ''
        answer = ''

        entries = []
        while len(entries) < 4:
            entry = random.choice(capitals)
            if len(entries) == 0 and entry in used:
                continue
            elif len(entries) == 0 and entry not in used:
                used.append(entry)
                entries.append(entry)
            else:
                if entry not in entries:
                    entries.append(entry)
            if len(entries) == 4:
                question += '\n#' + str(j+1) + ' What is the capital of ' + entries[0][0] + '\n'
                answer += '#' + str(j+1) + ' ' + entries[0][1] + '\n'

                random.shuffle(entries)

                question += 'a. ' + entries[0][1] + '\n'
                question += 'b. ' + entries[1][1] + '\n'
                question += 'c. ' + entries[2][1] + '\n'
                question += 'd. ' + entries[3][1] + '\n'

        file1.write(question)
        file2.write(answer)

    file1.close()
    file2.close()
