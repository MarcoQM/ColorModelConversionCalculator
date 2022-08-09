#ifndef HSV_H
#define HSV_H

#include <vector>
#include <iostream>

class HSV //Pixel//Color
{
public:
    HSV();
    HSV(float h, float c, float v);

    const float& operator[](unsigned index) const {return Channels[index];}
    float& operator[](unsigned index) {return Channels[index];}

    friend std::ostream& operator<<(std::ostream&  output, const HSV& hsv)
    {
        output<<hsv.Channels[0]<<" "<<hsv.Channels[1]<<" "<<hsv.Channels[2];
        return output;
    }

private:

    std::vector<float> Channels{}; //vector size 3

};

HSV::HSV(): Channels{std::vector<float>(3, {})}
{

}

HSV::HSV(float h, float s, float v): Channels{h, s, v}
{

}

#endif // HSV_H
