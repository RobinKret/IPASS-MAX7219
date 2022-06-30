#include "hwlib.hpp"
#include "max7219.hpp"
#include "data_letters.hpp"


int main( void )
{
	auto din = hwlib::target::pin_out(hwlib::target::pins::d4);
    auto cs = hwlib::target::pin_out(hwlib::target::pins::d3);
    auto clk = hwlib::target::pin_out(hwlib::target::pins::d2);
	auto bus = hwlib::spi_bus_bit_banged_sclk_mosi_miso(clk, din, hwlib::pin_in_dummy);
	MAX7219lib::max7219 matrix(clk, din, cs, bus);
	
	matrix.init(5);  // 1-15
	matrix.clear();
	hwlib::wait_ms(100);
	matrix.all_led_on();
	hwlib::wait_ms(500);
	matrix.all_led_off();
	matrix.set_number(1, 4);
	hwlib::wait_ms(500);
	matrix.set_number(2, 3);
	hwlib::wait_ms(500);
	matrix.set_number(3, 2);
	hwlib::wait_ms(500);
	matrix.set_number(4, 1);
	hwlib::wait_ms(500);
	matrix.clear();
	hwlib::wait_ms(100);
	matrix.set_letter(2, G);
	matrix.set_letter(3, O);
	hwlib::wait_ms(500);
	matrix.clear();
	matrix.set_letter(1, A);
	hwlib::wait_ms(200);
	matrix.set_letter(2, B);
	hwlib::wait_ms(200);
	matrix.set_letter(3, C);
	hwlib::wait_ms(200);
	matrix.set_letter(4, D);
	hwlib::wait_ms(200);
	matrix.clear();
	matrix.set_letter(1, E);
	hwlib::wait_ms(200);
	matrix.set_letter(2, F);
	hwlib::wait_ms(200);
	matrix.set_letter(3, G);
	hwlib::wait_ms(200);
	matrix.set_letter(4, H);
	hwlib::wait_ms(200);
	matrix.clear();
	matrix.set_letter(1, I);
	hwlib::wait_ms(200);
	matrix.set_letter(2, J);
	hwlib::wait_ms(200);
	matrix.set_letter(3, K);
	hwlib::wait_ms(200);
	matrix.set_letter(4, L);
	hwlib::wait_ms(200);
	matrix.clear();
	matrix.set_letter(1, M);
	hwlib::wait_ms(200);
	matrix.set_letter(2, N);
	hwlib::wait_ms(200);
	matrix.set_letter(3, O);
	hwlib::wait_ms(200);
	matrix.set_letter(4, P);
	hwlib::wait_ms(200);
	matrix.clear();
	matrix.set_letter(1, Q);
	hwlib::wait_ms(200);
	matrix.set_letter(2, R);
	hwlib::wait_ms(200);
	matrix.set_letter(3, S);
	hwlib::wait_ms(200);
	matrix.set_letter(4, T);
	hwlib::wait_ms(200);
	matrix.clear();
	matrix.set_letter(1, U);
	hwlib::wait_ms(200);
	matrix.set_letter(2, V);
	hwlib::wait_ms(200);
	matrix.set_letter(3, W);
	hwlib::wait_ms(200);
	matrix.set_letter(4, X);
	hwlib::wait_ms(200);
	matrix.clear();
	matrix.set_letter(1, Y);
	hwlib::wait_ms(200);
	matrix.set_letter(2, Z);
	hwlib::wait_ms(200);
	matrix.set_number(3, 1);
	hwlib::wait_ms(200);
	matrix.set_number(4, 2);
	hwlib::wait_ms(200);
	matrix.clear();
	matrix.set_number(1, 3);
	hwlib::wait_ms(200);
	matrix.set_number(2, 4);
	hwlib::wait_ms(200);
	matrix.set_number(3, 5);
	hwlib::wait_ms(200);
	matrix.set_number(4, 6);
	hwlib::wait_ms(200);
	matrix.clear();
	matrix.set_number(1, 7);
	hwlib::wait_ms(200);
	matrix.set_number(2, 8);
	hwlib::wait_ms(200);
	matrix.set_number(3, 9);
	hwlib::wait_ms(200);
	matrix.clear();
	hwlib::wait_ms(500);
	matrix.set_letter(2, N);
	matrix.set_letter(3, U);
	hwlib::wait_ms(500);
	matrix.clear();
	matrix.set_letter(2, D);
	matrix.set_letter(3, E);
	hwlib::wait_ms(500);
	matrix.clear();
	matrix.set_letter(1, K);
	matrix.set_letter(2, L);
	matrix.set_letter(3, O);
	matrix.set_letter(4, K);
	hwlib::wait_ms(500);
	matrix.clear();
	hwlib::wait_ms(100);
	matrix.set_clock(9, 50);
	


	
	
	
}




	


