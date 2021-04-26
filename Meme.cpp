#include <stdio.h>
#include <Windows.h>
#include <string>
int main(int argc, char *argv[])
{
	unsigned char color[16] = {0x30,0x31,0x32,0x33,0x34,0x35,0x36,0x37,0x38,0x39,0x61,0x62,0x63,0x64,0x65,0x66 };
	if (argc == 1)
	{
		int i = 0;
		int temp = -1;

		while (1)
		{
			if (i == 15 || i == 0)
				temp *= -1;
			system("cls");
			char s[80]="color ";
			s[6] = color[i];
			//strcat_s(s, color[i]);
			system(s);
			fprintf(stderr,
				"\t   _,-\"\"`\"\"-~`)									\n\t"
				" (`~_,=========\\									\n\t"
				"  |---,___.-.__,\\									\n\t"
				"  |        o     \\ ___  _,,,,_     _.--.			\n\t"
				"   \\      `^`    /`_.-\"~      `~-;`     \\			\n\t"
				"    \\_      _  .'                 `,     |			\n\t"
				"      |`-                           \\'__/ 			\n\t"
				"     /                      ,_       \\  `'-. 		\n\t"
				"    /    .-\"\"~~--.            `\"-,   ;_    /		\n\t"
				"   |              \\               \\  | `\"\"`			\n\t"
				"    \\__.--'`\"-.   /_               |'				\n\t"
				"               \`\"\`  \`~~~---..,     |				\n\t"
				"                              \\ _.-'`-.				\n\t"
				"                               \\       \\			\n\t"
				"                                '.     \/			\n\t"
				"                                  \`\"~\"\`				\n\n\t"
				"		WELCOME TO MEMBERCTF, KEEP TRYING HARD\n"	
			);
			
			i += temp;
			Sleep(250);
		}
		return 0;
	}
	printf("Flag: MemberCTF{W3lc0me-t0-rev3rse}");
	return 0;
}