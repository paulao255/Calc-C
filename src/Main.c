/* Importations: */
#include "C-Utils/cutils.h"
#include "C-Utils/mutils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


/* GG Calculator version variables: */
#define GG_CALCULATOR_FULL_VERSION 20260223L /* GG Calculator full version variable (2026/02/22). */

/* Main code: */
const int main(const int argc, const char **const argv)
{
	/* Local variables: */
	int loop1 = 1;                       /* First loop variable.                              */
	int precision = 6;                   /* Precision number variable.                        */
	double n[2];                         /* double numbers variable.                     */
	double result;                       /* Result number variable.                           */
	char sn[2][8192];                    /* String numbers string variable.                   */
	char operator[8192];                 /* Operator variable.                                */
	char sprecision[8192];               /* Precision string variable.                        */

	/* Commands before main loop: */
	clear_stdout();

	/* Main loop: */
	while(loop1 == 1)
	{
		fputs("Calc: ", stdout);
		scanf("%8191s", sn[0]);

		if(strcmp(sn[0], "3.14159") == 0 || strcmp(sn[0], "3,14159") == 0)
		{
			clear_stdout();
			easter_egg_function();
			clear_stdout();
			fputs("GG Calculator: ", stdout);
			scanf("%8191s", sn[0]);
			n[0] = strtod(sn[0], NULL);
		}

		else if(strcmp(sn[0], "exit") == 0 || strcmp(sn[0], "break") == 0)
		{
			--loop1;
			break;
		}

		else if(strcmp(sn[0], "help") == 0)
		{
			puts("Syntax: <first number/action> <operator/action> <second number/action>.");
			printf("Actions: \"lr\" = last result (current: %lf). \"precision\" = change precision, syntax: <precision> <precision new value>. \"exit/break\" or \"Ctrl + C\" = exit. \"help\" = show this help info.\n", result);
			fputs("GG Calculator: ", stdout);
			scanf("%8191s", sn[0]);
			n[0] = strtod(sn[0], NULL);
		}

		else if(strcmp(sn[0], "lr") == 0)
		{
			n[0] = result;
		}

		else if(strcmp(sn[0], "pi") == 0)
		{
			n[0] = PI_D;
		}

		else if(strcmp(sn[0], "precision") == 0)
		{
			scanf("%8191s", sprecision);
			precision = atoi(sprecision);
			fputs("GG Calculator: ", stdout);
			scanf("%8191s", sn[0]);
			n[0] = strtod(sn[0], NULL);
		}

		else
		{
			n[0] = strtod(sn[0], NULL);
		}

		scanf("%8191s", operator);

		if(strcmp(operator, "exit") == 0 || strcmp(operator, "break") == 0)
		{
			--loop1;
			break;
		}

		else if(strcmp(operator, "precision") == 0)
		{
			scanf("%8191s", sprecision);
			precision = atoi(sprecision);
			scanf("%8191s", operator);
		}

		scanf("%8191s", sn[1]);

		if(strcmp(sn[1], "exit") == 0 || strcmp(sn[1], "break") == 0)
		{
			--loop1;
			break;
		}

		else if(strcmp(sn[1], "lr") == 0)
		{
			n[1] = result;
		}

		else if(strcmp(sn[1], "pi") == 0)
		{
			n[1] = PI_D;
		}

		else if(strcmp(sn[1], "precision") == 0)
		{
			scanf("%8191s", sprecision);
			precision = atoi(sprecision);
			scanf("%8191s", sn[1]);
			n[1] = strtod(sn[1], NULL);
		}

		else
		{
			n[1] = strtod(sn[1], NULL);
		}

		clear_stdout();

		if(strcmp(operator, "+") == 0)
		{
			result = n[0] + n[1];
			printf("%.*lf %1s %.*lf = %.*lf\n", precision, n[0], operator, precision, n[1], precision, result);
		}

		else if(strcmp(operator, "-") == 0)
		{
			result = n[0] - n[1];
			printf("%.*lf %1s %.*lf = %.*lf\n", precision, n[0], operator, precision, n[1], precision, result);
		}

		else if(strcmp(operator, "*") == 0)
		{
			result = n[0] * n[1];
			printf("%.*lf %1s %.*lf = %.*lf\n", precision, n[0], operator, precision, n[1], precision, result);
		}

		else if(strcmp(operator, "**") == 0)
		{
			result = pow(n[0], n[1]);
			printf("%.*lf %1s %.*lf = %.*lf\n", precision, n[0], operator, precision, n[1], precision, result);
		}

		else if(strcmp(operator, "/") == 0)
		{
			result = n[0] / n[1];
			printf("%.*lf %1s %.*lf = %.*lf\n", precision, n[0], operator, precision, n[1], precision, result);
		}

		else if(strcmp(operator, "//") == 0)
		{
			result = pow(n[0], 1.0L / n[1]);
			printf("%.*lf %1s %.*lf = %.*lf\n", precision, n[0], operator, precision, n[1], precision, result);
		}

		else
		{
			puts("Operation error!");
			fputs("Press any key to continue...", stdout);
			scan_char();
			clear_stdout();
		}
	}

	return 0;
}
