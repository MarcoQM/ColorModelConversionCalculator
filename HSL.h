#ifndef HSL_H
#define HSL_H

#include <vector>
#include <iostream>

template<typename Type=float>
class HSL //Pixel//Color
{
public:
    HSL();
    HSL(Type h, Type c, Type l);

    const Type& operator[](unsigned index) const {return Channels[index];}
    Type& operator[](unsigned index) {return Channels[index];}

    using ValueType = Type;

    friend std::ostream& operator<<(std::ostream&  output, const HSL<Type>& hsl)
    {
        output<<static_cast<float>(hsl.Channels[0])<<" "<<static_cast<float>(hsl.Channels[1])<<" "<<static_cast<float>(hsl.Channels[2]);
        return output;
    }

private:

    std::vector<Type> Channels{}; //vector size 3

};

template<typename Type>
HSL<Type>::HSL(): Channels{std::vector<Type>(3, {})}
{

}

template<typename Type>
HSL<Type>::HSL(Type h, Type s, Type l): Channels{h, s, l}
{

}

#endif // HSL_H
