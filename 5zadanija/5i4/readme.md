# README

config override (`--port/-p`, `--host/-h`, `--debug/-d`)

## What it does
- has defaults: port=8080, host=localhost, debug=off
- flags change them:
  - `--port <num>` or `-p <num>`
  - `--host <addr>` or `-h <addr>`
  - `--debug` or `-d`
- prints final config: `host=...`, `port=...`, `debug=on/off`

## How it works
1) starts with defaults  
2) walks over args  
3) `--port/-p` takes next token, parses number  
4) `--host/-h` takes next token as text  
5) `--debug/-d` turns debug on  
6) unknown flag -> `warn: unknown flag '...'`  
7) prints final values

---

## Build
```bash
gcc 5i4.c -o 5i4.o


## Examples
./5i4.o --port 3000 --host 0.0.0.0 -d 

host=localhost
port=8080
debug=off