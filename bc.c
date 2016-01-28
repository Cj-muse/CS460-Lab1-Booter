#include "io.h"

// load a disk sector to (DS, addr)
int getSector(u32 sector, char *addr)
{
  dp->addr    = addr;
  dp->s1      = (u32)sector;
  diskr();    // call int13-43 in assembly
}

int main()
{
   int i;
   struct partition *p;
   prints("booter start in main()\n\r");

   // initialize the dap struct
   dp = &dap;
   dp->len  = 0x10;        // must be 16
   dp->zero = 0;           // must be 0
   dp->nsector = 1;        // load one sector
   dp->addr = 0;           // will set to addr              
   dp->segment = BOOTSEG;  // always booter's segment
   dp->s1 = 0;             // will set to LBA sector#
	dp->s2 = 0;             // high 4-byte address s2=0

	prints("dap struct initialized\n\r");

	prints("retrieving the Master Boot Record (MBR)...\n\r");
	getSector((u32)0, (u16)mbr); // get MBR
	prints("succesfully retrieved the MBR\n\r");

//  ==================================================
//     In the MBR, partition table begins at 0x1BE
//     DO:#1  WRITE C CODE TO PRINT THE PARTITIONS
//  ==================================================
	color = CYAN;

	//get to offset 0x1BE
	p = dp->addr + 0x1be;
	
	//print out partition
	prints("head: ");
	printu(p->head); 
	prints("\n");


	//gets(ans);
	//prints(ans);
	/*while(1)
	{
		prints("what's your name? ");
   	gets(ans);
    	if (strcmp(ans, "quit")==0)
		{
      	printf("\n\rexit main()\n\r");
	      break;
   	}
    	printf("\n\rWelcome %s!\n\r", ans);
  	}*/
}
