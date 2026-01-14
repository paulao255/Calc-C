/* Include guard: */
#ifndef GG_CALCULATOR_C
#define GG_CALCULATOR_C

/* Importations: */
#include "C-Utils/cutils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define __USE_GNU
#include <math.h>


/* GG Calculator version variables: */
#define GG_CALCULATOR_FULL_VERSION  210  /* GG Calculator full version variable (2.1.0). */
#define GG_CALCULATOR_MAJOR_VERSION 2    /* GG Calculator major version variable (2).    */
#define GG_CALCULATOR_MINOR_VERSION 1    /* GG Calculator minor version variable (1).    */
#define GG_CALCULATOR_PATCH_VERSION 0    /* GG Calculator patch version variable (0).    */

/* Main code: */
int main(void)
{
	/* Local variables: */
	char loop1 = 1;                  /* First loop variable.                         */
	int precision = 6;               /* Precision number variable.                   */
	long double n[2] = {0.0L, 0.0L}; /* Long double numbers variable.                */
	long double result = 0;          /* Result number variable.                      */
	char sn[2][8192] = {"", ""};     /* String numbers string variable.              */
	char operator[8192] = "";        /* Operator variable.                           */
	char sprecision[8192] = "";      /* Precision string variable.                   */

	/* Commands before main loop: */
	clear_terminal();

	/* Main loop: */
	while(loop1 == 1)
	{
		fputs("GG Calculator: ", stdout);
		scanf("%8191s", sn[0]);

		if(strcmp(sn[0], "3.14159") == 0 || strcmp(sn[0], "3,14159") == 0)
		{
			clear_terminal();
			easter_egg_function();
			clear_terminal();
			fputs("GG Calculator: ", stdout);
			scanf("%8191s", sn[0]);
			n[0] = strtold(sn[0], NULL);
		}

		else if(strcmp(sn[0], "exit") == 0 || strcmp(sn[0], "break") == 0)
		{
			--loop1;
			break;
		}

		else if(strcmp(sn[0], "help") == 0)
		{
			puts("Syntax: <first number/action> <operator/action> <second number/action>.");
			printf("Actions: \"lr\" = last result (current: %Lf). \"precision\" = change precision, syntax: <precision> <precision new value>. \"exit/break\" or \"Ctrl + C\" = exit. \"help\" = show this help info.\n", result);
			fputs("GG Calculator: ", stdout);
			scanf("%8191s", sn[0]);
			n[0] = strtold(sn[0], NULL);
		}

		else if(strcmp(sn[0], "lr") == 0)
		{
			n[0] = result;
		}

		else if(strcmp(sn[0], "pi") == 0)
		{
			n[0] = M_PIl;
		}

		else if(strcmp(sn[0], "precision") == 0)
		{
			scanf("%8191s", sprecision);
			precision = atoi(sprecision);
			fputs("GG Calculator: ", stdout);
			scanf("%8191s", sn[0]);
			n[0] = strtold(sn[0], NULL);
		}

		else
		{
			n[0] = strtold(sn[0], NULL);
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
			n[1] = M_PIl;
		}

		else if(strcmp(sn[1], "precision") == 0)
		{
			scanf("%8191s", sprecision);
			precision = atoi(sprecision);
			scanf("%8191s", sn[1]);
			n[1] = strtold(sn[1], NULL);
		}

		else
		{
			n[1] = strtold(sn[1], NULL);
		}

		clear_terminal();

		if(strcmp(operator, "+") == 0)
		{
			result = n[0] + n[1];
			printf("%.*Lf %1s %.*Lf = %.*Lf\n", precision, n[0], operator, precision, n[1], precision, result);
		}

		else if(strcmp(operator, "-") == 0)
		{
			result = n[0] - n[1];
			printf("%.*Lf %1s %.*Lf = %.*Lf\n", precision, n[0], operator, precision, n[1], precision, result);
		}

		else if(strcmp(operator, "*") == 0)
		{
			result = n[0] * n[1];
			printf("%.*Lf %1s %.*Lf = %.*Lf\n", precision, n[0], operator, precision, n[1], precision, result);
		}

		else if(strcmp(operator, "**") == 0)
		{
			result = powl(n[0], n[1]);
			printf("%.*Lf %1s %.*Lf = %.*Lf\n", precision, n[0], operator, precision, n[1], precision, result);
		}

		else if(strcmp(operator, "/") == 0)
		{
			result = n[0] / n[1];
			printf("%.*Lf %1s %.*Lf = %.*Lf\n", precision, n[0], operator, precision, n[1], precision, result);
		}

		else if(strcmp(operator, "//") == 0)
		{
			result = powl(n[0], 1.0L / n[1]);
			printf("%.*Lf %1s %.*Lf = %.*Lf\n", precision, n[0], operator, precision, n[1], precision, result);
		}

		else
		{
			puts("Operation error!");
			petc();
			clear_terminal();
		}
	}

	return 0;
}

/* End code: */
#endif
