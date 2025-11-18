# Agent Guidelines for COP3514 C Programming Course

## Build & Test Commands
- **Compile**: `gcc -o a.out <filename>.c` (produces a.out executable)
- **Run single test**: `./a.out < ./tests/1.in` (redirect test input to program)
- **Run all tests**: `./try_project*` (shell script in project directory)
- **Compare output**: `diff -w ./tests/1.out ./1.out` (ignores whitespace differences)

## Code Style Guidelines
- **Imports**: Standard library headers first (`#include <stdio.h>`, `<stdlib.h>`, `<string.h>`, `<ctype.h>`)
- **Defines**: Use `#define` for constants (e.g., `#define MAX_STUDENTS 1000`)
- **Naming**: snake_case for functions/variables, UPPER_CASE for constants
- **Structs**: Define with typedef or use `struct student` syntax
- **Comments**: Block comments for function headers, inline for complex logic
- **Formatting**: K&R style braces, 2-space indentation
- **Error Handling**: Check malloc/fopen/scanf return values, print errors to stderr
- **Return Values**: `return 0` for success, `return 1` for errors in main
- **Pointers**: Use pointer arithmetic when required, array notation otherwise
- **Memory**: Always free malloc'd memory before program exit

## Project Structure
- Each weekXX/projectX_name/ contains: .c file, try_projectX_name script, tests/ directory
- Test files: N.in (input), N.out (expected output) where N is test number
