## What it does
Operators: `+  -  *  /`
Uses `strtol` and stops on invalid data
Prints errors for bad pattern, bad number, bad operator, and division by zero

---

## How it works

1) Checks there is at least one argument and that the total count (without the program name) is **odd**: `1, 3, 5, ...`.  
2) Parses the first number as the initial result.  
3) Walks through pairs: **operator** then **number**.  
4) Validates the operator is a single char from `+-*/`.  
5) Parses the next number and applies the operation to the running result.  
6) Prints `Res: <value>` at the end.



## Build

```bash
gcc calc.c -o calc

Examples
    ./3i2 10 + 5 + 4 + 5 - 2 + 5 - 2
    Output: Result: 25



Photo
[image info](photo/gcc.png) Build

[image info](photo/start.png) Start






