#ifndef HSV_H
#define HSV_H

#include <vector>
#include <iostream>

template<typename Type=float>
class HSV //Pixel//Color
{
public:
    HSV();
    HSV(Type h, Type c, Type v);

    const Type& operator[](unsigned index) const {return Channels[index];}
    Type& operator[](unsigned index) {return Channels[index];}

    using ValueType = Type;

    friend std::ostream& operator<<(std::ostream&  output, const HSV<Type>& hsv)
    {
        output<<static_cast<float>(hsv.Channels[0])<<" "<<static_cast<float>(hsv.Channels[1])<<" "<<static_cast<float>(hsv.Channels[2]);
        return output;
    }

private:

    std::vector<Type> Channels{}; //vector size 3

};

template<typename Type>
HSV<Type>::HSV(): Channels{std::vector<Type>(3, {})}
{

}

template<typename Type>
HSV<Type>::HSV(Type h, Type s, Type v): Channels{h, s, v}
{

}

#endif // HSV_H
