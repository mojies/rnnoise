#include <stdio.h>
#include <stdint.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/time.h>
#include "../include/vad.h"

// #define DL_FRAME_SIZE 240*2
#define DL_FRAME_SIZE 120*2

unsigned debug_level = 7;


void Dbg_Show_Now( void ){
    struct timeval tNow;
    gettimeofday( &tNow, NULL );
    printf( "%u.%u\n", tNow.tv_sec, tNow.tv_usec  );
}

int main( int argc, char *argv[] ){
    void       *tp_vad;

    int         tv_infd;
    int         tv_outfd;

    short       tv_inbuf[ DL_FRAME_SIZE*2 ];
    int         tv_rlen;
    int         tv_flag;


    tv_infd = open( argv[1], O_RDONLY );
    // DLLOGV( "%s fd is %d", argv[1], tv_infd );
    tv_outfd = open( argv[2], O_RDWR|O_TRUNC|O_CREAT, S_IRWXU|S_IRWXO|S_IRWXG );

    tp_vad = vad_start();

    Dbg_Show_Now();
    while( ( tv_rlen = read( tv_infd, tv_inbuf, DL_FRAME_SIZE*sizeof(short) )  ) > 0  ){
        tv_flag = vad_running_16k( tp_vad, tv_inbuf, DL_FRAME_SIZE );
        memset( tv_inbuf, tv_flag*30, DL_FRAME_SIZE*sizeof(short) );
        write( tv_outfd, tv_inbuf, DL_FRAME_SIZE*sizeof(short) );
    }
    Dbg_Show_Now();

    vad_close( tp_vad );

    return 0;
}


