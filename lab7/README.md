### README

##### Compile

In your bash terminal (Linux/Mac should be OKay Windows Users please use WSL), type 

`./compile.sh` 

If it doesn't work, you can try

```sh
gcc -o main *.c -Wall -Wextra -Werror -pedantic -lm
```

##### Run

```shell
./main
```

##### Sample result

```text
./main
URU LOSE POR
FRA LOSE CRO
POR WIN CRO
BRA WIN SWE
BEL WIN POL
BRA LOSE BEL
POR LOSE BEL
ESP WIN RUS
ARG WIN DEN
ESP LOSE ARG
GER WIN SUI
COL LOSE ENG
GER WIN ENG
ARG LOSE GER
BEL LOSE GER
GER WIN the world cup!
```



##### Usage specifications

input filename restrict: `l7_input.txt`

output file name restrict: `l7_output.txt`
