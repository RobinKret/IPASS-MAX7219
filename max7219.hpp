#ifndef MAX7219_HPP
#define MAX7219_HPP
///@file
#include "hwlib.hpp"

namespace MAX7219lib
{
    
    #define max7219_reg_noop        0x00
    #define max7219_reg_digit0      0x01
    #define max7219_reg_digit1      0x02
    #define max7219_reg_digit2      0x03
    #define max7219_reg_digit3      0x04
    #define max7219_reg_digit4      0x05
    #define max7219_reg_digit5      0x06
    #define max7219_reg_digit6      0x07
    #define max7219_reg_digit7      0x08
    #define max7219_reg_decodeMode  0x09
    #define max7219_reg_intensity   0x0a
    #define max7219_reg_scanLimit   0x0b
    #define max7219_reg_shutdown    0x0c
    #define max7219_reg_displayTest 0x0f


    class max7219{
    private:
        hwlib::target::pin_out& clk;     
        hwlib::target::pin_out& din;     
        hwlib::target::pin_out& cs;
        hwlib::spi_bus& bus;
        void clock_hours(uint8_t hour);  
        void clock_minutes(uint8_t minute);    
        void max_write(const uint8_t byte1, const uint8_t byte2, const uint8_t byte3, const uint8_t byte4, const uint8_t byte5, const uint8_t byte6, const uint8_t byte7, const uint8_t byte8);     
    public:
    ///\brief Constructor for MAX7219.
    ///\details With this constructor you can set the clock(clk) pin, data in(din) pin, chip select(cs) pin. and create a spi bus.
        max7219(hwlib::target::pin_out& clk, hwlib::target::pin_out& din, hwlib::target::pin_out& cs, hwlib::spi_bus& bus ):
        clk(clk), din(din), cs(cs), bus(bus)
        {} 
    ///\brief Initialisation of the MAX7219.
    ///\details Intitialises the MAX7219 with a given brightness value from 1-15.
        void init(uint8_t brightness);
    ///\brief Clears the MAX7219.
    ///\details Clears all the led's of the MAX7219.
        void clear();
    ///\brief Turn all led's on.
    ///\details When this funcion is called all led's of the MAX7219 will turn on.
        void all_led_on();
    ///\brief Turn all led's off.
    ///\details When this funcion is called all led's of the MAX7219 will turn off.
        void all_led_off();
    ///\brief Sets a letter on the MAX7219.
    ///\details Sets the given letter on the given spot on the MAX7219. Digit is the matrix you want to display the letter on from 1-4, letter is a capital letter from the alphabet.
        void set_letter(uint8_t digit, uint8_t letter[]);
    ///\brief Sets a number on the MAX7219.
    ///\details Sets the given number on the given spot on the MAX7219. Digit is the matrix you want to display the number on from 1-4, number is a number from 0-9.
        void set_number(uint8_t digit, uint8_t number);
    ///\brief Makes a clock.
    ///\details Set the time for a clock on the MAX7219. Hour is a number from 0-23 and minute is a number from 0-59.
        void set_clock(uint8_t hour, uint8_t minute);
        
    };
}


#endif