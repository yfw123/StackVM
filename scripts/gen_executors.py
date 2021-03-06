import argparse
import os

OPCODE_PREFIX = "OP"
OPCODE_TEXT_SEPARATOR = "_"

def extract_raw_opcodes(file):
    file_clean = file.replace("\r", "").replace(",", "").replace(" ", "")
    
    lines = file_clean.split("\n")
    raw_opcodes = []

    for line in lines:
      try:
        comment_start = line.index('//')
        raw_opcode = line[:comment_start]

        if raw_opcode:
          raw_opcodes.append(raw_opcode)
      except:
        if line:
          raw_opcodes.append(line)

    return raw_opcodes

def extract_opcode_name(raw_opcode):
    opcode = raw_opcode.replace(OPCODE_PREFIX, "").replace(OPCODE_TEXT_SEPARATOR, "").replace("   ", "")

    return opcode.lower()

def create_signature(opcode):
    return f'STATE op_{opcode}(STACK* stack, STREAM* program, STATE vm)'

def create_definition(opcode):
    return create_signature(opcode) + ' { \n\n}\n'

def create_declaration(opcode):
    return create_signature(opcode) + ';'

def create_assignement(raw_opcode, opcode):
    return f'vm.executors[{raw_opcode}] = op_{opcode};'

def write_file(name, content):
    with open(name, 'w') as file:
        file.write('\n'.join(content))

def main():
    parser = argparse.ArgumentParser(description="Generate executor function signatures for opcodes")
    
    parser.add_argument('filename', help='The file which contains the list of the opcodes, separated by \\n')
    parser.add_argument('--declarations', action='store_true')
    parser.add_argument('--definitions', action='store_true')
    parser.add_argument('--assignments', action='store_true')

    args = parser.parse_args()

    filename_no_ext = os.path.splitext(args.filename)[0]

    with open(args.filename, 'r') as opcodes_file:
        data = opcodes_file.read()
        raw_opcodes = extract_raw_opcodes(data)
        opcodes = [extract_opcode_name(opcode) for opcode in raw_opcodes]

        if args.declarations:
            declarations = [create_declaration(opcode) for opcode in opcodes]
            write_file(f'{filename_no_ext}.declarations.h', declarations)
        
        if args.definitions:
            definitions = [create_definition(opcode) for opcode in opcodes]
            write_file(f'{filename_no_ext}.definitions.c', definitions)

        if args.assignments:
            assignements = [create_assignement(raw_opcode, opcode) for raw_opcode, opcode in zip(raw_opcodes, opcodes)]
            write_file(f'{filename_no_ext}.assignements.c', assignements)

if __name__ == "__main__":
    main()