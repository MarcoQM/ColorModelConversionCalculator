#ifndef LAB_H
#define LAB_H

#include <vector>
#include <iostream>

class LAB //Pixel//Color
{
public:
    LAB();
    LAB(float l, float a, float b);

    const float& operator[](unsigned index) const {return Channels[index];}
    float& operator[](unsigned index) {return Channels[index];}

    friend std::ostream& operator<<(std::ostream&  output, const LAB& lab)
    {
        output<<lab.Channels[0]<<" "<<lab.Channels[1]<<" "<<lab.Channels[2];
        return output;
    }

private:

    std::vector<float> Channels{}; //vector size 3

};

LAB::LAB(): Channels{std::vector<float>(3, {})}
{

}

LAB::LAB(float l, float a, float b): Channels{l, a, b}
{

}

#endif // LAB_H
