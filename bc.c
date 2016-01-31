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
   int i = 0;
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
	while (i < 4)
	{
		//print out partition
		printf("Partition %d \n\r", i);
		//prints("Head: ");  				printu(p->head);				prints("\n\r");
		//prints("Sector: ");				printu(p->sector); 			prints("\n\r");
		//prints("Cylinder: ");			printu(p->cylinder); 		prints("\n\r");
		prints("Type: ");					printd(p->type); 				prints("\n\r");
		prints("Start Sector: ");		printd(p->start_sector);	prints("\n\r");
		prints("Number of Sectors: ");printd(p->nr_sectors);		prints("\n\r");
		prints("\n\r");
		// move to next partition
		p++;
		i++;
	}
}
