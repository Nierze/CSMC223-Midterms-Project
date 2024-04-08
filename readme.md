# Instructions


## Syntax

\<OPERATION> \<REGISTER> \<VALUE>\\\<ADDRESS>

To define an address, start it with the character "*"


## Instructions

Instructions will be represented as a 5 digit decimal in memory for the sake of making it easier to understand. It will look like the following:

<br>

`0 0 0 0 0`

<br>

`0 0` MOV = **Loads** a value, value of an address, or an address into a register.<br>
`0 1` PUT = **Stores** the register into memory.<br>
`0 2` PRN = **Prints** the value of a register in the terminal.<br>
`0 3` OBL = **OBLITERATES** the contents of a register.<br>
`1 0` ADD = **Addition** operation.<br>
`1 1` SUB = **Subtraction** operation.<br>
`1 2` DIV = **Division** operation.<br>
`1 3` MUL = **Multiplication** operation.<br>
`1 4` MOD = **Modulo** operation.<br>
`2 1` GTN = **Greater than** operation. <br>
`2 2` LTN = **Less than** operation. <br>
`2 3` EQU = **Equals** operation <br>
`2 4` GEQ = **Greater than or Equals** operation. <br>
`2 5` LEQ = **Less than or Equals** operation. <br>
`2 6` XXX = **A little surprise**.


## Registers

### Data Registers
| 64bit Register | 32bit Register  | 16bit Register | 8bit Register | Purpose |
|----------|----------|----------|----------|--------------|
| RA1         |  RB1        |  RC1        |  RD1        |  General purpose register 1        |
| RA2         |  RB2        |  RC2        |  RD2        |  General purpose register 2        |
| RA3         |  RB3        |  RC3        |  RD3        |  General purpose register 3        |
| RA4         |  RB4        |  RC4        |  RD4        |  General purpose register 4        |

### Other Registers
| Register | Purpose | Meaning |
|----------|---------|--------|
|   CIR   | Holds the current instruction   | **C**urrent **I**struction **R**egister|
|   NIR   | Holds the address of the next instruction    | **N**ext **I**nstruction **R**egister|

<!-- |   CIA   | Holds the address of the current instruction   | **C**urrent **I**nstruction **A**ddress |
-->

### Sample Instructions 



\<OPERATION> \<REGISTER> \<VALUE>\\\<ADDRESS>

MOV RC1 95<br>
MOV RC2 96<br>
MOV RC3 #RC1<br>
ADD RC1 RC2<br>
ADD RC1 RC3<br>
MOV NIR 4<br>
MOV NIR 4<br>
PUT RC1 97<br>


![Diagram](./asssets/instructionSet.png)

Result:
Value of 97 will become 377