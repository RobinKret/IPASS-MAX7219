#include "hwlib.hpp"
#include "max7219.hpp"
#include "data_numbers.hpp"

namespace MAX7219lib
{

    void max7219::max_write(const uint8_t byte1, const uint8_t byte2, const uint8_t byte3, const uint8_t byte4, const uint8_t byte5, const uint8_t byte6, const uint8_t byte7, const uint8_t byte8)
    {
        {auto spi_trans = bus.transaction(cs);
        spi_trans.write(byte1);
        spi_trans.write(byte2);
        spi_trans.write(byte3);
        spi_trans.write(byte4);
        spi_trans.write(byte5);
        spi_trans.write(byte6);
        spi_trans.write(byte7);
        spi_trans.write(byte8);}

    }

    void max7219::init(uint8_t brightness)
    {
        max_write(max7219_reg_decodeMode, 0, max7219_reg_decodeMode, 0, max7219_reg_decodeMode, 0, max7219_reg_decodeMode, 0);                                     //decode mode off
        max_write(max7219_reg_intensity, brightness, max7219_reg_intensity, brightness, max7219_reg_intensity, brightness, max7219_reg_intensity, brightness);     //brightness
        max_write(max7219_reg_scanLimit, 7, max7219_reg_scanLimit, 7, max7219_reg_scanLimit, 7, max7219_reg_scanLimit, 7);                                         //sets scanlimit
        max_write(max7219_reg_shutdown, 1, max7219_reg_shutdown, 1, max7219_reg_shutdown, 1, max7219_reg_shutdown, 1);                                             //turns on MAX7219
    }

    void max7219::clear()
    {
        for (uint8_t i = 0; i < 8; i++)
        {
            max_write(i+1, 0, i+1, 0, i+1, 0, i+1, 0);
        }
        
    }

    void max7219::set_letter(uint8_t digit, uint8_t letter[])
    {
        uint8_t E[8] = {
        0b01111110,0b01000000,0b01000000,0b01111110,
        0b01000000,0b01000000,0b01000000,0b01111110};

        uint8_t R[8] = {
        0b01111100,0b01000010,0b01000010,0b01111100,
        0b01010000,0b01001000,0b01000100,0b01000010};
        
        switch(digit)
        {
            case 1:
            for (uint8_t i = 0; i <= 7; i++)
            {
                max_write(i+1, letter[i], 0, 0, 0, 0, 0, 0);
            }
            break;

            case 2:
            for (uint8_t i = 0; i <= 7; i++)
            {
                max_write( 0, 0, i+1, letter[i], 0, 0, 0, 0);
            }
            break;

            case 3:
            for (uint8_t i = 0; i <= 7; i++)
            {
                max_write( 0, 0, 0, 0, i+1, letter[i], 0, 0);
            }
            break;

            case 4:
            for (uint8_t i = 0; i <= 7; i++)
            {
                max_write( 0, 0, 0, 0, 0, 0, i+1, letter[i]);
            }
            break;
            default:
            for (uint8_t i = 0; i <= 7; i++)
            {
                max_write(i+1, E[i], 0, 0, 0, 0, 0, 0);
                max_write( 0, 0, i+1, R[i], 0, 0, 0, 0);
                max_write( 0, 0, 0, 0, i+1, R[i], 0, 0);
               
            }
        }

        
    }

