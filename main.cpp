#include "vector.hpp"
using namespace tmm;
void print(vector<int> v)
{
    for (size_t i = 0; i < v.size(); ++i)
    {
        std::cout << v[i] << " ";
    }
}
int main(int argc, char const *argv[])
{
    vector<int> v {1,2,3,4,5,6,7,8};
    const tmm::vector<int>::const_iterator it = v.cbegin();
    tmm::vector<int>::const_iterator it1 = v.end();
    tmm::vector<int>::const_reverse_iterator it2 = v.rbegin();
    tmm::vector<int>::reverse_iterator it3 = v.rend();
    for (size_t i = 0; i < v.size(); ++i)
    {
        std::cout << *(it + i) << " ";
    }
    std::cout << "\n";
    v.assign({23,345,456,22,433425,654,23});
    print(v);
    return 0;
}
