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
	/* Main variables: */
	unsigned char loop1 = 1u;         /* First loop variable.                              */
	unsigned char has_error = 0u;     /* Has error in the program variable.                */
	int precision = 6;                /* Precision number variable.                        */
	double n[2] = {0.0, 0.0}; /* double numbers variable.                          */
	double result = 0.0;              /* Result number variable.                           */
	char sn[2][8192];                 /* String numbers string variable.                   */
	char operator[8192];              /* Operator variable.                                */
	char sprecision[8192];            /* Precision string variable.                        */

	/* Commands before main loop: */
	c_utils_clear_stdout();

	/* Main loop: */
	while(loop1 == 1u)
	{
		fputs("Calc: ", stdout);

		/* sn1 scan/code: */
		fscanf(stdin, "%8191s", *sn);

		if(strcmp(*sn, "exit") == 0 || strcmp(*sn, "break") == 0 || strcmp(*sn, "quit") == 0)
		{
			--loop1;
		}

		else if(strcmp(*sn, "help") == 0)
		{
			c_utils_clear_stdout();
			fputs("Syntax: <first number/action> <operator/action> <second number/action>.\n", stdout);
			fprintf(stdout, "Actions: [lr|ans] = last result (current: %f). [precision] = change precision, syntax: <precision> <precision new value>. [exit|break] or [Ctrl + C] = exit. [help] = show this help info.\n", result);
			fputs("Available operators: [ + | - | * | / | % | ** | // ].\n", stdout);
			fputs("Press any key to continue...", stdout);
			fflush(stdout);
			c_utils_clear_stdin();
			c_utils_scan_character();
			has_error = 1u;
		}

		else if(strcmp(*sn, "lr") == 0 || strcmp(*sn, "ans") == 0)
		{
			*n = result;
		}

		else if(strcmp(*sn, "pi") == 0 || strcmp(*sn, "π") == 0)
		{
			*n = C_UTILS_M_PI;
		}

		else if(strcmp(*sn, "precision") == 0)
		{
			fscanf(stdin, "%8191s", sprecision);
			precision = atoi(sprecision);
			fputs("GG Calculator: ", stdout);
			fscanf(stdin, "%8191s", *sn);
			*n = strtod(*sn, NULL);
		}

		else
		{
			*n = strtod(*sn, NULL);
		}

		/* Operator scan/code: */
		if(loop1 && has_error == 0u)
		{
			fscanf(stdin, "%8191s", operator);
		}

		if(strcmp(operator, "exit") == 0 || strcmp(operator, "break") == 0 || strcmp(operator, "quit") == 0)
		{
			--loop1;
		}

		else if(strcmp(operator, "precision") == 0)
		{
			fscanf(stdin, "%8191s", sprecision);
			precision = atoi(sprecision);
			fscanf(stdin, "%8191s", operator);
		}

		/* sn2 scan/code: */
		if(loop1 && has_error == 0u)
		{
			fscanf(stdin, "%8191s", *(sn + 1));
		}

		if(strcmp(*(sn + 1), "exit") == 0 || strcmp(*(sn + 1), "break") == 0 || strcmp(*(sn + 1), "quit") == 0)
		{
			--loop1;
		}

		else if(strcmp(*(sn + 1), "lr") == 0 || strcmp(*(sn + 1), "ans") == 0)
		{
			*(n + 1) = result;
		}

		else if(strcmp(*(sn + 1), "pi") == 0 || strcmp(*(sn + 1), "π") == 0)
		{
			*(n + 1) = C_UTILS_M_PI;
		}

		else if(strcmp(*(sn + 1), "precision") == 0)
		{
			fscanf(stdin, "%8191s", sprecision);
			precision = atoi(sprecision);
			fscanf(stdin, "%8191s", *(sn + 1));
			*(n + 1) = strtod(*(sn + 1), NULL);
		}

		else
		{
			*(n + 1) = strtod(*(sn + 1), NULL);
		}

		c_utils_clear_stdout();

		/* Calculate the results: */
		if(!has_error)
		{
			if(strcmp(operator, "+") == 0)
			{
				result = *n + *(n + 1);
				fprintf(stdout, "%.*f %c %.*f = %.*f\n", precision, *n, *operator, precision, *(n + 1), precision, result);
			}

			else if(strcmp(operator, "-") == 0)
			{
				result = *n - *(n + 1);
				fprintf(stdout, "%.*f %c %.*f = %.*f\n", precision, *n, *operator, precision, *(n + 1), precision, result);
			}

			else if(strcmp(operator, "*") == 0)
			{
				result = *n * *(n + 1);
				fprintf(stdout, "%.*f %c %.*f = %.*f\n", precision, *n, *operator, precision, *(n + 1), precision, result);
			}

			else if(strcmp(operator, "/") == 0 || strcmp(operator, "÷") == 0)
			{
				result = *n / *(n + 1);
				fprintf(stdout, "%.*f %c %.*f = %.*f\n", precision, *n, *operator, precision, *(n + 1), precision, result);
			}

			else if(strcmp(operator, "%") == 0)
			{
				result = fmod(*n, *(n + 1));
				fprintf(stdout, "%.*f %c %.*f = %.*f\n", precision, *n, *operator, precision, *(n + 1), precision, result);
			}

			else if(strcmp(operator, "^") == 0)
			{
				result = pow(*n, *(n + 1));
				fprintf(stdout, "%.*f %c %.*f = %.*f\n", precision, *n, *operator, precision, *(n + 1), precision, result);
			}

			else if(strcmp(operator, "√") == 0)
			{
				result = pow(*n, 1.0 / *(n + 1));
				fprintf(stdout, "%.*f %c %.*f = %.*f\n", precision, *n, *operator, precision, *(n + 1), precision, result);
			}

			else if(strcmp(operator, "**") == 0)
			{
				result = pow(*n, *(n + 1));
				fprintf(stdout, "%.*f %2s %.*f = %.*f\n", precision, *n, operator, precision, *(n + 1), precision, result);
			}

			else if(strcmp(operator, "//") == 0)
			{
				result = pow(*n, 1.0 / *(n + 1));
				fprintf(stdout, "%.*f %2s %.*f = %.*f\n", precision, *n, operator, precision, *(n + 1), precision, result);
			}

			else
			{
				fputs("Operation error!\n", stdout);
				fputs("Press any key to continue...\n", stdout);
				c_utils_scan_character();
				c_utils_clear_stdout();
			}
		}

		else
		{
			has_error = 0u;
		}
	}

	c_utils_clear_stdout();

	return 0;
}
