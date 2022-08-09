#ifndef RGB_H
#define RGB_H

#include <vector>
#include <iostream>

class RGB //Pixel//Color
{
public:
    RGB();
    RGB(unsigned char value);
    RGB(unsigned char r, unsigned char g, unsigned char b);

    const unsigned char& operator[](unsigned index) const {return Channels[index];}
    unsigned char& operator[](unsigned index) {return Channels[index];}

    friend std::ostream& operator<<(std::ostream&  output, const RGB& rgb)
    {
        output<<static_cast<unsigned>(rgb.Channels[0])<<" "<<static_cast<unsigned>(rgb.Channels[1])<<" "<<static_cast<unsigned>(rgb.Channels[2]);
        return output;
    }

private:

    std::vector<unsigned char> Channels{}; //vector size 3

};

RGB::RGB(): Channels{std::vector<unsigned char>(3, {})}
{

}

RGB::RGB(unsigned char value): Channels{std::vector<unsigned char>(3, value)}
{

}

RGB::RGB(unsigned char r, unsigned char g, unsigned char b): Channels{r, g, b}
{

}

#endif // RGB_H
