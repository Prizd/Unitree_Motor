#include <iostream>
#include "A1.h"

SerialPort  A1_motor::serial("/dev/ttyUSB0");// serial port
A1 A;
int main() {
	while(true){
		// for(int i=2;i<=4;i++){
		// 	A[i].set_motor(0.1,0.0,0.0,0.0,0.0);
		// }
		A[2].set_motor(0,0,0,0,0);
		std::cout <<  std::endl;
		std::cout <<  "motor.q: "    << A[0].get_data().q    <<  std::endl;
		std::cout <<  "motor.temp: "   << A[0].get_data().temp   <<  std::endl;
		std::cout <<  "motor.W: "      << A[0].get_data().dq      <<  std::endl;
		std::cout <<  "motor.tau: "     << A[0].get_data().tau      <<  std::endl;
		std::cout <<  "motor.merror: " << A[0].get_data().merror <<  std::endl;
		std::cout <<  "motor.footForce: "      << A[0].get_data().footForce      <<  std::endl;
		std::cout <<  std::endl;
	}	


}