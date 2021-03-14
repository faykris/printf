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

[TOCM]

[TOC]

## How It Works?
In this function we define a first parameter where we have the data to print and it will be verified if it has any identifier operator, the other parameters will correspond to the identifier operators found in the first.
Now, we will show the different use cases of this function: 
### Only a text Without variables
```C
#include "holberton.h"

int main()
{
	_printf("Example0: Printing a simple text\n");

	return (0);
}
```
### Print some concatenated strings
```C
#include "holberton.h"

int main()
{
	_printf("Example1: Printing a simple text %s", "with another text\n");

	return (0);
}
```
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
### print a integer number
```C
#include "holberton.h"

int main()
{
	int num1 = 6; 

	_printf("Example3: Printing a integer 6 as %d", num1);

	return (0);
}
```
```
Printing a integer 6 as 6
```
##How My Code Works?