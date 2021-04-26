#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{
	FILE *fp;
	int i=0,j=0;
	char buffer[1024] = {0};
	char flag[1024] = {0};
	char CipherText[] = "1pB__@!!s@11c!ccc_@rcss0!rm_spc_ac1ram3pB__m!_m!";
	puts("Enter password: ");
	scanf("%s",&buffer);
	if (strcspn(buffer, "\n") != 16)
	{
		printf("NOPE!");
		return -1;
	}
	for (i = 0; i < strcspn(buffer, "\n"); i++)
	{
		if (buffer[i] != CipherText[j + 2])
		{
			printf("WRONG!");
			break;
		}
		j += 3;
	}
	if (i != strcspn(buffer, "\n"))
		return -1;
	fp = fopen("./flag.txt", "r");
	if (fp == NULL)
	{
		puts("File not exist!");
	}
	else 
	{
		fgets(flag, 255, (FILE*)fp);
		puts(flag);
		fclose(fp);
	}
	return 0;
}
