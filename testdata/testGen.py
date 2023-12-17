import random
import string

def generate_user_data_line(user_ids, num_additional_columns, line_length):
    user_id = random.choice(user_ids)
    
    # Use Unicode characters in the line
    user_id_str = f'U{user_id:05}'  # Assuming user_id is an integer
    
    # Joining additional columns with normal characters
    additional_columns = [''.join(random.choices(string.ascii_letters, k=8)) for _ in range(num_additional_columns)]
    line = f'{user_id_str} {" ".join(additional_columns)}'
    
    # Fill the remaining space with normal characters
    line += ' ' * (line_length - len(line)) + '\n'
    
    return line

def generate_text_file(file_path, num_lines, user_ids, num_additional_columns):
    line_length = 33  # You can adjust this based on your requirements
    with open(file_path, 'w', encoding='utf-8') as file:
        for _ in range(num_lines):
            line = generate_user_data_line(user_ids, num_additional_columns, line_length)
            file.write(line)
            print(repr(line))  # Print the representation of the generated line

# Generate text files with normal characters
for startIdx in range(0, 16):
    st = startIdx * 10
    ed = st + 10
    user_ids = [i for i in range(st, ed)]
    generate_text_file(f"file_{startIdx}.txt", 10000, user_ids, 3)
