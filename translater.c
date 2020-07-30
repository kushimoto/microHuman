#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BASE 33

int main (int argc, char** argv) {

	int ch;
	char name[256];

	FILE* sfp;
	FILE* dfp;

	sfp = fopen(argv[1], "r");

	if (sfp == NULL) {
		perror("fopen");
		exit(EXIT_FAILURE);
	}

	strcat(name, argv[2]);
	strcat(name, ".mhc");
	strcat(argv[2], "\n");
	dfp = fopen(name, "w");
	fputs(argv[2], dfp);

	for (int i = 0; i < MAX_BASE; i++) {
		for (int j = 0; j <= MAX_BASE; j++) {

			switch (ch = fgetc(sfp)) {
				case '+':
					if ( j < (MAX_BASE - 1) )
						fputs("4, ", dfp);
					else
						fputs("4\n", dfp);
					break;
				case '-':
					for (int k = 0; k < 2; k++)
						if (ch = fgetc(sfp) != '-')
							exit(EXIT_FAILURE);
					
					if ( j < (MAX_BASE - 1) )
						fputs("3, ", dfp);
					else
						fputs("3\n", dfp);
					break;
				case '|':
					if ( j < (MAX_BASE - 1) )
						fputs("2, ", dfp);
					else
						fputs("2\n", dfp);
					break;
				case ' ':
					if (j % 2 == 1) {
						for (int k = 0; k < 2; k++)
							if (ch = fgetc(sfp) != ' ')
								exit(EXIT_FAILURE);
					}

					if ( j < (MAX_BASE - 1) )
						fputs("0, ", dfp);
					else
						fputs("0\n", dfp);
					break;
			}

			printf("i = %d j = %d ch = %c\n", i, j, (char)ch);

		}
	}

	fclose(sfp);
	fclose(dfp);

	exit(EXIT_SUCCESS);
}
