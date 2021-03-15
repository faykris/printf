# README.md

![](https://pandao.github.io/editor.md/images/logos/editormd-logo-180x180.png)

![](https://img.shields.io/github/contributors/faykris/printf) ![](https://img.shields.io/github/last-commit/faykris/printf) ![](https://img.shields.io/github/commit-activity/m/faykris/printf)

### Description
- Function that prints argument(s) according to format

### Features
- Created in language C and only can be used in it;
- Some format controls are used;
- Based in the version written by David MacKenzie

**Table of Contents**

[TOC]

## How It Works?
In this function we define a first parameter where we have the data to print and it will be verified if it has any identifier operator, the other parameters will correspond to the identifier operators found in the first.
### _printf fuunction:
```C
int _printf(const char *format, ...);
```
This is the main function which contains all the execution processes connected to the secondary functions, it return a integer value corresponding a total string lenght and use a variadic constant char pointer.

Now, we will show the different use cases of this function: 
### Print a text Without variables
```C
#include "holberton.h"

int main()
{
	_printf("Example0: Printing a simple text\n");

	return (0);
}
```
```
Example0: Printing a simple text with

```
Only we needs to put a string value into double quotes without special characters as '%' because it used for identify other type formats

### Print some concatenated strings
```C
#include "holberton.h"

int main()
{
	_printf("Example1: Printing a simple text %s", "with another text\n");

	return (0);
}
```
```
Example1: Printing a simple text with another text

```
In this case, we uses a % with the 's' into the first parameter for indicate where it puts the data of the second parameter that corresponding a string value with format pointer.
### Only a text with variables
```C
#include "holberton.h"

int main()
{
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