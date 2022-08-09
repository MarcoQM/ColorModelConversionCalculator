#ifndef CMYK_H
#define CMYK_H

#include <vector>
#include <iostream>

template<typename Type=float>
class CMYK //Pixel//Color
{
public:
    CMYK();
    CMYK(Type c, Type m, Type y, Type k);

    const Type& operator[](unsigned index) const {return Channels[index];}
    Type& operator[](unsigned index) {return Channels[index];}


    using ValueType = Type;

    friend std::ostream& operator<<(std::ostream&  output, const CMYK<Type>& cmyk)
    {
        output<<static_cast<float>(cmyk.Channels[0])<<" "<<static_cast<float>(cmyk.Channels[1])<<" "<<static_cast<float>(cmyk.Channels[2])<<" "<<static_cast<float>(cmyk.Channels[3]);
        return output;
    }

private:

    std::vector<Type> Channels{}; //vector size 4

};

template<typename Type>
CMYK<Type>::CMYK(): Channels{std::vector<Type>(4, {})}
{

}

template<typename Type>
CMYK<Type>::CMYK(Type c, Type m, Type y, Type k): Channels{c, m, y, k}
{

}
#endif // CMYK_H
