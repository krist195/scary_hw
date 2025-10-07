# README

Flags with values (`-n`, `-o`, `-v`). Prints saved options and the remaining args.

## What it does

Pattern:
- `-n <number>` → remember a number (`n`)
- `-o <filename>` → remember an output file name (`out`)
- `-v` → turn on simple verbose messages (`verbose on`)
- anything else without `-` → treated as item and printed
- unknown flags → warning, ignored

## How it works

1. Walks over args from left to right.  
2. If `-n` → reads next token, parses it as integer; on bad value prints `err: bad number '...'`.  
3. If `-o` → reads next token as file name.  
4. If `-v` → enables verbose and prints `verbose on`.  
5. Non-flag tokens are collected as items.  
6. At the end prints:
   - `n=<value>` or `n=not set`
   - `out=<filename>` or `out=not set`
   - `items(K):` then each item on its own line; in verbose mode also `do: <item>` before it.

---

## Build
```bash
gcc 5i2.c -o 5i2.o



## Examples

./5i2.o input.txt
Output:
n=not set
out=not set
items(1):
input.txt


Photo

[image info](photo/gcc.png) Build

[image info](photo/start.png) Start