# README

Number statistics (extension of “sum all numbers”).


## What it does

Reads a list of arguments, takes only valid integers, and prints:

- **Count** of valid numbers  
- **Sum**  
- **Average**  
- **Min** / **Max**  
- Prints a **warning** for every invalid value and skips it


## How it works 

1. For each argument, tries to parse it with `strtol`.  
2. If parsing fails → prints `Warning: invalid number '<arg>' — skipped`.  
3. If parsing succeeds → updates `sum`, `count`, `min`, `max`.  
4. If `count == 0` → prints `No valid numbers.`  
5. Otherwise prints Count, Sum, Average, Min, Max.





## Build

```bash
gcc calc.c -o calc

Examples
    ./3i3.o 12 12 5 2 6
    Output: 
    Count: 5
    Sum: 37
    Average: 7.40
    Min: 2
    Max: 12



Photo
[image info](photo/gcc.png) Build

[image info](photo/start.png) Start






