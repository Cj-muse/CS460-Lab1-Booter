#include "io.h"

int rpu(u8 x)
{
	char c;
   if (x)
	{
		c = table[x % BASE];
		rpu(x / BASE);
		putc(c);
	}
} 

int printu(u8 x)
{
	if (x==0)
	{
		putc('0');
	}
	else
	{
		rpu(x);
	}
	putc(' ');
}

int printf()
{}

int prints(char *s)
{ 
	int i = 0;
	while(s[i])
	{
		putc(s[i]);
		i++;
	}
}

strcmp()
{}

//returns a string using the assembly function getc()
int gets(char s[64])
{	
	int i = 0;
	char c = '0';
	
	// put carrige return and newline on front of string 
	s[0] = '\n';
	s[1] = '\r';
	i = 2;

	do // iterate over user keystrokes until newline is encounterd
	{
		c = getc();
		s[i] = c;
		putc(s[i]);// print out the char entered for the user to see
		i++;
	}  while (c != 13 && i < 63);

	//add \n
	s[i] = '\n';
	s[i+1] = '\r';
	s[i+2] = 0;
}
