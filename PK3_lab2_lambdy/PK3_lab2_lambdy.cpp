
#include <iostream>
#include<vector>
#include<algorithm>
#include<functional>

#define LOG(x) std::cout<< x << std::endl;

template <class T>
std::vector<T> CreateVector(const size_t size, std::function<T(const size_t)> f) {
    std::vector<T> result(size);
    for (size_t i = 0; i < size; i++)
    {
        result[i] = f(i);
    }
    return result;
}
template <class T>
void RemoveMinMax(std::vector<T>& takimalytakiduzy) {
    auto minamx = minmax_element(takimalytakiduzy.begin(), takimalytakiduzy.end();)
        std::insert(minmax.second);
}
void wypisz(const std::vector<int> v) {
    for (int i = 0; i < v.size(); i++) {
        LOG(v[i]);
    }
}
int main()
{
    auto potega = [](int x) {
        return std::pow(2, x);
    };
    std::vector<int> potegowy = CreateVector<int>(10,potega);
    wypisz(potegowy);

    std::function<int(int)> fibonaczi;
    fibonaczi = [&fibonaczi](int x) -> int {
        if ((x == 1) or (x == 0)) return x;
        else {
            return (fibonaczi(x - 1) + fibonaczi(x - 2));
        }
    };
    std::vector<int> fibonacziowy = CreateVector<int>(10, fibonaczi);
    wypisz(fibonacziowy);

    std::vector<int> zbior = {1,2,6,0,99,55,36,-4};
    RemoveMinMax(zbior);
}

