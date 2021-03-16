#include "../holberton.h"

void test_string(void)
{
    int a=0, b=0;
    printf("<<<<<     -------%d-------     >>>>>\n", __LINE__);
	a = _printf("a=%sh\n","Hola Mundo");
    b = printf("b=%sh\n","Hola Mundo");
    (a != b)?printf("\a^^***** a != b ***** a=%d\tb=%d *****^^\n", a, b):a++;

    printf("<<<<<     -------%d-------     >>>>>\n", __LINE__);
    a = _printf("a=%sh%%s\n","Hola Mundo");
    b = printf("b=%sh%%s\n","Hola Mundo");
    (a != b)?printf("\a^^***** a != b ***** a=%d\tb=%d *****^^\n", a, b):a++;

    printf("<<<<<     -------%d-------     >>>>>\n", __LINE__);
    a = _printf("a=%ss\n","Hola", " M");
    b = printf("b=%ss\n","Hola", " M");
    (a != b)?printf("\a^^***** a != b ***** a=%d\tb=%d *****^^\n", a, b):a++;

    printf("<<<<<     -------%d-------     >>>>>\n", __LINE__);
    a= _printf("a=%s\t\a%s\n","Hola Mundo"," 100");
    b= printf("b=%s\t\a%s\n","Hola Mundo"," 100");
    (a != b)?printf("\a^^***** a != b ***** a=%d\tb=%d *****^^\n", a, b):a++;

    printf("<<<<<     -------%d-------     >>>>>\n", __LINE__);
    a= _printf("a=%sh%s %s\n","Hola Mundo"," 100", "10 \ns");
    b= printf("b=%sh%s %s\n","Hola Mundo"," 100", "10 \ns");
    (a != b)?printf("\a^^***** a != b ***** a=%d\tb=%d *****^^\n", a, b):a++;

    printf("<<<<<     -------%d-------     >>>>>\n", __LINE__);
    a= _printf("Hola oo%   -9 + -\n");
    b= printf("hola oo%  -9 + -\n");
    printf("-----\n");
    (a != b)?printf("\a^^***** a != b ***** a=%d\tb=%d *****^^\n", a, b):a++;

    printf("<<<<<     -------%d-------     >>>>>\n", __LINE__);
    a= _printf("% ñ s\n","Hola Mundo");
    b= printf("% ñ s\n","Hola Mundo");
     (a != b)?printf("\a^^***** a != b ***** a=%d\tb=%d *****^^\n", a, b):a++;

    printf("<<<<<     -------%d-------     >>>>>\n", __LINE__);
    a= _printf("hola %    ");
    b= printf("hola %    ");
    (a != b)?printf("\a^^***** a != b ***** a=%d\tb=%d *****^^\n", a, b):a++;

    printf("<<<<<     -------%d-------     >>>>>\n", __LINE__);
    a= _printf("%sdd\n","Hola Mundo");
    b= printf("%sdd\n","Hola Mundo");
    (a != b)?printf("\a^^***** a != b ***** a=%d\tb=%d *****^^\n", a, b):a++;

    printf("<<<<<     -------%d-------     >>>>>\n", __LINE__);
    a = _printf("\\a=\t%s%%h%s\n","Hola", " Mundo");
    b = printf("\\b=\t%s%%h%s\n","Hola", " Mundo");
     (a != b)?printf("\a^^***** a != b ***** a=%d\tb=%d *****^^\n", a, b):a++;

    printf("<<<<<     -------%d-------     >>>>>\n", __LINE__);
	a = _printf("%s\n", NULL);
    b = printf("%s\n", NULL);
    (a != b)?printf("\a^^***** a != b ***** a=%d\tb=%d *****^^\n", a, b):a++;

    printf("<<<<<     -------%d-------     >>>>>\n", __LINE__);
	a = _printf("%s\n", "");
    b = printf("%s\n", "");
    (a != b)?printf("\a^^***** a != b ***** a=%d\tb=%d *****^^\n", a, b):a++;

    printf("<<<<<     -------%d-------     >>>>>\n", __LINE__);
	a = _printf("", "");
    b = printf("", "");
    (a != b)?printf("\a^^***** a != b ***** a=%d\tb=%d *****^^\n", a, b):a++;

    printf("<<<<<     -------%d-------     >>>>>\n", __LINE__);
	a = _printf(NULL, "");
    b = printf(NULL, "");
    (a != b)?printf("\a^^***** a != b ***** a=%d\tb=%d *****^^\n", a, b):a++;

    _printf("String:[%     %]\n");
    printf("String:[%      %]\n");
     _printf("Percent:[% 0--+-++-+10.1%]\n");
    printf("Percent:[% 0--+-++-+10.1%]\n");
}

