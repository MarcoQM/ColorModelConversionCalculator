#ifndef HSL_H
#define HSL_H

#include <vector>
#include <iostream>

class HSL //Pixel//Color
{
public:
    HSL();
    HSL(float h, float c, float l);

    const float& operator[](unsigned index) const {return Channels[index];}
    float& operator[](unsigned index) {return Channels[index];}

    friend std::ostream& operator<<(std::ostream&  output, const HSL& hsl)
    {
        output<<hsl.Channels[0]<<" "<<hsl.Channels[1]<<" "<<hsl.Channels[2];
        return output;
    }

private:

    std::vector<float> Channels{}; //vector size 3

};

HSL::HSL(): Channels{std::vector<float>(3, {})}
{

}

HSL::HSL(float h, float s, float l): Channels{h, s, l}
{

}

#endif // HSL_H
