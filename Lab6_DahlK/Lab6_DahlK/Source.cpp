
#include <iostream>
using namespace std;
int main()
{
    int Set[8] = { 5, 10, 15, 20, 25, 30, 35, 40 };

    int* Nums = Set;

    while (Nums < &Set[7])

    {

        Nums--;

        cout << *Nums << " ";

    }

    return 0;
}