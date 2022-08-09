#ifndef XYZ_H
#define XYZ_H

#include <vector>
#include <iostream>

template<typename Type=float>
class XYZ //Pixel//Color
{
public:
    XYZ();
    XYZ(Type x, Type y, Type z);

    const Type& operator[](unsigned index) const {return Channels[index];}
    Type& operator[](unsigned index) {return Channels[index];}

    using ValueType = Type;

    friend std::ostream& operator<<(std::ostream&  output, const XYZ<Type>& xyz)
    {
        output<<static_cast<float>(xyz.Channels[0])<<" "<<static_cast<float>(xyz.Channels[1])<<" "<<static_cast<float>(xyz.Channels[2]);
        return output;
    }

private:

    std::vector<Type> Channels{}; //vector size 3

};

template<typename Type>
XYZ<Type>::XYZ(): Channels{std::vector<Type>(3, {})}
{

}

template<typename Type>
XYZ<Type>::XYZ(Type x, Type y, Type z): Channels{x, y, z}
{

}

#endif // XYZ_H
