#include "motors_control.hpp"

int16_t PPS[4] = {0,0,0,0};
bool EncoderB_status[4] = {0,0,0,0}; 


/// @brief Function that calculates the Pulses Per Second
/// of the encoders
/// @param gpio 
/// @param events 
void encoders_callback(uint gpio, uint32_t events)
{
    uint8_t pos = 0;
    if (events == gpio_irq_level::GPIO_IRQ_LEVEL_HIGH)
    {
        switch (gpio)
        {
        case 6:
            pos = 0;
            break;
        case 28:
            pos = 1;
            break;
        case 10:
            pos = 2;
            break;
        case 8:
            pos = 3;
            break;
        default:
            break;
        }
    }

    if(EncoderB_status[pos] == 1)
    {
        PPS[pos] += 1;
    }
    else
    {
        PPS[pos] -= 1;
    }

}

Motors::Motors()
{
    
}

///*******************************************************************///
///@brief This function initializes all ports for the encoders
///@skip
///gpio_init: Initialize a GPIO
///gpio_set_dir: Set a single GPIO direction; in this case as INPUT
///gpio_pull_down: Set specified GPIO to be pulled down. 
///@return None
///*******************************************************************///
void Motors::init_sensors_input(void)
{
    for(uint8_t i = 0; i < NUM_MOTORS_PWM/2; i++)
    {
        gpio_init(encoders_a[i]);
        gpio_set_dir(encoders_a[i], GPIO_IN);
        gpio_pull_down(encoders_b[i]);
        gpio_init(encoders_b[i]);
        gpio_set_dir(encoders_b[i], GPIO_IN);
        gpio_pull_down(encoders_b[i]);
    }

    for(uint8_t i=0; i < NUM_MOTORS_PWM/2; i++)
    {
        EncoderB_status[i] =  gpio_get(encoders_b[i]);
        gpio_set_irq_enabled_with_callback(encoders_a[i], GPIO_IRQ_EDGE_RISE, true, &encoders_callback);
    }
}

///*******************************************************************///
///@brief This function initializes all ports for the dc motors as PWM
///@skip
///gpio_set_function: Initialize ports(in this case as PWM)
///pwm_gpio_to_slice_num: Find out which PWM channel is connected to the actual GPIO
///pwm_set_enabled: Turn off PWM
///pwm_set_wrap: Set period by wraps
///@return None
///*******************************************************************///
void Motors::init_pwm(void)
{   
    for(uint8_t i = 0; i < NUM_MOTORS_PWM; i++)
    {
        gpio_set_function(motor_pwm[i], GPIO_FUNC_PWM);
        pwm_slice_num[i] = pwm_gpio_to_slice_num(motor_pwm[i]);  
        pwm_set_enabled(pwm_slice_num[i], false);
        pwm_set_wrap(pwm_slice_num[i], CYCLES);
    }
}


