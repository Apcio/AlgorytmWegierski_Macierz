#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>

int main()
{
    std::srand(std::time(NULL));

    unsigned int width;
    unsigned int height;

    int min;
    int max;

    std::string name;

    int v;

    std::cout << "Podaj nazwe dla pliku: ";
    std::cin >> name;

    std::cout << "Podaj wartosc minimalna: ";
    std::cin >> min;

    std::cout << "Podaj wartosc maksymalna: ";
    std::cin >> max;

    std::cout << "Podaj szerokosc macierzy: ";
    std::cin >> width;

    std::cout << "Podaj wysokosc macierzy: ";
    std::cin >> height;

    std::fstream f;
    f.open(name, std::ios_base::out | std::ios_base::trunc);

    if(f.is_open() == false) return EXIT_FAILURE;

    std::cout << "\n\nLosuje wartosci do macierzy\n\n";

    for(unsigned int i = 0; i < height; ++i)
    {
        for(unsigned int j = 0; j < width; ++j)
        {
            v = (rand() % (max - min + 1) ) + min;
            std::cout << v;
            f << v;

            if( j != (width - 1) )
            {
                std::cout << " ";
                f << " ";
            }
        }

        if( i != (height - 1) )
        {
            std::cout << "\n";
            f << "\n";
        }
    }

    f.close();

    std::cout << "\n\n";
    return 0;
}

