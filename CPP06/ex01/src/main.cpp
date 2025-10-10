#include "Serializer.hpp"

int main()
{
	Data ptr;
	uintptr_t serializedVal;
	Data *deserializedVal;

	ptr.value = 10;
	std::cout << "Data: " << ptr.value << std::endl;
	serializedVal = Serializer::serialize(&ptr);
	std::cout << "Serialized data: " << serializedVal << std::endl;
	deserializedVal = Serializer::deserialize(serializedVal);
	std::cout << "Deserialized data: " << deserializedVal->value << std::endl;
	
	std::cout << "\n" << std::endl;

	ptr.value = 42;
	serializedVal = Serializer::serialize(&ptr);
	std::cout << "Data: " << ptr.value << std::endl;
	std::cout << "Serialized data: " << serializedVal << std::endl;
	deserializedVal = Serializer::deserialize(serializedVal);
	std::cout << "Deserialized data: " << deserializedVal->value << std::endl;
}