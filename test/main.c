#include "../holberton.h"

void test_string(void);
void test_char(void);
void test_int(void);
void test_address(void);
void test_ui();
void test_octal();
void test_hex();
void test_custom_string();


/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */
int main(void)
{
    /* s c d i u o xX p r */
    /*char txt[] = "hola\n";*/

<<<<<<< HEAD
    char whatTest[] = "pxX";
=======
    char whatTest[] = "o";
>>>>>>> f167bfc1137d3a00baf4fef151fadeda9e9e5355
    int i = 0;
    int len;
    int len2;

   while (whatTest[i])
    {
        switch(whatTest[i])
        {
            case 's':
                test_string();
                break;
            case 'c':
                test_char();
                break;
            case 'd':
	        case 'i':
		        test_int();
		        break;
            case 'p':
                test_address();
                break;
            case 'x':
            case 'X':
                test_hex();
                break;
            case 'S':
                test_custom_string();
                break;

	case 'u':
		test_ui();
		break;
	case 'o':
		test_octal();
		break;

        }
        i++;
    }

    /*   other test*/


    len = _printf("%r", "hola mundo en reversa\n");
    len2 = printf("%s", "hola mundo en reversa\n");
    _printf("Len:[%d]\n", len);
    printf("Len:[%d]\n", len2);
    len = _printf("%R", "Why did the chicken cross the road?\n");
    len2 = printf("%s", "Why did the chicken cross the road?\n");
        _printf("Len:[%d]\n", len);
    printf("Len:[%d]\n", len2);


/*
    len = _printf("Let's try to printf a simple sentence.\n");
    len2 = printf("Let's try to printf a simple sentence.\n");
    _printf("Length:[%d, %i]\n", len, len);
    printf("Length:[%d, %i]\n", len2, len2);
    _printf("Negative:[%d]\n", -762534);
    printf("Negative:[%d]\n", -762534);
    _printf("Character:[%c]\n", 'H');
    printf("Character:[%c]\n", 'H');
    _printf("String:[%s]\n", "I am a string !");
    printf("String:[%s]\n", "I am a string !");
    len = _printf("P1rcent:[% 0--+-++-+10.1%]\n");
    len2 = printf("p2rcent:[% 0--+-++-+10.1%]\n");
    len = _printf("P3rcent:[%   ");
    len2 = printf("p4rcent:[%   ");
    _printf("Len:[%d]\n", len);
    printf("Len:[%d]\n", len2);
    len = _printf("P5rcent:[%       0++-.9     ");
    len2 = printf("p6rcent:[%       0++-.9     ");
    _printf("Len:[%d]\n", len);
    printf("Len:[%d]\n", len2);*/

    return (0);
}
