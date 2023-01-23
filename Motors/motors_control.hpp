#ifndef MOTORS_CONTROL_H
#define MOTORS_CONTROL_H

#include <stdlib.h>
#include "pico/stdlib.h"
#include <hardware/pwm.h>
#include "hardware/gpio.h"


/*@skip********DEFINITIONS & VARIABLES**********/
#define ENABLE 1
#define DISABLE 0

/*************PMW*************
Desired PWM Freq: 5kHz -> 200us
Period of RP2040 clock -> 8ns
200us/8ns = 2500 cycles -> warp point
*****************************/
#define CYCLES 2500

/************MACROS***********/
#define map(duty) (duty*CYCLES)

void encoders_callback(uint, uint32_t);

class Motors
{
    public:
        Motors() ;
        void init_pwm(void);
        void init_sensors_input(void);

        /*@skip*****************************PORTS*******************************
         The following arrays are by pairs, example:
        - motor_pwm[0] and motor_pwm[1] are FL_PWM_L and FL_PWM_R
        - motor_pwm[2] and motor_pwm[3] are FR_PWM_L and FR_PWM_R 
        - motor_pwm[4] and motor_pwm[5] are RR_PWM_L and RR_PWM_R 
        - motor_pwm[6] and motor_pwm[7] are RL_PWM_L and RL_PWM_R 
        The encoder array goes equually by pairs:
        - encoder[0] and encoder[1] are FL_Senial_A and FL_Senial_B
        - and so on...
        ***********************************************************************/
        uint8_t motor_pwm[8]    = {0,1,27,26,19,18,12,13};
        uint8_t motor_enable[8] = {2,3,22,21,17,16,14,15};
        uint8_t encoders_a[4]     = {6,28,10,8};
        uint8_t encoders_b[4]     = {7,20,11,9};
        uint8_t pwm_slice_num[8];

        uint8_t NUM_MOTORS_PWM = 8;
        enum Motores {FL, FR, RR, RL};
    
    private:
        
};

#endif

