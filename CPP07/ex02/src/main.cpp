#include "Array.tpp"

int	main( void )
{
	int * a = new int();
	std::cout << a << std::endl;

	delete (a);

	Array<int> arra(9);

	for (int i = 0; i < 9; i++) {
		arra[i] = i;
	}

	for (int i = 0; i < 9; i++) {
		std::cout << "arra[i] = "<< arra[i] << " " << std::endl;
	}

	std::cout  << std::endl;

	Array<int> arraarra(arra);
	arraarra[0] = 42;

	Array<int> arraarraarra;
	arraarraarra = arra;

	try
	{
		arra[19] = 666;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		arra[-1] = -666;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "arra[0] = " << arra[0] << std::endl;
	std::cout << "arraarra[0] = " << arraarra[0] << std::endl;
	std::cout << "arraarraarra[8] = " << arraarraarra[8] << std::endl;
	std::cout << "size : " << arra.getSize() << std::endl;

	Array<std::string> UwU(18);
	UwU[0] = "Never";
	UwU[1] = "gonna";
	UwU[2] = "give";
	UwU[3] = "you";
	UwU[5] = "\n";
	UwU[6] = "Some";
	UwU[7] = "...";
	UwU[8] = "...";
	UwU[9] = "...";
	UwU[10] = "...";
	UwU[11] = "...";
	UwU[12] = "...";
	UwU[13] = "...";
	UwU[14] = "BODY";
	UwU[15] = "ONCE";
	UwU[16] = "TOLD";
	UwU[17] = "ME";

	for (unsigned int i= 0; i < UwU.getSize(); i++)
		std::cout << UwU[i] << " ";

	return (0);
}