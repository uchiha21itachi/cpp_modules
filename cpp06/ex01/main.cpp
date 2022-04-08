#include "Data.hpp"

uintptr_t   serialize(Data* ptr)
{
    uintptr_t   ret = reinterpret_cast<uintptr_t>(ptr);

    return (ret);
}

Data*       deserialize(uintptr_t raw)
{
    Data    *ret = reinterpret_cast<Data *>(raw);
    
    return (ret);
}

int main()
{
    uintptr_t   someUni;
    Data        *dataObject  = new Data;

    dataObject->num = 42;
    std::cout << "Testing the serialization and deserialization..." << std::endl;
    
    std::cout << "....Serialization..." << std::endl;
    someUni = serialize(dataObject);
    std::cout << someUni << std::endl;
    std::cout << dataObject << std::endl;
    std::cout << *(reinterpret_cast<int *>(someUni)) << std::endl;

    std::cout << "....Deserialization..." << std::endl;
    dataObject = deserialize(someUni);
    std::cout << (int*)someUni << std::endl;
    std::cout << dataObject << std::endl;
    std::cout << dataObject->num << std::endl;


    delete dataObject;

    return (0);
}