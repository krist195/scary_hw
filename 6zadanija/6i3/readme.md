# README

file search tool (`./filesearch [-i] <word> <files...>`)

## What it does
- looks for a word in many files
- prints `filename:line_number:matching_line`
- `-i` makes it case-insensitive

## How it works
1) if `-i` first → enable case-insensitive  
2) read `<word>`  
3) for each file:
   - open and read line by line
   - if line contains the word → print `file:line:line_text`
   - keep original line text (adds `\n` if needed)
4) if a file can’t be opened → prints `error: cannot open <name>`

---

## Build
```bash
gcc 6i3.c -o 6i3.o



# Examples
./6i3.o cat a.txt b.txt

a.txt:3:I have a cat
b.txt:1:catapult is fast


Photo

[image info](photo/gcc.png) Build

[image info](photo/start.png) Start


