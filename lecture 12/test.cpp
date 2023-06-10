#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> v = { 1, 2, 3, 4, 5 };

    do
    {
        for (auto e : v)
            std::cout << e << " ";
        std::cout << "\n";
    } 
    while (std::next_permutation(v.begin(), v.end()));
}