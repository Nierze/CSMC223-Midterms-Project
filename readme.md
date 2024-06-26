# Instructions
## Submitted by: Melchor Filippe S. Bulanon

## How to use

Compile and run main.cpp. In main.cpp, you can change the inputfile to the input file you want.
Please check the sample instructions down below on how to correctly write instructions for this project.


## Syntax

`<OPERATION> <REGISTER> <VALUE>\<ADDRESS>`

WARNING: There should be no empty spaces between every lines of instructions. <br>

so supposed you have the instructions <br>

`MOV RA1 [69]` <br>
`MOV RA2 [420]` <br>
`MOV RA3 [70]` <br>
`ADD RA1 RA2` <br>

it should not be

`MOV RA1 [69]` <br>
`MOV RA2 [420]` <br> <br>
`MOV RA3 [70]` <br>
`ADD RA1 RA2` <br>

else it will result in an error. <br>

To define a value instead of an address, supposed you want to store the number `69` in memory address `50`, we will use `[]`.
Example: `PUT 50 [69]`
<br>

## Instructions

Instructions will be represented as a 2 digit Hexadecimal in memory for the sake of making it easier to understand. It will look like the following:
<br>
<hr>

`0 1` MOV = **Loads** a value, value of an address, or an address into a register. Cannot be used to load values into memory.
<br>

Usages: <br>
`MOV RA1 [4]` &nbsp; &nbsp; // Loads the value 4 into the RA1 reguster <br>
`MOV RA1 4` &nbsp; &nbsp; // Loads the value in memory address 4 <br>
`MOV RA1 RB1` &nbsp; &nbsp; // Loads the value of RB1 into RA1 <br>
<br>
<hr>

`0 2` PUT = **Stores** the register into memory. Cannot be used to store values into registers. 
<br>

Usages: <br>
Supposed `RA1` and `RA2` contains the values 70 and 420 respectively. <br>

`PUT 69 RB1` &nbsp; &nbsp; // Stores 420 in memory location 69 <br> 
`PUT RA1 RA2` &nbsp; &nbsp; // Stores 420 in memory location 70 since RA1 contains the value 70 <br>

<hr>

`0 3` PRN = **Prints** the value of a register in the terminal.<br>

Usages: <br>
`PRN RA1 0 ` &nbsp; &nbsp; // Prints the value of RA1 into terminal. Ignore 0. <br>
<hr>

`0 4` OBL = **OBLITERATES** the contents of a register or a memmory location back to `0`.<br>

Usages: <br>
`OBL 0 RA1` &nbsp; &nbsp; // Resets the contents of RA1 to 0 <br>
`OBL 0 70` &nbsp; &nbsp; // Deletes the contents in the memory location 70 <br>

<hr>

`1 1` ADD = **Addition** operation.<br>
`1 2` SUB = **Subtraction** operation.<br>
`1 3` DIV = **Division** operation.<br>
`1 4` MUL = **Multiplication** operation.<br>
`1 5` MOD = **Modulo** operation.<br>

Usage: <br>
`ADD RA1 [4]` &nbsp; &nbsp; // Adds the 4 to the value of RA1 and stores it in RA1<br>
`SUB RA1 RA2` &nbsp; &nbsp; // Subtracts the value RA2 to the value of RA1 and stores it in RA1<br>
`MUL RA2 RA1` &nbsp; &nbsp; // Multiplies the value of RA1 to the value of RA2 and stores it in RA2 <br>
`DIV RA1 [2]` &nbsp; &nbsp; // Divides the value of RA1 by 2 and stores it in RA1 <br>
`MOD RA1 [2]` &nbsp; &nbsp; // Get the modulo of RA1 Mod 2 and stores it in RA1 <br>

<hr>

`2 1` GTN = Jump if **Greater than** operation. <br>
`2 2` LTN = Jump if **Less than** operation. <br>
`2 3` EQU = Jump if **Equals** operation <br>
`2 4` GEQ = Jump if **Greater than or Equals** operation. <br>
`2 5` LEQ = Jump if **Less than or Equals** operation. <br>
`2 6` CMP = Compares 2 registers and prepares them for the comparison operators <br>
`3 0` XXX = **A little surprise**. <br>
`4 4` END =  **Ends** the program.

## Memory 
Values/Instructions stored in memory are stored as a 10 digit Hexadecimal. The memory cell can only access memory address 0 - 80 where each cell has 5 bytes. So all in all the memory will have a total of `400 bytes`. A single cell CANNOT contain a value greater than `65,535`.

![Diagram](./asssets/bitsExplanation.png)

