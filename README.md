	char txt1[] = "with another text", txt2[] = "and other\n";

	_printf("Example2: Printing a simple text %s %s", txt1, txt2);

	return (0);
}
```
```
Example2: Printing a simple text with another text and other

```
### Print a integer number
```C
#include "holberton.h"

int main()
{
	int num1 = 6; 

	_printf("Example3: Printing a integer 6 as %d\n", num1);

	return (0);
}
```
```
Printing a integer 6 as 6

```
We uses another identify format for the integer numbers that is %d, the output shows that integer stored in the variable num1 replacing the identify format.
### Print a 1 decimal float number 
```C
int main()
{
	float num2 = 6.5; 

	_printf("Example4: Printing a float 6.5 as %.1f\n", num2);

	return (0);
}
```
```
Example4: Printing a float 6.5 as 6.5

```
For the float value, we uses a point character followed by 1, this number indicates to print only one decimal value and followed by f, the float value is in the second parameter variable.

### Print a char character
```C
int main()
{
	char hash = '#'; 

	_printf("Example5: Printing a hash character %c\n", hash);

	return (0);
}
```
```
Example5: Printing a hash character #

```
For the %c identy format, only We can use one character stored in a variable, no more, or a simple char caracter with simple quotes.

### Print a binary number
```C
int main()
{
	unsigned int num3 = 68; 

	_printf("Example6: The binary value of 68 is %b\n", num3);

	return (0);
}
```
```
Example6: The binary value of 68 is 1000100

```
This identy format doesn't have the original function, converts a unsigned integer value to a binary and print it replacing the %b characters.

### Print a hexadecimal number
```C
int main()
{
	unsigned int num4 = 980;

	_printf("Example7: Printing 980 as a hexadecimal %x, %X\n", num4, num4);

	return (0);
}
```
```
Example7: Printing 980 as a hexadecimal 3d4, 3D4

```
Print a unsigned integer as a hexadecimal number, with %x lowercase prints the base 16 letters in lowercase (abcdef) the %X uppercase prints in uppercase (ABCDEF).

## How My Code Works?
Everything we need for the _printf function to execute correctly, we will show below:

### Header file
We define a header file names ` "holberton.h"`  where puts the prototypes functions, include standard libraries to use and a struct that contains the different format types used in _printf function.

#### Standard libraries
For some proccess is neccessary use the standard libraries for example we use the write fuction across the `<unistd.h>` library.

#### Functions prototypes
Small functions are necessary for realize some operations with the characters found in the process and are defined with their respective name, data type of parameters.

#### cp_func struct
Contains a char parameter followed a function parameter who permits select the corresponding identify operators at the pointer position.

#### .c Source codes
Contains the logic to use in each step the _printf process, using the different functions.

### Contributors
- [Adriana Echeverry ](https://github.com/adri_er)
- [Cristian Pinzón ](https://github.com/faykris)
- [Jerson Pérez ](https://github.com/jperez90)

> Made with ❤ by  [Cristian Pinzón](https://github.com/faykris)。

![](https://www.holbertonschool.com/holberton-logo.png)
**Holberton School - Cohort 14 BOG**
*Colombia 2021*