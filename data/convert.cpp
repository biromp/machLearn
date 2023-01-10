#include <iostream>
#include <fstream>

std::string brandAt(int x)
{
    std::ifstream brands("brands.csv");

    std::string a;

    x = x%92;
    for (int i=0; i<=92; i++)
    {
        brands >> a;
        if (i == x)
        {
            break;
        }
    }
    brands.close();

    return a;
}

std::string countyAt(int x)
{
    std::ifstream header("header.csv");
    std::string a;

    x = x%42;
    for (int i=0; i<=42; i++)
    {
        header >> a;
        if (i == x)
        {
            break;
        }
    }
    header.close();

    return a;
}

int main(){
    std::ifstream data("data.csv");
    std::ofstream g("out.csv");
    int count = 0;

    int x;
    while (!data.eof())
    {
        data >> x;

        g << countyAt(count%42) << ", " << brandAt(count/42) << ", " << x << ",\n";
        count++;
    }

    std::cout << count;
    data.close();
    g.close();
    return 0;
}
