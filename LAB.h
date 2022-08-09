#ifndef LAB_H
#define LAB_H

#include <vector>
#include <iostream>

template<typename Type=float>
class LAB //Pixel//Color
{
public:
    LAB();
    LAB(Type l, Type a, Type b);

    const Type& operator[](unsigned index) const {return Channels[index];}
    Type& operator[](unsigned index) {return Channels[index];}

    using ValueType = Type;

    friend std::ostream& operator<<(std::ostream&  output, const LAB<Type>& lab)
    {
        output<<static_cast<float>(lab.Channels[0])<<" "<<static_cast<float>(lab.Channels[1])<<" "<<static_cast<float>(lab.Channels[2]);
        return output;
    }

private:

    std::vector<Type> Channels{}; //vector size 3

};

template<typename Type>
LAB<Type>::LAB(): Channels{std::vector<Type>(3, {})}
{

}

template<typename Type>
LAB<Type>::LAB(Type l, Type a, Type b): Channels{l, a, b}
{

}

#endif // LAB_H