    void max7219::clock_hours(uint8_t hour)
    {
        switch (hour)
        {
            case 0:
            for (uint8_t i = 0; i <= 7; i++)
            {
                max_write(i+1, number_0[i], 0, 0, 0, 0, 0, 0);
                max_write(0, 0, i+1, number_0[i], 0, 0, 0, 0);
            }
                break;

            case 1:
            for (uint8_t i = 0; i <= 7; i++)
            {
                max_write(i+1, number_0[i], 0, 0, 0, 0, 0, 0);
                max_write(0, 0, i+1, number_1[i], 0, 0, 0, 0);
            }
                break;
            
            case 2:
            for (uint8_t i = 0; i <= 7; i++)
            {
                max_write(i+1, number_0[i], 0, 0, 0, 0, 0, 0);
                max_write(0, 0, i+1, number_2[i], 0, 0, 0, 0);
            }
                break;
            
            case 3:
            for (uint8_t i = 0; i <= 7; i++)
            {
                max_write(i+1, number_0[i], 0, 0, 0, 0, 0, 0);
                max_write(0, 0, i+1, number_3[i], 0, 0, 0, 0);
            }
                break;
            
            case 4:
            for (uint8_t i = 0; i <= 7; i++)
            {
                max_write(i+1, number_0[i], 0, 0, 0, 0, 0, 0);
                max_write(0, 0, i+1, number_4[i], 0, 0, 0, 0);
            }
                break;
            
            case 5:
            for (uint8_t i = 0; i <= 7; i++)
            {
                max_write(i+1, number_0[i], 0, 0, 0, 0, 0, 0);
                max_write(0, 0, i+1, number_5[i], 0, 0, 0, 0);
            }
                break;
            
            case 6:
            for (uint8_t i = 0; i <= 7; i++)
            {
                max_write(i+1, number_0[i], 0, 0, 0, 0, 0, 0);
                max_write(0, 0, i+1, number_6[i], 0, 0, 0, 0);
            }
                break;

            case 7:
            for (uint8_t i = 0; i <= 7; i++)
            {
                max_write(i+1, number_0[i], 0, 0, 0, 0, 0, 0);
                max_write(0, 0, i+1, number_7[i], 0, 0, 0, 0);
            }
                break;

            case 8:
            for (uint8_t i = 0; i <= 7; i++)
            {
                max_write(i+1, number_0[i], 0, 0, 0, 0, 0, 0);
                max_write(0, 0, i+1, number_8[i], 0, 0, 0, 0);
            }
                break;

            case 9:
            for (uint8_t i = 0; i <= 7; i++)
            {
                max_write(i+1, number_0[i], 0, 0, 0, 0, 0, 0);
                max_write(0, 0, i+1, number_9[i], 0, 0, 0, 0);
            }
                break;

            case 10:
            for (uint8_t i = 0; i <= 7; i++)
            {
                max_write(i+1, number_1[i], 0, 0, 0, 0, 0, 0);
                max_write(0, 0, i+1, number_0[i], 0, 0, 0, 0);
            }
                break;

            case 11:
            for (uint8_t i = 0; i <= 7; i++)
            {
                max_write(i+1, number_1[i], 0, 0, 0, 0, 0, 0);
                max_write(0, 0, i+1, number_1[i], 0, 0, 0, 0);
            }
                break;

            case 12:
            for (uint8_t i = 0; i <= 7; i++)
            {
                max_write(i+1, number_1[i], 0, 0, 0, 0, 0, 0);
                max_write(0, 0, i+1, number_2[i], 0, 0, 0, 0);
            }
                break;

            case 13:
            for (uint8_t i = 0; i <= 7; i++)
            {
                max_write(i+1, number_1[i], 0, 0, 0, 0, 0, 0);
                max_write(0, 0, i+1, number_3[i], 0, 0, 0, 0);
            }
                break;

            case 14:
            for (uint8_t i = 0; i <= 7; i++)
            {
                max_write(i+1, number_1[i], 0, 0, 0, 0, 0, 0);
                max_write(0, 0, i+1, number_4[i], 0, 0, 0, 0);
            }
                break;

            case 15:
            for (uint8_t i = 0; i <= 7; i++)
            {
                max_write(i+1, number_1[i], 0, 0, 0, 0, 0, 0);
                max_write(0, 0, i+1, number_5[i], 0, 0, 0, 0);
            }
                break;

            case 16:
            for (uint8_t i = 0; i <= 7; i++)
            {
                max_write(i+1, number_1[i], 0, 0, 0, 0, 0, 0);
                max_write(0, 0, i+1, number_6[i], 0, 0, 0, 0);
            }
                break;

            case 17:
            for (uint8_t i = 0; i <= 7; i++)
            {
                max_write(i+1, number_1[i], 0, 0, 0, 0, 0, 0);
                max_write(0, 0, i+1, number_7[i], 0, 0, 0, 0);
            }
                break;

            case 18:
            for (uint8_t i = 0; i <= 7; i++)
            {
                max_write(i+1, number_1[i], 0, 0, 0, 0, 0, 0);
                max_write(0, 0, i+1, number_8[i], 0, 0, 0, 0);
            }
                break;

            case 19:
            for (uint8_t i = 0; i <= 7; i++)
            {
                max_write(i+1, number_1[i], 0, 0, 0, 0, 0, 0);
                max_write(0, 0, i+1, number_9[i], 0, 0, 0, 0);
            }
                break;

            case 20:
            for (uint8_t i = 0; i <= 7; i++)
            {
                max_write(i+1, number_2[i], 0, 0, 0, 0, 0, 0);
                max_write(0, 0, i+1, number_0[i], 0, 0, 0, 0);
            }
                break;

            case 21:
            for (uint8_t i = 0; i <= 7; i++)
            {
                max_write(i+1, number_2[i], 0, 0, 0, 0, 0, 0);
                max_write(0, 0, i+1, number_1[i], 0, 0, 0, 0);
            }
                break;

            case 22:
            for (uint8_t i = 0; i <= 7; i++)
            {
                max_write(i+1, number_2[i], 0, 0, 0, 0, 0, 0);
                max_write(0, 0, i+1, number_2[i], 0, 0, 0, 0);
            }
                break;

            case 23:
            for (uint8_t i = 0; i <= 7; i++)
            {
                max_write(i+1, number_2[i], 0, 0, 0, 0, 0, 0);
                max_write(0, 0, i+1, number_3[i], 0, 0, 0, 0);
            }
                break;
        }
    }
        

