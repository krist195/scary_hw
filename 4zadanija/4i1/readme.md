# README

String length counter.


## What it does

Takes several strings as arguments, prints each string with its length, then prints the total character count.


## How it works

1. Checks that at least one string is provided.
2. For each `argv[i]` (starting from `i = 1`) calls `strlen` to get its length.
3. Prints `<string>: <length>` for each item.
4. Sums all lengths into `total` and prints `Total: <sum>`.




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

[image info](photo/gcc.png) Build

[image info](photo/start.png) Start






