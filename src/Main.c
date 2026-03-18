/* Importations: */
#include "C-Utils/cutils.h"
#include "C-Utils/mutils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


/* Main code: */
int main(void)
{
	/* Local variables: */
	unsigned char loop1 = 1;             /* First loop variable.                              */
	int precision = 6;                   /* Precision number variable.                        */
	double n[2] = {0, 0};                /* double numbers variable.                          */
	double result = 0.0;                 /* Result number variable.                           */
	char sn[2][8192];                    /* String numbers string variable.                   */
	char operator[8192];                 /* Operator variable.                                */
	char sprecision[8192];               /* Precision string variable.                        */

	/* Commands before main loop: */
	clear_stdout();

	/* Main loop: */
	while(loop1 == 1u)
	{
		fputs("Calc: ", stdout);
		scanf("%8191s", *(sn));

		if(strcmp(*(sn), "3.14159") == 0 || strcmp(*(sn), "3,14159") == 0)
		{
			clear_stdout();

			easter_egg_function();

			clear_stdout();

			fputs("GG Calculator: ", stdout);
			scanf("%8191s", *(sn));
			*(n) = strtod(*(sn), NULL);
		}

		else if(strcmp(*(sn), "exit") == 0 || strcmp(*(sn), "break") == 0)
		{
			--loop1;
		}

		else if(strcmp(*(sn), "help") == 0)
		{
			puts("Syntax: <first number/action> <operator/action> <second number/action>.");
			printf("Actions: \"lr\"|\"ans\" = last result (current: %f). \"precision\" = change precision, syntax: <precision> <precision new value>. \"exit/break\" or \"Ctrl + C\" = exit. \"help\" = show this help info.\n", result);
			fputs("GG Calculator: ", stdout);
		}

		else if(strcmp(*(sn), "lr") == 0 || strcmp(*(sn), "ans") == 0)
		{
			*(n) = result;
		}

		else if(strcmp(*(sn), "pi") == 0)
		{
			*(n) = M_PI;
		}

		else if(strcmp(*(sn), "precision") == 0)
		{
			scanf("%8191s", sprecision);
			precision = atoi(sprecision);
			fputs("GG Calculator: ", stdout);
			scanf("%8191s", *(sn));
			*(n) = strtod(*(sn), NULL);
		}

		else
		{
			*(n) = strtod(*(sn), NULL);
		}

		if(loop1)
		{
			scanf("%8191s", operator);
		}

		if(strcmp(operator, "exit") == 0 || strcmp(operator, "break") == 0)
		{
			--loop1;
		}

		else if(strcmp(operator, "precision") == 0)
		{
			scanf("%8191s", sprecision);
			precision = atoi(sprecision);
			scanf("%8191s", operator);
		}

		if(loop1)
		{
			scanf("%8191s", *(sn + 1));
		}

		if(strcmp(*(sn + 1), "exit") == 0 || strcmp(*(sn + 1), "break") == 0)
		{
			--loop1;
		}

		else if(strcmp(*(sn + 1), "lr") == 0 || strcmp(*(sn + 1), "ans") == 0)
		{
			*(n + 1) = result;
		}

		else if(strcmp(*(sn + 1), "pi") == 0)
		{
			*(n + 1) = M_PI;
		}

		else if(strcmp(*(sn + 1), "precision") == 0)
		{
			scanf("%8191s", sprecision);
			precision = atoi(sprecision);
			scanf("%8191s", *(sn + 1));
			*(n + 1) = strtod(*(sn + 1), NULL);
		}

		else
		{
			*(n + 1) = strtod(*(sn + 1), NULL);
		}

		clear_stdout();

		if(strcmp(operator, "+") == 0)
		{
			result = *(n) + *(n + 1);
			printf("%.*f %1s %.*f = %.*f\n", precision, *(n), operator, precision, *(n + 1), precision, result);
		}

		else if(strcmp(operator, "-") == 0)
		{
			result = *(n) - *(n + 1);
			printf("%.*f %1s %.*f = %.*f\n", precision, *(n), operator, precision, *(n + 1), precision, result);
		}

		else if(strcmp(operator, "*") == 0)
		{
			result = *(n) * *(n + 1);
			printf("%.*f %1s %.*f = %.*f\n", precision, *(n), operator, precision, *(n + 1), precision, result);
		}

		else if(strcmp(operator, "**") == 0)
		{
			result = pow(*(n), *(n + 1));
			printf("%.*f %1s %.*f = %.*f\n", precision, *(n), operator, precision, *(n + 1), precision, result);
		}

		else if(strcmp(operator, "/") == 0)
		{
			result = *(n) / *(n + 1);
			printf("%.*f %1s %.*f = %.*f\n", precision, *(n), operator, precision, *(n + 1), precision, result);
		}

		else if(strcmp(operator, "//") == 0)
		{
			result = pow(*(n), 1.0 / *(n + 1));
			printf("%.*f %1s %.*f = %.*f\n", precision, *(n), operator, precision, *(n + 1), precision, result);
		}

		else
		{
			puts("Operation error!");
			fputs("Press any key to continue...", stdout);
			scan_char();
			clear_stdout();
		}
	}

	clear_stdout();

	return 0;
}