    void max7219::clock_minutes(uint8_t minute)
    {
        switch (minute)
        {
            case 0:
            for (uint8_t i = 0; i <= 7; i++)
            {
                max_write(0, 0, 0, 0, i+1, number_0[i], 0, 0);
                max_write(0, 0, 0, 0, 0, 0, i+1, number_0[i]);
            }
                break;

            case 1:
            for (uint8_t i = 0; i <= 7; i++)
            {
                max_write(0, 0, 0, 0, i+1, number_0[i], 0, 0);
                max_write(0, 0, 0, 0, 0, 0, i+1, number_1[i]);
            }
                break;

            case 2:
            for (uint8_t i = 0; i <= 7; i++)
            {
                max_write(0, 0, 0, 0, i+1, number_0[i], 0, 0);
                max_write(0, 0, 0, 0, 0, 0, i+1, number_2[i]);
            }
                break;

            case 3:
            for (uint8_t i = 0; i <= 7; i++)
            {
                max_write(0, 0, 0, 0, i+1, number_0[i], 0, 0);
                max_write(0, 0, 0, 0, 0, 0, i+1, number_3[i]);
            }
                break;

            case 4:
            for (uint8_t i = 0; i <= 7; i++)
            {
                max_write(0, 0, 0, 0, i+1, number_0[i], 0, 0);
                max_write(0, 0, 0, 0, 0, 0, i+1, number_4[i]);
            }
                break;

            case 5:
            for (uint8_t i = 0; i <= 7; i++)
            {
                max_write(0, 0, 0, 0, i+1, number_0[i], 0, 0);
                max_write(0, 0, 0, 0, 0, 0, i+1, number_5[i]);
            }
                break;

            case 6:
            for (uint8_t i = 0; i <= 7; i++)
            {
                max_write(0, 0, 0, 0, i+1, number_0[i], 0, 0);
                max_write(0, 0, 0, 0, 0, 0, i+1, number_6[i]);
            }
                break;

            case 7:
            for (uint8_t i = 0; i <= 7; i++)
            {
                max_write(0, 0, 0, 0, i+1, number_0[i], 0, 0);
                max_write(0, 0, 0, 0, 0, 0, i+1, number_7[i]);
            }
                break;

            case 8:
            for (uint8_t i = 0; i <= 7; i++)
            {
                max_write(0, 0, 0, 0, i+1, number_0[i], 0, 0);
                max_write(0, 0, 0, 0, 0, 0, i+1, number_8[i]);
            }
                break;

            case 9:
            for (uint8_t i = 0; i <= 7; i++)
            {
                max_write(0, 0, 0, 0, i+1, number_0[i], 0, 0);
                max_write(0, 0, 0, 0, 0, 0, i+1, number_9[i]);
            }
                break;

            case 10:
            for (uint8_t i = 0; i <= 7; i++)
            {
                max_write(0, 0, 0, 0, i+1, number_1[i], 0, 0);
                max_write(0, 0, 0, 0, 0, 0, i+1, number_0[i]);
            }
                break;

            case 11:
            for (uint8_t i = 0; i <= 7; i++)
            {
                max_write(0, 0, 0, 0, i+1, number_1[i], 0, 0);
                max_write(0, 0, 0, 0, 0, 0, i+1, number_1[i]);
            }
                break;

            case 12:
            for (uint8_t i = 0; i <= 7; i++)
            {
                max_write(0, 0, 0, 0, i+1, number_1[i], 0, 0);
                max_write(0, 0, 0, 0, 0, 0, i+1, number_2[i]);
            }
                break;

            case 13:
            for (uint8_t i = 0; i <= 7; i++)
            {
                max_write(0, 0, 0, 0, i+1, number_1[i], 0, 0);
                max_write(0, 0, 0, 0, 0, 0, i+1, number_3[i]);
            }
                break;

            case 14:
            for (uint8_t i = 0; i <= 7; i++)
            {
                max_write(0, 0, 0, 0, i+1, number_1[i], 0, 0);
                max_write(0, 0, 0, 0, 0, 0, i+1, number_4[i]);
            }
                break;

            case 15:
            for (uint8_t i = 0; i <= 7; i++)
            {
                max_write(0, 0, 0, 0, i+1, number_1[i], 0, 0);
                max_write(0, 0, 0, 0, 0, 0, i+1, number_5[i]);
            }
                break;

            case 16:
            for (uint8_t i = 0; i <= 7; i++)
            {
                max_write(0, 0, 0, 0, i+1, number_1[i], 0, 0);
                max_write(0, 0, 0, 0, 0, 0, i+1, number_6[i]);
            }
                break;

            case 17:
            for (uint8_t i = 0; i <= 7; i++)
            {
                max_write(0, 0, 0, 0, i+1, number_1[i], 0, 0);
                max_write(0, 0, 0, 0, 0, 0, i+1, number_7[i]);
            }
                break;

            case 18:
            for (uint8_t i = 0; i <= 7; i++)
            {
                max_write(0, 0, 0, 0, i+1, number_1[i], 0, 0);
                max_write(0, 0, 0, 0, 0, 0, i+1, number_8[i]);
            }
                break;

            case 19:
            for (uint8_t i = 0; i <= 7; i++)
            {
                max_write(0, 0, 0, 0, i+1, number_1[i], 0, 0);
                max_write(0, 0, 0, 0, 0, 0, i+1, number_9[i]);
            }
                break;

            case 20:
            for (uint8_t i = 0; i <= 7; i++)
            {
                max_write(0, 0, 0, 0, i+1, number_2[i], 0, 0);
                max_write(0, 0, 0, 0, 0, 0, i+1, number_0[i]);
            }
                break;

            case 21:
            for (uint8_t i = 0; i <= 7; i++)
            {
                max_write(0, 0, 0, 0, i+1, number_2[i], 0, 0);
                max_write(0, 0, 0, 0, 0, 0, i+1, number_1[i]);
            }
                break;

            case 22:
            for (uint8_t i = 0; i <= 7; i++)
            {
                max_write(0, 0, 0, 0, i+1, number_2[i], 0, 0);
                max_write(0, 0, 0, 0, 0, 0, i+1, number_2[i]);
            }
                break;

            case 23:
            for (uint8_t i = 0; i <= 7; i++)
            {
                max_write(0, 0, 0, 0, i+1, number_2[i], 0, 0);
                max_write(0, 0, 0, 0, 0, 0, i+1, number_3[i]);
            }
                break;

            case 24:
            for (uint8_t i = 0; i <= 7; i++)
            {
                max_write(0, 0, 0, 0, i+1, number_2[i], 0, 0);
                max_write(0, 0, 0, 0, 0, 0, i+1, number_4[i]);
            }
                break;

            case 25:
            for (uint8_t i = 0; i <= 7; i++)
            {
                max_write(0, 0, 0, 0, i+1, number_2[i], 0, 0);
                max_write(0, 0, 0, 0, 0, 0, i+1, number_5[i]);
            }
                break;

            case 26:
            for (uint8_t i = 0; i <= 7; i++)
            {
                max_write(0, 0, 0, 0, i+1, number_2[i], 0, 0);
                max_write(0, 0, 0, 0, 0, 0, i+1, number_6[i]);
            }
                break;

            case 27:
            for (uint8_t i = 0; i <= 7; i++)
            {
                max_write(0, 0, 0, 0, i+1, number_2[i], 0, 0);
                max_write(0, 0, 0, 0, 0, 0, i+1, number_7[i]);
            }
                break;

            case 28:
            for (uint8_t i = 0; i <= 7; i++)
            {
                max_write(0, 0, 0, 0, i+1, number_2[i], 0, 0);
                max_write(0, 0, 0, 0, 0, 0, i+1, number_8[i]);
            }
                break;

            case 29:
            for (uint8_t i = 0; i <= 7; i++)
            {
                max_write(0, 0, 0, 0, i+1, number_2[i], 0, 0);
                max_write(0, 0, 0, 0, 0, 0, i+1, number_9[i]);
            }
                break;

            case 30:
            for (uint8_t i = 0; i <= 7; i++)
            {
                max_write(0, 0, 0, 0, i+1, number_3[i], 0, 0);
                max_write(0, 0, 0, 0, 0, 0, i+1, number_0[i]);
            }
                break;

            case 31:
            for (uint8_t i = 0; i <= 7; i++)
            {
                max_write(0, 0, 0, 0, i+1, number_3[i], 0, 0);
                max_write(0, 0, 0, 0, 0, 0, i+1, number_1[i]);
            }
                break;

            case 32:
            for (uint8_t i = 0; i <= 7; i++)
            {
                max_write(0, 0, 0, 0, i+1, number_3[i], 0, 0);
                max_write(0, 0, 0, 0, 0, 0, i+1, number_2[i]);
            }
                break;
                
            case 33:
            for (uint8_t i = 0; i <= 7; i++)
            {
                max_write(0, 0, 0, 0, i+1, number_3[i], 0, 0);
                max_write(0, 0, 0, 0, 0, 0, i+1, number_3[i]);
            }
                break;

            case 34:
            for (uint8_t i = 0; i <= 7; i++)
            {
                max_write(0, 0, 0, 0, i+1, number_3[i], 0, 0);
                max_write(0, 0, 0, 0, 0, 0, i+1, number_4[i]);
            }
                break;

            case 35:
            for (uint8_t i = 0; i <= 7; i++)
            {
                max_write(0, 0, 0, 0, i+1, number_3[i], 0, 0);
                max_write(0, 0, 0, 0, 0, 0, i+1, number_5[i]);
            }
                break;

            case 36:
            for (uint8_t i = 0; i <= 7; i++)
            {
                max_write(0, 0, 0, 0, i+1, number_3[i], 0, 0);
                max_write(0, 0, 0, 0, 0, 0, i+1, number_6[i]);
            }
                break;

            case 37:
            for (uint8_t i = 0; i <= 7; i++)
            {
                max_write(0, 0, 0, 0, i+1, number_3[i], 0, 0);
                max_write(0, 0, 0, 0, 0, 0, i+1, number_7[i]);
            }
                break;

            case 38:
            for (uint8_t i = 0; i <= 7; i++)
            {
                max_write(0, 0, 0, 0, i+1, number_3[i], 0, 0);
                max_write(0, 0, 0, 0, 0, 0, i+1, number_8[i]);
            }
                break;

            case 39:
            for (uint8_t i = 0; i <= 7; i++)
            {
                max_write(0, 0, 0, 0, i+1, number_3[i], 0, 0);
                max_write(0, 0, 0, 0, 0, 0, i+1, number_9[i]);
            }
                break;

            case 40:
            for (uint8_t i = 0; i <= 7; i++)
            {
                max_write(0, 0, 0, 0, i+1, number_4[i], 0, 0);
                max_write(0, 0, 0, 0, 0, 0, i+1, number_0[i]);
            }
                break;

            case 41:
            for (uint8_t i = 0; i <= 7; i++)
            {
                max_write(0, 0, 0, 0, i+1, number_4[i], 0, 0);
                max_write(0, 0, 0, 0, 0, 0, i+1, number_1[i]);
            }
                break;

            case 42:
            for (uint8_t i = 0; i <= 7; i++)
            {
                max_write(0, 0, 0, 0, i+1, number_4[i], 0, 0);
                max_write(0, 0, 0, 0, 0, 0, i+1, number_2[i]);
            }
                break;

            case 43:
            for (uint8_t i = 0; i <= 7; i++)
            {
                max_write(0, 0, 0, 0, i+1, number_4[i], 0, 0);
                max_write(0, 0, 0, 0, 0, 0, i+1, number_3[i]);
            }
                break;

            case 44:
            for (uint8_t i = 0; i <= 7; i++)
            {
                max_write(0, 0, 0, 0, i+1, number_4[i], 0, 0);
                max_write(0, 0, 0, 0, 0, 0, i+1, number_4[i]);
            }
                break;

            case 45:
            for (uint8_t i = 0; i <= 7; i++)
            {
                max_write(0, 0, 0, 0, i+1, number_4[i], 0, 0);
                max_write(0, 0, 0, 0, 0, 0, i+1, number_5[i]);
            }
                break;

            case 46:
            for (uint8_t i = 0; i <= 7; i++)
            {
                max_write(0, 0, 0, 0, i+1, number_4[i], 0, 0);
                max_write(0, 0, 0, 0, 0, 0, i+1, number_6[i]);
            }
                break;

            case 47:
            for (uint8_t i = 0; i <= 7; i++)
            {
                max_write(0, 0, 0, 0, i+1, number_4[i], 0, 0);
                max_write(0, 0, 0, 0, 0, 0, i+1, number_7[i]);
            }
                break;

            case 48:
            for (uint8_t i = 0; i <= 7; i++)
            {
                max_write(0, 0, 0, 0, i+1, number_4[i], 0, 0);
                max_write(0, 0, 0, 0, 0, 0, i+1, number_8[i]);
            }
                break;

            case 49:
            for (uint8_t i = 0; i <= 7; i++)
            {
                max_write(0, 0, 0, 0, i+1, number_4[i], 0, 0);
                max_write(0, 0, 0, 0, 0, 0, i+1, number_9[i]);
            }
                break;

            case 50:
            for (uint8_t i = 0; i <= 7; i++)
            {
                max_write(0, 0, 0, 0, i+1, number_5[i], 0, 0);
                max_write(0, 0, 0, 0, 0, 0, i+1, number_0[i]);
            }
                break;

            case 51:
            for (uint8_t i = 0; i <= 7; i++)
            {
                max_write(0, 0, 0, 0, i+1, number_5[i], 0, 0);
                max_write(0, 0, 0, 0, 0, 0, i+1, number_1[i]);
            }
                break;

            case 52:
            for (uint8_t i = 0; i <= 7; i++)
            {
                max_write(0, 0, 0, 0, i+1, number_5[i], 0, 0);
                max_write(0, 0, 0, 0, 0, 0, i+1, number_2[i]);
            }
                break;

            case 53:
            for (uint8_t i = 0; i <= 7; i++)
            {
                max_write(0, 0, 0, 0, i+1, number_5[i], 0, 0);
                max_write(0, 0, 0, 0, 0, 0, i+1, number_3[i]);
            }
                break;

            case 54:
            for (uint8_t i = 0; i <= 7; i++)
            {
                max_write(0, 0, 0, 0, i+1, number_5[i], 0, 0);
                max_write(0, 0, 0, 0, 0, 0, i+1, number_4[i]);
            }
                break;

            case 55:
            for (uint8_t i = 0; i <= 7; i++)
            {
                max_write(0, 0, 0, 0, i+1, number_5[i], 0, 0);
                max_write(0, 0, 0, 0, 0, 0, i+1, number_5[i]);
            }
                break;

            case 56:
            for (uint8_t i = 0; i <= 7; i++)
            {
                max_write(0, 0, 0, 0, i+1, number_5[i], 0, 0);
                max_write(0, 0, 0, 0, 0, 0, i+1, number_6[i]);
            }
                break;

            case 57:
            for (uint8_t i = 0; i <= 7; i++)
            {
                max_write(0, 0, 0, 0, i+1, number_5[i], 0, 0);
                max_write(0, 0, 0, 0, 0, 0, i+1, number_7[i]);
            }
                break;

            case 58:
            for (uint8_t i = 0; i <= 7; i++)
            {
                max_write(0, 0, 0, 0, i+1, number_5[i], 0, 0);
                max_write(0, 0, 0, 0, 0, 0, i+1, number_8[i]);
            }
                break;

            case 59:
            for (uint8_t i = 0; i <= 7; i++)
            {
                max_write(0, 0, 0, 0, i+1, number_5[i], 0, 0);
                max_write(0, 0, 0, 0, 0, 0, i+1, number_9[i]);
            }
                break;            
        }  
    }

    

