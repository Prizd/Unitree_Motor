#include <iostream>
#include "Go1.h"

SerialPort  Go1_motor::serial("/dev/ttyUSB0");// serial port
GO1 Go1;
int main() {
	while(true){
		Go1[0].set_motor(0.,0.0,0.0,0.0,0.0);
		std::cout <<  std::endl;
		std::cout <<  "motor.q: "    << Go1[0].get_data().q    <<  std::endl;
		std::cout <<  "motor.temp: "   << Go1[0].get_data().temp   <<  std::endl;
		std::cout <<  "motor.W: "      << Go1[0].get_data().dq      <<  std::endl;
		std::cout <<  "motor.tau: "     << Go1[0].get_data().tau      <<  std::endl;
		std::cout <<  "motor.merror: " << Go1[0].get_data().merror <<  std::endl;
		std::cout <<  "motor.footForce: "      << Go1[0].get_data().footForce      <<  std::endl;
		std::cout <<  std::endl;
	}	


}