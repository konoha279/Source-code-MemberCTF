#include <stdio.h>
#include <sys/ptrace.h>
#include <unistd.h>
#include <sys/mman.h>
#include <stdlib.h>
#include <time.h>

int key =10;
unsigned char RealFlag[] ="\x60\x00\xB2\x1B\x1B\x1B\x1B\xB1\x71\x2B\x79\x66\x3B\xC9\x59\x4A\xB1\x28\x2B\x7F\x36\x3B\xC9\x59\x4A\xB1\x7E\x28\x44\x7C\x3B\xC9\x59\x4A\xB1\x72\x77\x28\x75\x3B\xC9\x59\x4A\xB1\x32\x58\x73\x2F\x3B\xC9\x59\x4A\xB1\x70\x5B\x68\x6F\x3B\xC9\x59\x4A\xB1\x49\x73\x28\x36\x3B\xC9\x59\x4A\xB1\x51\x4F\x5D\x60\x3B\xC9\x59\x4A\xB1\x7E\x79\x7E\x69\x3B\xC9\x59\x4A\x62\x30\x2A\x47\x6F\x62\x6D\x2A\x63\x79\x62\x4C\x66\x6B\x0A\xB2\x0E\x0A\x0A\x0A\xB1\x0B\x0A\x0A\x0A\x83\xEB\xB0\x38\x0A\x0A\x0A\xC7\x8A\xB2\x0B\x0A\x0A\x0A\xC7\x8A";

unsigned char FakeFlag[] = "\x6A\x0A\x68\x6C\x61\x67\x7D\x68\x6B\x65\x5F\x66\x68\x70\x68\x61\x2D\x68\x43\x54\x46\x7B\x68\x6D\x62\x65\x72\x68\x3A\x20\x4D\x65\x68\x67\x20\x69\x73\x68\x20\x46\x6C\x61\x68\x61\x2D\x6B\x65\x68\x50\x68\x00\x00\xB8\x04\x00\x00\x00\xBB\x01\x00\x00\x00\x89\xE1\xBA\x29\x00\x00\x00\xCD\x80\xB8\x01\x00\x00\x00\xCD\x80";

void hihi(int temp)
{
	if ( temp >= 0)
	{
		__asm__ ("lea eax, RealFlag\n"
		 	 "call eax\n");
	}	
	__asm__ ("lea eax, FakeFlag\n"
		 "call eax\n");
}

int main()
{
	time_t t;
	int bypass;
	int antiDebug = (int)ptrace(0, 0, 1, 0);
	int size = getpagesize();
	mprotect(RealFlag - (unsigned int)RealFlag % size, size, 6);
	mprotect(FakeFlag - (unsigned int)FakeFlag % size, size, 6);
	if (antiDebug >= 0)
		for (int i=0; i<129;i++)
		{
			RealFlag[i]=RealFlag[i]^key;
		}
	srand((unsigned) time(&t));
	int  temp = rand()% 100;
	int inp;
	
	if (temp < 50)
		temp += 50;
	printf("Please input %d random number\n",temp);
	while (temp)
	{
		int n = rand()% 1000000;
		if (n <= 100000)
			n += 100000;
		printf("Input number: ");
		scanf("%d",&inp);
		if (inp == n)
			temp--;
		else
		{
			printf("OH NO! TODAY YOU'RE NOT LUCK!\n");
			break;
		}

	}
	bypass = !(temp);
	if (bypass)
		hihi(antiDebug);
	return 0;
}