    void max7219::set_number(uint8_t digit, uint8_t number)
    {
        switch (digit)
        {
            case 1:
            switch (number)
            {
                case 0:
                for (uint8_t i = 0; i <= 7; i++)
                {
                    max_write(i+1, number_0[i], 0, 0, 0, 0, 0, 0);
                }
                break;

                case 1:
                for (uint8_t i = 0; i <= 7; i++)
                {
                    max_write(i+1, number_1[i], 0, 0, 0, 0, 0, 0);
                }
                break;

                case 2:
                for (uint8_t i = 0; i <= 7; i++)
                {
                    max_write(i+1, number_2[i], 0, 0, 0, 0, 0, 0);
                }
                break;

                case 3:
                for (uint8_t i = 0; i <= 7; i++)
                {
                    max_write(i+1, number_3[i], 0, 0, 0, 0, 0, 0);
                }
                break;
            
                case 4:
                for (uint8_t i = 0; i <= 7; i++)
                {
                    max_write(i+1, number_4[i], 0, 0, 0, 0, 0, 0);
                }
                break;
            
                case 5:
                for (uint8_t i = 0; i <= 7; i++)
                {
                    max_write(i+1, number_5[i], 0, 0, 0, 0, 0, 0);
                }
                break;
            
                case 6:
                for (uint8_t i = 0; i <= 7; i++)
                {
                    max_write(i+1, number_6[i], 0, 0, 0, 0, 0, 0);
                }
                break;
            
                case 7:
                for (uint8_t i = 0; i <= 7; i++)
                {
                    max_write(i+1, number_7[i], 0, 0, 0, 0, 0, 0);
                }
                break;

                case 8:
                for (uint8_t i = 0; i <= 7; i++)
                {
                    max_write(i+1, number_8[i], 0, 0, 0, 0, 0, 0);
                }
                break;
            
                case 9:
                for (uint8_t i = 0; i <= 7; i++)
                {
                    max_write(i+1, number_9[i], 0, 0, 0, 0, 0, 0);
                }
                break;            
            }
            break;
                    
            case 2:
            switch (number)
            {
                case 0:
                for (uint8_t i = 0; i <= 7; i++)
                {
                    max_write(0, 0, i+1, number_0[i], 0, 0, 0, 0);
                }
                break;

                case 1:
                for (uint8_t i = 0; i <= 7; i++)
                {
                    max_write(0, 0, i+1, number_1[i], 0, 0, 0, 0);
                }
                break;

                case 2:
                for (uint8_t i = 0; i <= 7; i++)
                {
                    max_write(0, 0, i+1, number_2[i], 0, 0, 0, 0);
                }
                break;

                case 3:
                for (uint8_t i = 0; i <= 7; i++)
                {
                    max_write(0, 0, i+1, number_3[i], 0, 0, 0, 0);
                }
                break;
            
                case 4:
                for (uint8_t i = 0; i <= 7; i++)
                {
                    max_write(0, 0, i+1, number_4[i], 0, 0, 0, 0);
                }
                break;
            
                case 5:
                for (uint8_t i = 0; i <= 7; i++)
                {
                    max_write(0, 0, i+1, number_5[i], 0, 0, 0, 0);
                }
                break;
            
                case 6:
                for (uint8_t i = 0; i <= 7; i++)
                {
                    max_write(0, 0, i+1, number_6[i], 0, 0, 0, 0);
                }
                break;
            
                case 7:
                for (uint8_t i = 0; i <= 7; i++)
                {
                    max_write(0, 0, i+1, number_7[i], 0, 0, 0, 0);
                }
                break;

                case 8:
                for (uint8_t i = 0; i <= 7; i++)
                {
                    max_write(0, 0, i+1, number_8[i], 0, 0, 0, 0);
                }
                break;
            
                case 9:
                for (uint8_t i = 0; i <= 7; i++)
                {
                    max_write(0, 0, i+1, number_9[i], 0, 0, 0, 0);
                }
                break;      
            }
            break;

            case 3:
            switch (number)
            {
                case 0:
                for (uint8_t i = 0; i <= 7; i++)
                {
                    max_write(0, 0, 0, 0, i+1, number_0[i], 0, 0);
                }
                break;

                case 1:
                for (uint8_t i = 0; i <= 7; i++)
                {
                    max_write(0, 0, 0, 0, i+1, number_1[i], 0, 0);
                }
                break;

                case 2:
                for (uint8_t i = 0; i <= 7; i++)
                {
                    max_write(0, 0, 0, 0, i+1, number_2[i], 0, 0);
                }
                break;

                case 3:
                for (uint8_t i = 0; i <= 7; i++)
                {
                    max_write(0, 0, 0, 0, i+1, number_3[i], 0, 0);
                }
                break;
            
                case 4:
                for (uint8_t i = 0; i <= 7; i++)
                {
                    max_write(0, 0, 0, 0, i+1, number_4[i], 0, 0);
                }
                break;
            
                case 5:
                for (uint8_t i = 0; i <= 7; i++)
                {
                    max_write(0, 0, 0, 0, i+1, number_5[i], 0, 0);
                }
                break;
            
                case 6:
                for (uint8_t i = 0; i <= 7; i++)
                {
                    max_write(0, 0, 0, 0, i+1, number_6[i], 0, 0);
                }
                break;
            
                case 7:
                for (uint8_t i = 0; i <= 7; i++)
                {
                    max_write(0, 0, 0, 0, i+1, number_7[i], 0, 0);
                }
                break;

                case 8:
                for (uint8_t i = 0; i <= 7; i++)
                {
                    max_write(0, 0, 0, 0, i+1, number_8[i], 0, 0);
                }
                break;
            
                case 9:
                for (uint8_t i = 0; i <= 7; i++)
                {
                    max_write(0, 0, 0, 0, i+1, number_9[i], 0, 0);
                }
                break;
            }
            break;

            case 4:
            switch (number)
            {
                case 0:
                for (uint8_t i = 0; i <= 7; i++)
                {
                    max_write(0, 0, 0, 0, 0, 0, i+1, number_0[i]);
                }
                break;

                case 1:
                for (uint8_t i = 0; i <= 7; i++)
                {
                    max_write(0, 0, 0, 0, 0, 0, i+1, number_1[i]);
                }
                break;

                case 2:
                for (uint8_t i = 0; i <= 7; i++)
                {
                    max_write(0, 0, 0, 0, 0, 0, i+1, number_2[i]);
                }
                break;

                case 3:
                for (uint8_t i = 0; i <= 7; i++)
                {
                    max_write(0, 0, 0, 0, 0, 0, i+1, number_3[i]);
                }
                break;
            
                case 4:
                for (uint8_t i = 0; i <= 7; i++)
                {
                    max_write(0, 0, 0, 0, 0, 0, i+1, number_4[i]);
                }
                break;
            
                case 5:
                for (uint8_t i = 0; i <= 7; i++)
                {
                    max_write(0, 0, 0, 0, 0, 0, i+1, number_5[i]);
                }
                break;
            
                case 6:
                for (uint8_t i = 0; i <= 7; i++)
                {
                    max_write(0, 0, 0, 0, 0, 0, i+1, number_6[i]);
                }
                break;
            
                case 7:
                for (uint8_t i = 0; i <= 7; i++)
                {
                    max_write(0, 0, 0, 0, 0, 0, i+1, number_7[i]);
                }
                break;

                case 8:
                for (uint8_t i = 0; i <= 7; i++)
                {
                    max_write(0, 0, 0, 0, 0, 0, i+1, number_8[i]);
                }
                break;
            
                case 9:
                for (uint8_t i = 0; i <= 7; i++)
                {
                    max_write(0, 0, 0, 0, 0, 0, i+1, number_9[i]);
                }
                break;
            }
            break;
        }
    }


    void max7219::all_led_on()
    {
        max_write(max7219_reg_displayTest, 1, max7219_reg_displayTest, 1, max7219_reg_displayTest, 1, max7219_reg_displayTest, 1);
    }

    void max7219::all_led_off()
    {
        max_write(max7219_reg_displayTest, 0, max7219_reg_displayTest, 0, max7219_reg_displayTest, 0, max7219_reg_displayTest, 0);
    }

    void max7219::set_clock(uint8_t hour, uint8_t minute)
    {
        int hours = hour, minutes = minute;
        
        while (true)
        {
            clock_hours(hours);
            clock_minutes(minutes);
            minutes++;
            if (minutes == 60)
            {
                
                hours++;
                minutes = 0;
                
                if (hours == 24)
                {
                    hours = 0;
                }
                
            }
            hwlib::wait_ms(60000);
        }
    }


}
