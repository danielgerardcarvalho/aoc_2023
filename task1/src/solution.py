file_path = 'data/aoc_task1.txt'
spelt_numbers = ['one', 'two', 'three', 'four', 'five', 'six', 'seven', 'eight', 'nine']

total = 0

with open(file_path, 'r') as file:

    for line in file:
        line = line.strip()

        number = ""
        temp = ""
        numero_save_list = []
        numero_index = -1
        
        # Find the word numbers
        for i in range(len(spelt_numbers)):
            runner = True
            numero_temp_list = []
            while numero_index < len(line) and runner:
                if numero_index == -1:
                    numero_index = line.find(spelt_numbers[i])
                else:
                    numero_index = line.find(spelt_numbers[i], numero_index)
                if numero_index == -1:
                    runner = False
                else:
                    numero_temp_list.append(numero_index)
                    numero_index+=1
            numero_save_list.append(numero_temp_list)

        # Building new line
        for i in range(len(numero_save_list)):
            for j in range(len(numero_save_list[i])):

                line = line[:numero_save_list[i][j]] + str(i+1) + line[numero_save_list[i][j]+1:]

        # Collect the numbers
        for char in line:
            if char.isdigit():
                temp += char

        if len(temp) == 1:
            number = temp + temp
        else:
            number = temp[0] + temp[len(temp)-1]

        total += int(number)
        print(total)