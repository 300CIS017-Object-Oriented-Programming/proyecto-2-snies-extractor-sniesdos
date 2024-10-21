#include <iostream>
#include <fstream>
#include <string>

class GestorTxt
{
public:
    GestorTxt(const std::string &filename) : filename(filename) {}

    void write(const std::string &content)
    {
        std::ofstream file(filename, std::ios::app);
        if (file.is_open())
        {
            file << content << std::endl;
            file.close();
        }
        else
        {
            std::cerr << "Unable to open file for writing." << std::endl;
        }
    }

    void read()
    {
        std::ifstream file(filename);
        std::string line;
        if (file.is_open())
        {
            while (getline(file, line))
            {
                std::cout << line << std::endl;
            }
            file.close();
        }
        else
        {
            std::cerr << "Unable to open file for reading." << std::endl;
        }
    }

private:
    std::string filename;
};

int main()
{
    GestorTxt gestor("example.txt");

    gestor.write("Hello, world!");
    gestor.write("This is a test.");

    std::cout << "Reading from file:" << std::endl;
    gestor.read();

    return 0;
}