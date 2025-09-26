# README

Word search (case-insensitive).


## What it does

Searches for a word inside each text argument and prints which arguments contain it (case-insensitive).

Example pattern:
./search cat “I have a cat” “Dogs are nice” “My CAT is black”

## How it works

1. Checks that there is a search word and at least one text.
2. For each text, scans all positions and compares characters with the word.
3. Comparison is case-insensitive via simple ASCII conversion (no extra libraries).
4. If a match is found, prints `arg N: <text>` (N = argument index starting from 1 for the first text).
5. If nothing matched, prints `no matches`.





## Build

```bash
gcc 4i3.c -o 4i3.o 

Examples
    ./4i3.o casino i love casino i Marka
    Output:  arg 3: casino

```

Photo

[image info](photo/gcc.png) Build

[image info](photo/start.png) Start






