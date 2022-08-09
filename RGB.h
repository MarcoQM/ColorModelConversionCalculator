#ifndef RGB_H
#define RGB_H

#include <vector>
#include <iostream>

template<typename Type=unsigned char> //deep
class RGB //Pixel//Color
{
public:
    RGB();
    RGB(Type value);
    RGB(Type r, Type g, Type b);

    const Type& operator[](unsigned index) const {return Channels[index];}
    Type& operator[](unsigned index) {return Channels[index];}


    using ValueType = Type;

    friend std::ostream& operator<<(std::ostream&  output, const RGB<Type>& rgb)
    {
        output<<static_cast<int>(rgb.Channels[0])<<" "<<static_cast<int>(rgb.Channels[1])<<" "<<static_cast<int>(rgb.Channels[2]);
        return output;
    }

private:

    std::vector<Type> Channels{}; //vector size 3

};

template<typename Type>
RGB<Type>::RGB(): Channels{std::vector<Type>(3, {})}
{

}

template<typename Type>
RGB<Type>::RGB(Type value): Channels{std::vector<Type>(3, value)}
{

}

template<typename Type>
RGB<Type>::RGB(Type r, Type g, Type b): Channels{r, g, b}
{

}

#endif // RGB_H
