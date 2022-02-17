#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

int main(int argc, char *argv[])
{
    std::string         filename(argv[1]);
    std::string         str1(argv[2]);
    std::string         str2(argv[3]);
    std::string         data;
    std::string         outfile(filename);
    std::ofstream       ofs;
    std::ifstream       ifs;
    std::stringstream   myBuf;

//checking the args
    if (argc != 4)
    {
        std::cout << "Wrong number of args.\n Usage ./replace filename \"str1\" \"str2\""
        << std::endl;
        return (1);
    }
    if (filename.empty() || str1.empty() || str2.empty())
    {
        std::cout << "Something is wrong in args. Empty arg found\n" << std::endl;
        return (2);
    }
//opening the file 
    ifs.open(filename.c_str());
    if (!(ifs.is_open()))
    {
        std::cout << "File didnt open i guess.\n returning now..." << std::endl;
        return (3);
    }
    myBuf << ifs.rdbuf();
    data = myBuf.str();

//creating the .replace file
    outfile.append(".replaced");
    ofs.open(outfile.c_str());
    if (!(ofs.is_open()))
    {
        std::cout << "Unable to create .replaced file\n returning now" << std::endl;
        return (4);
    }

    size_t  ret_pos = 0;
    size_t  len = 0; 

//replacing str1 with strr2
    len = str1.length();
    ret_pos = data.find(str1);

    while(!(ret_pos == (size_t) -1))
    {
        data.erase(ret_pos, len);
        data.insert(ret_pos, str2);
        ret_pos = data.find(str1);
    }
    ofs << data;
    return (0);
}
