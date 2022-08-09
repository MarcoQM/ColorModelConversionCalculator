#ifndef CMYK_H
#define CMYK_H

#include <vector>
#include <iostream>

class CMYK //Pixel//Color
{
public:
    CMYK();
    CMYK(float c, float m, float y, float k);

    const float& operator[](unsigned index) const {return Channels[index];}
    float& operator[](unsigned index) {return Channels[index];}

    friend std::ostream& operator<<(std::ostream&  output, const CMYK& cmyk)
    {
        output<<cmyk.Channels[0]<<" "<<cmyk.Channels[1]<<" "<<cmyk.Channels[2]<<" "<<cmyk.Channels[3];
        return output;
    }

private:

    std::vector<float> Channels{}; //vector size 4

};

CMYK::CMYK(): Channels{std::vector<float>(4, {})}
{

}

CMYK::CMYK(float c, float m, float y, float k): Channels{c, m, y, k}
{

}
#endif // CMYK_H
