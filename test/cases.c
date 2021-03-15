#include "../holberton.h"

void print_all(const char * const format, ...);

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
    a = _printf("a=%s\%s\n","Hola", " M");
    b = printf("b=%s\%s\n","Hola", " M");
    (a != b)?printf("\a^^***** a != b ***** a=%d\tb=%d *****^^\n", a, b):a++;

    printf("<<<<<     -------%d-------     >>>>>\n", __LINE__);
    a= _printf("a=%sh%s\n","Hola Mundo"," 100");
    b= printf("b=%sh%s\n","Hola Mundo"," 100");
    (a != b)?printf("\a^^***** a != b ***** a=%d\tb=%d *****^^\n", a, b):a++;

    printf("<<<<<     -------%d-------     >>>>>\n", __LINE__);
    a= _printf("a=%sh%s %s\n","Hola Mundo"," 100", "10 \ns");
    b= printf("b=%sh%s %s\n","Hola Mundo"," 100", "10 \ns");
    (a != b)?printf("\a^^***** a != b ***** a=%d\tb=%d *****^^\n", a, b):a++;

    printf("<<<<<     -------%d-------     >>>>>\n", __LINE__);
    a= _printf("hola oo%    \n");
    b= printf("hola oo%    \n");
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
    a= _printf("hola %    \n");
    b= printf("hola %    \n");
    (a != b)?printf("\a^^***** a != b ***** a=%d\tb=%d *****^^\n", a, b):a++;

    printf("<<<<<     -------%d-------     >>>>>\n", __LINE__);
    a= _printf("%sdd\n","Hola Mundo");
    b= printf("%sdd\n","Hola Mundo");
    (a != b)?printf("\a^^***** a != b ***** a=%d\tb=%d *****^^\n", a, b):a++;

    printf("<<<<<     -------%d-------     >>>>>\n", __LINE__);
    a = _printf("\\a=\t%s%%h\%s\n","Hola", " Mundo");
    b = printf("\\b=\t%s%%h\%s\n","Hola", " Mundo");
     (a != b)?printf("\a^^***** a != b ***** a=%d\tb=%d *****^^\n", a, b):a++;

}

void test_char(void)
{
    int a=0, b=0;

    printf("<<<<<     -------%d-------     >>>>>\n", __LINE__);
	a = _printf("Character:[%c]\n", 'H');
    b = printf("Character:[%c]\n", 'H');
    (a != b)?printf("\a^^***** a != b ***** a=%d\tb=%d *****^^\n", a, b):a++;

    printf("<<<<<     -------%d-------     >>>>>\n", __LINE__);
	a = _printf("Character:[%c]\n", "H");
    b = printf("Character:[%c]\n", "H");
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
	_printf("Address:[%p]\n", addr);
    printf("Address:[%p]\n", addr);
}
void test_ui(){
	unsigned int ui = (unsigned int)INT_MAX + 1024;
	_printf("Unsigned:[%u]\n", ui);
    printf("Unsigned:[%u]\n", ui);
}
test_octal()
{
	unsigned int ui = (unsigned int)INT_MAX + 1024;
	_printf("Unsigned octal:[%o]\n", ui);
    printf("Unsigned octal:[%o]\n", ui);
}
test_hex()
{
	unsigned int ui = (unsigned int)INT_MAX + 1024;
     void *addr = (void *)0x7ffe637541f0;
	 _printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
}

test_custom_string()
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
