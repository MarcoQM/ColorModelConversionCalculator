#ifndef XYZ_H
#define XYZ_H

#include <vector>
#include <iostream>

class XYZ //Pixel//Color
{
public:
    XYZ();
    XYZ(float x, float y, float z);

    const float& operator[](unsigned index) const {return Channels[index];}
    float& operator[](unsigned index) {return Channels[index];}

    friend std::ostream& operator<<(std::ostream&  output, const XYZ& xyz)
    {
        output<<xyz.Channels[0]<<" "<<xyz.Channels[1]<<" "<<xyz.Channels[2];
        return output;
    }

private:

    std::vector<float> Channels{}; //vector size 3

};

XYZ::XYZ(): Channels{std::vector<float>(3, {})}
{

}

XYZ::XYZ(float x, float y, float z): Channels{x, y, z}
{

}

#endif // XYZ_H
