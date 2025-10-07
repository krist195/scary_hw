# README

file operations tool (`./fileops <operation> <files...>`)

## What it does
- `copy <src> <dst>` → copies a file
- `merge <output> <input1> <input2> ...` → concatenates inputs into one file
- `split <input> <size>` → splits a file into parts of `<size>` bytes (`input.part1`, `input.part2`, ...)

## How it works (short)
1) read operation name  
2) if `copy` → open src (rb), dst (wb), copy chunks, print `copied src -> dst`  
3) if `merge` → open output (wb), for each input open (rb) and append chunks, print `merged N file(s) -> output`  
4) if `split` → open input (rb), write out parts of given size, print `split input into N part(s)`  
5) on open/write errors → print `error: ...` and continue/exit as in code  
6) unknown operation or bad args → print `Usage: ...`

---

## Build
```bash
gcc 6i4.c -o 6i4.o

Examples
Copy
./6i4.o copy a.txt b.txt
copied a.txt -> b.txt

merge
./6i4.o merge all.txt part1.txt part2.txt part3.txt
merged 3 file(s) -> all.txt

split
./6i4.o split big.bin 1048576
split big.bin into 5 part(s)