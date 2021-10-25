### README

##### Compile

In your bash terminal (Linux/Mac should be OKay Windows Users please use WSL), type 

`sh compile.sh`

If it doesn't work, you can try

```sh
gcc -o main *.c -Wall -Wextra -Werror -pedantic -lm
```

##### Usage specifications

`./main --help` or `./main -h` will print the help page.

`./main -c str` will evaluate the str. Notes: str should be in the form "\[operand1\]\[operator\]\[operand2\]"  

`./main - ` will evaluate an expression in interactive form.

`./main file` will evaluate expression in the file. (Pleasure ensure all expressions in the file are valid).

Notes: any form is not within specifications will be treated as undefined behavior!

##### Supporting calculations

* a+b

* a-b

* a*b

* a/b

* a^b

* alb= 
  $$
  log_a^b
  $$

* amb=
  $$
  a \bmod b
  $$
  