void test_char(void)
{
    int a=0, b=0;

    printf("<<<<<     -------%d-------     >>>>>\n", __LINE__);
	a = _printf("Character:[%c]\n", 'H');
    b = printf("Character:[%c]\n", 'H');
    (a != b)?printf("\a^^***** a != b ***** a=%d\tb=%d *****^^\n", a, b):a++;

    printf("<<<<<     -------%d-------     >>>>>\n", __LINE__);
	a = _printf("Character:[%c %c %s]\n", 46, 150, "h");
    b = printf("Character:[%c %c %s]\n", 46,150, "h");
    (a != b)?printf("\a^^***** a != b ***** a=%d\tb=%d *****^^\n", a, b):a++;

    printf("<<<<<     -------%d-------     >>>>>\n", __LINE__);
	a = _printf("%c\n", NULL);
    b = printf("%c\n", NULL);
    (a != b)?printf("\a^^***** a != b ***** a=%d\tb=%d *****^^\n", a, b):a++;

    printf("<<<<<     -------%d-------     >>>>>\n", __LINE__);
	a = _printf("%c\n", "");
    b = printf("%c\n", "");
    (a != b)?printf("\a^^***** a != b ***** a=%d\tb=%d *****^^\n", a, b):a++;
}
void test_int(void)
{
	int len = _printf("Percent:[%%]\n");
	int len2 = printf("Percent:[%%]\n");
	_printf("Length:[%i]\n", len);
	printf("Length:[%i]\n", len2);
	_printf("Negative:[%d]\n", -762534);
	printf("Negative:[%d]\n", -762534);
	_printf("Len:[%d]\n", len);
	printf("Len:[%d]\n", len2);
	_printf("Len:[%d]\n", 0);
	printf("Len:[%d]\n", 0);
}

void test_address(void)
{
	void * addr = (void *)0x7ffe637541f0;
int a, b;
        printf("<<<<<     -------%d-------     >>>>>\n", __LINE__);
	a = _printf("Address:[%p]\n", addr);
    b = printf("Address:[%p]\n", addr);
    (a != b)?printf("\a^^***** a != b ***** a=%d\tb=%d *****^^\n", a, b):a++;

    printf("<<<<<     -------%d-------     >>>>>\n", __LINE__);
	a = _printf("Address:[%p]\n", NULL);
    b = printf("Address:[%p]\n", NULL);
    (a != b)?printf("\a^^***** a != b ***** a=%d\tb=%d *****^^\n", a, b):a++;

    printf("<<<<<     -------%d-------     >>>>>\n", __LINE__);
	a = _printf("Address:[%p]\n", "");
    b = printf("Address:[%p]\n", "");
    (a != b)?printf("\a^^***** a != b ***** a=%d\tb=%d *****^^\n", a, b):a++;

}
void test_ui(){
	unsigned int ui = (unsigned int)INT_MAX + 1024;
	_printf("Unsigned:[%u]\n", ui);
    printf("Unsigned:[%u]\n", ui);
}
void test_octal()
{
	unsigned int ui = (unsigned int)INT_MAX + 1024;
	_printf("Unsigned octal:[%o]\n", ui);
    printf("Unsigned octal:[%o]\n", ui);
}
void test_hex()
{
	unsigned int ui = (unsigned int)INT_MAX + 1024;
int a, b;
    printf("<<<<<     -------%d-------     >>>>>\n", __LINE__);
    a =_printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    b = printf("unsigned hexadecimal:[%x, %X]\n", ui, ui);
    (a != b)?printf("\a^^***** a != b ***** a=%d\tb=%d *****^^\n", a, b):a++;
    printf("<<<<<     -------%d-------     >>>>>\n", __LINE__);
	 a =_printf("Unsigned hexadecimal:[%x, %X]\n", 0, 0);
     b = printf("unsigned hexadecimal:[%x, %X]\n",UINT_MAX, 1000);
    (a != b)?printf("\a^^***** a != b ***** a=%d\tb=%d *****^^\n", a, b):a++;
}

void test_custom_string()
{
    int a = 0, b = 0;
   /* printf("<<<<<     -------%d-------     >>>>>\n", __LINE__);
	a = _printf("Character:[%S]\n", "Hola\nMundo");
    b = printf("Character:[%s]\n", "Hola\nMundo");
    (a != b)?printf("\a^^***** a != b ***** a=%d\tb=%d *****^^\n", a, b):a++;


    printf("<<<<<     -------%d-------     >>>>>\n", __LINE__);
	a = _printf("Character:[%S]\n", "Hola\nMun\tdo");
    b = printf("Character:[%s]\n", "Hola\nMun\tdo");
    (a != b)?printf("\a^^***** a != b ***** a=%d\tb=%d *****^^\n", a, b):a++;*/

    printf("<<<<<     -------%d-------     >>>>>\n", __LINE__);
	a = _printf("Character:[%S]\n", "Hola \nMundo");
    b = printf("Character:[%s]\n", "Hola \nMundo");
    (a != b)?printf("\a^^***** a != b ***** a=%d\tb=%d *****^^\n", a, b):a++;
}
