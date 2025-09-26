# README

String length counter.


## What it does

Takes several strings as arguments, prints each string with its length, then prints the total character count.

## How it works

1) Checks there is at least one argument and that the total count (without the program name) is **odd**: `1, 3, 5, ...`.  
2) Parses the first number as the initial result.  
3) Walks through pairs: **operator** then **number**.  
4) Validates the operator is a single char from `+-*/`.  
5) Parses the next number and applies the operation to the running result.  
6) Prints `Res: <value>` at the end.



## Build

```bash
gcc 4i1.c -o 4i.o

Examples
    ./4i1.o yo baranka gnu
    Output: 
        yo: 2
        baranka: 7
        gnu: 3
        Total: 12

```

Photo

[image info](4zadanija/4i1/photo/gcc.png) Build

[image info](4zadanija/4i1/photo/start.png) Start






