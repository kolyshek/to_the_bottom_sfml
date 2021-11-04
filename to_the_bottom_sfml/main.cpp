#include "Programm.hpp"

int main()
{
	srand(static_cast<unsigned int>(time(0)));

	kp::Programm programm;

	programm.run();

	return EXIT_SUCCESS;
}