#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <pthread.h>


int main()
{
    int file_desc;
    char tmp[4];
    
    int i;
    for(i = 0; i < 4; i++) {
		tmp[i] = 0;
	}

   /* Open controller file. */
while(1) {
	
    file_desc = open("/dev/gpio_driver", O_RDWR);

    if(file_desc < 0)
    {
        printf("Error, 'gpio_driver' not opened\n");
        return -1;
    }

    /* Write to controller file. */
    write(file_desc, tmp, 4);
    
    sleep(1);
    
    /* Read from controller file. */
    read(file_desc, tmp, 4);
    /*
    printf("%d%d%d%d%d%d%d%d",
		  (tmp[0] & 0x80) >> 7, (tmp[0] & 0x40) >> 6, (tmp[0] & 0x20) >> 5,
		  (tmp[0] & 0x10 >> 4), (tmp[0] & 0x08) >> 3, (tmp[0] & 0x04) >> 2, 
		  (tmp[0] & 0x02) >> 1, tmp[0] & 0x01);
    printf("%d%d%d%d%d%d",
		  (tmp[1] & 0x20) >> 5, (tmp[1] & 0x10) >> 4, 
		  (tmp[1] & 0x08) >> 3, (tmp[1] & 0x04) >> 2, 
		  (tmp[1] & 0x02) >> 1, tmp[1] & 0x01);
    printf("\t0x%x\t0x%x\n", tmp[2], tmp[3]);
	printf("\n");
	*/
	sleep(0.1);
	printf("%x %x %x %x\n", tmp[0], tmp[1], tmp[2], tmp[3]);  
	
    /* Close controller file. */
    close(file_desc);


}    
    return 0;
}
