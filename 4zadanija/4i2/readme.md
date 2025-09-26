# README

String operations tool


## What it does

Takes an operation name and a list of strings, then prints the result

Pattern:
- `upper`   → make all letters uppercase  
- `lower`   → make all letters lowercase  
- `reverse` → reverse each string separately  
- `concat`  → print all strings glued together (no spaces)

## How it works (short)

1. Checks that there are at least 2 arguments: an operation and one string
2. Compares the operation with `upper/lower/reverse/concat` (own `str_eq`)
3. For each string calls the matching printer:
   - `print_upper` / `print_lower` convert characters by ASCII math (no `<ctype.h>`)
   - `print_reverse` uses `str_len` and prints from end to start
   - `print_raw` writes the string as is
4. For `upper/lower/reverse` adds a space between outputs
5. Prints a newline at the end




## Build

```bash
gcc 4i2.c -o 4i2.o

Examples
    ./4i2.o upper sdsdsdsd ola la la
    Output:  SDSDSDSD OLA LA LA

```

Photo

[image info](photo/gcc.png) Build

[image info](photo/start.png) Start






