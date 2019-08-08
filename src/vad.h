#ifndef __VAD_H
#define __VAD_H

typedef enum{
    e_vad_ret_is_inactivation,
    e_vad_ret_is_activation,
    e_vad_ret_turn_activation,
    e_vad_ret_turn_inactivation,
}E_VAD_RET_STATUS;


extern void *vad_start( void );
extern int vad_close( void *ivad );
extern int vad_running_16k( void *ivad,\
        const int16_t *iindata, unsigned idlen );

#endif
