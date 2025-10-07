# README

mixed args parser (`-v`, `-n <num>`, `-o <file>`)

## What it does
- flags can be anywhere
- many files and many flags
- unknown flags -> error

## How it works
1) goes left to right  
2) `-v` turns verbose  
3) `-n <num>` saves number  
4) `-o <file>` saves output name  
5) tokens without `-` are files  
6) unknown `-something` -> prints error and exits  
7) prints final config and list of files

---

## Build
```bash
gcc 5i3.c -o 5i3.o




## Examples

./5i3.o file1 -v file2 -n 10 -o out.txt file3

[VERBOSE] verbose on
[VERBOSE] file: file1
[VERBOSE] file: file2
[VERBOSE] n=10
[VERBOSE] out=out.txt
[VERBOSE] file: file3
Verbose: ON
Number: 10
Output: out.txt
Files (3):
  file1
  file2
  file3



[image info](photo/gcc.png) Build

[image info](photo/start.png) Start