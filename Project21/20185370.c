#define _CRT_SECURE_NO_WARNIGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>



int main(int argc, char *argv[])
{
	FILE *f1,*f2;
	
	

	char revname[] = "OSParadigmShift2.rev";
	

	if (fopen_s(&f1, argv[1], "r") != 0)
	{
		printf("파일이 열리지 않습니다");
		exit(1);
	}


	if (fopen_s(&f2,revname, "w") != 0)
	{
		printf("파일이 열리지 않습니다");
		fclose(f1);
		exit(1);
	}

	int linecount = 0, wordcount = 0, charactercount = 0, spacecount = 0;
	char a;
	int b;

	while (!feof(f1))
	{
		a = getc(f1);
		if (a == '\n')
		{
			linecount++;
			putc(a, f2);
		}
		else if (isgraph(a))
		{
			charactercount++;
			if (isdigit(a))
			{
				putc(a, f2);
			}
		}
		else if (a == ' ')
		{
			spacecount++;
			putc(a, f2);
		}


		if (isalpha(a))
		{
			if (islower(a))
				a = toupper(a);
			else if (isupper(a))
				a = tolower(a);

			putc(a, f2);
		}

	}

	

	printf("<Result>\n");
	printf("line count = %d \n",linecount+1);
	printf("character count = %d \n", charactercount);
	printf("word count = %d \n", spacecount+1);

	fclose(f1);
	fclose(f2);
	printf("File saved in OSParadigmShift.rev");


	system("pause");
	return 0;
}