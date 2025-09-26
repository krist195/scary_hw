# README

This program opens each file you pass and prints its contents.




## What it does
- Takes one or more filenames as command-line arguments.
- Prints `Filename: <name>` before each file’s content.
- If a file cannot be opened, prints an error and continues with the next one.




## How it works

1. Read the list of filenames from the command line.
2. For each name:
   - Try `fopen(name, "rb")`.
   - If opening fails → print `error: cannot open <name>` and continue.
   - If it opens → print `Filename: <name>`.
   - Copy the file byte-by-byte with `fgetc` → `putchar`.
   - If the last byte wasn’t `\n`, print a final newline.
3. Print a blank line between files.





## Build

```bash
gcc 6i1.c -o 6i1.o

Examples 
    ./6i1.o ass.txt markdown.txt
    Output:  
    Filename: ass.txt
    ss

    Filename: markdown.txt
    aaaaaa mark down

```

Photo

[image info](photo/gcc.png) Build

[image info](photo/start.png) Start






