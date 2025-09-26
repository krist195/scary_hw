# README


Simple flags parser (`-v/--verbose`, `-h/--help`). Prints non-flag arguments.



## What it does

Pattern:
- `-v` / `--verbose` → turn on verbose messages  
- `-h` / `--help` → show usage and exit  
- any other `-something` → warning, ignored  
- everything that doesn’t start with `-` is printed line by line


## How it works (short)

1. If no args → show help and exit.  
2. For each argument:
   - if it starts with `-`:
     - `-v` or `--verbose` → set `verbose = 1`
     - `-h` or `--help` → print help and exit
     - otherwise → print warning
   - else (positional) → print it, and in verbose mode also print a `[VERBOSE]` line
3. At the end, if verbose is on → show how many positional items were processed.

---




## Build

```bash
gcc 5i1.c -o 5i1.o

Examples (verbose + Item)
    ./5i1.o -v file1.txt file2.txt
    Output:  
    [VERBOSE] Verbose mode enabled
    [VERBOSE] Processing argument: file1.txt
    file1.txt
    [VERBOSE] Processing argument: file2.txt
    file2.txt
    [VERBOSE] Done. Processed 2 item(s)

```

Photo

[image info](photo/gcc.png) Build

[image info](photo/start.png) Start






