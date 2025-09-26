# README

File statistics tool.

---

## What it does
For each file you pass, prints:
- **Filename**
- **Size in bytes**
- **Number of lines**
- **Number of words**

## How it works

1. Read the list of filenames from the command line.
2. For each filename:
   - Try to open with `fopen(name, "rb")`.
   - If opening fails → print `error: cannot open <name>` and continue to the next file.
   - If opened:
     - Initialize counters: `bytes = 0`, `lines = 0`, `words = 0`, `inword = 0`.
     - Read the file byte-by-byte using `fgetc`.
       - Always do `bytes++`.
       - If the byte is `'\n'` → `lines++`.
       - If the byte is **whitespace** (`' '`, `'\n'`, `'\t'`, `'\r'`, `'\v'`, `'\f'`):
         - If `inword == 1` → set `inword = 0` (we just left a word).
       - Else (non-space):
         - If `inword == 0` → `words++` and set `inword = 1` (we just entered a new word).
     - Close the file.
     - Print:
       ```
       Filename: <name>
       Size in bytes: <bytes>
       Number of lines: <lines>
       Number of words: <words>
       ```
   - Print a blank line between files.




## Build

```bash
gcc 6i2.c -o 6i2.o

Examples
    ./6i2.o  markdown.txt
    Output:  
    Filename: markdown.txt
    Size in bytes: 25
    Number of lines: 1
    Number of words: 6

```

Photo

[image info](photo/gcc.png) Build

[image info](photo/start.png) Start