**A**: First 2 digits signifies what operation the CPU must do. A value of `0 0` means that that particular memory location stores a value and not an instruction hence the first 5 digit will always be `0 0 0 0 0`.

<br>

**B**: The next 2 digits signifies the register than the operation the CPU will use.

<br>

The last 6 digits signifies the argument of the the operation. Each part of this 6 digits have its meaning.

* **C**: the 5th digit will only either be a `1` or a `0`. A `1` means that the remaining 4 digits will be a numerical value. A `0` signifies that the number stored in the next 4 digits is an address in the memory.

* **D**: The next 4 digits, as stated in **C** will contain either the value or the address that will be used as an argument for the operation dictated by **A**.

* **E**: This last digit will represent whether the numerical data in **D** is a positive or negative number. A value of `1` indicates that **D** is a negative number and a value of `0` indicates that it is a positive number.

Example: Supposed you want to load the value `69` into the **RA1** register and add it to the contents of the **RB1** register and store it into the memory location `44`.

Supposed RB1 contains the value `420`.

`MOV RA1 [69]` <br>
`ADD RB1 RA1` <br>
`PUT 44 RB1` <br>

That would look like this in memory:

`0`  : `0197100450`<br>
`1`  : `1196000970`<br>
`2`  : `022C100960`<br>
... <br>
`44` : `0000001E90`<br>


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
|   CIR   | Holds the current instruction   | **C**urrent **I**nstruction **R**egister|
|   NIR   | Holds the address of the next instruction    | **N**ext **I**nstruction **R**egister|
|   CM1   | Holds the value to be compared   | **C**o**M**pare **1**|
|   CM2   | Holds the value to be compared   | **C**o**M**pare **2**|

<!-- |   CIA   | Holds the address of the current instruction   | **C**urrent **I**nstruction **A**ddress |
-->

## Sample Instructions 

`<OPERATION> <REGISTER> <VALUE>\<ADDRESS>`

### Add the 69 and 420 and place it in memory location 69

`MOV RA1 [69]` <br>
`MOV RA2 [420]` <br>
`ADD RA1 RA2` <br>
`PUT 69 RA1` <br>

Result:
Value of 69 will become 489 <br>

### Put the numbers 1 - 10 in memory location 51 - 60 using a loop structure
`MOV RA1 [0]` <br>
`MOV RB1 [51]` <br>
`MOV RC1 [1]` <br>
`MOV RD1 [10]` <br>
`ADD RA1 RC1` <br>
`PUT RB1 RA1` <br>
`ADD RB1 RC1` <br>
`CMP RD1 RA1` <br>
`GTN CMP 4` <br>
`END 0 0` <br>

Result: 
The memory locations 51, 52, 53 .... 60 will have the values 1, 2, 3 .... 10 respectively


### Assembly FizzBuzz
Loop through the numbers 0 - 10 and place the results in memory location 50 - 60. if the number is an even number, put the value `0` in the memory location, if it is odd, put `1` otherwise.

`MOV RA1 [60]`<br>
`MOV RB1 [0]`<br>
`MOV RD1 [50]`<br>
`MOD RB1 [2]`<br>
`MOV RB2 [1]`<br>
`CMP RB1 RB2`<br>
`EQU CMP 8`<br>
`JMP 0 10`<br>
`PUT RD1 [1]` <br>
`JMP 0 11`<br>
`PUT RD1 [0]` <br>
`ADD RB1 [1]`<br>
`ADD RD1 [1]`<br>
`CMP RA1 RD1`<br>
`GEQ CMP 3`<br>
`END 0 0`<br>


### Get the average of 3 numbers
Supposed the 3 numbers are `69`, `420`, `70` and store it in memory location `69`

`MOV RA1 [69]` <br>
`MOV RA2 [420]` <br>
`MOV RA3 [70]` <br>
`ADD RA1 RA2` <br>
`ADD RA1 RA3` <br>
`DIV RA1 [3]` <br>
`PUT 69 RA1` <br>
`END 0 0` <br>

Result: `186` will be stored in memory location `69` as hexadecimal. (Note, this project is designed not to handle floating point values.) 

<br>



### Print the multiplication of 7 up until 70

Prints the multiplication of 7 - 70 and store it in memory location 41 - 50.

<br>

`MOV RA1 [7]` <br>
`MOV RA2 [41]` <br>
`MOV RB2 [51]` <br>
`PUT RA2 RA1` <br>
`ADD RA1 [7]` <br>
`ADD RA2 [1]` <br>
`CMP RA2 RB2` <br>
`LTN CMP 3` <br>
`END 0 0`<br>

