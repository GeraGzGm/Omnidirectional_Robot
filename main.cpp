#include "Motors/motors_control.hpp"

Motors Motor;


int main()
{
    Motor.init_pwm();
    Motor.init_sensors_input();
    
    /*
    //Turn on pwm
    pwm_set_enabled(Motor.pwm_slice_num[0], true);

    //pwm_set_chan_level(slice_num, PWM_CHAN_A,2499);

    while (1)
    {
        for (int x = 0; x < 100; x += 1) {
            //PWM_CHAN_# 0 for A, 1 for B.
            pwm_set_chan_level(Motor.pwm_slice_num[0], PWM_CHAN_A,map(x / 100.0f));
            sleep_ms(100);
        }
        
    }
    */
    return 0;
}