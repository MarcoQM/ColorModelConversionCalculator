#include <iostream>
#include <cmath>
#include <vector>

#include "ColorConverter.h"
#include "CMYK.h"
#include "HSL.h"
#include "HSV.h"
#include "LAB.h"
#include "RGB.h"
#include "XYZ.h"

static ColorConverter calculator;

void modelRGBConverter(unsigned char r, unsigned char g, unsigned char b, std::string modelColor)
{
    RGB rgb(r, g, b);
    if(modelColor == "GrayV1")
        std::cout<<calculator.RGBtoGrayV1(rgb)<<std::endl;
    else if(modelColor == "GrayV2")
        std::cout<<calculator.RGBtoGrayV2(rgb)<<std::endl;
    else if(modelColor == "GrayV3")
        std::cout<<calculator.RGBtoGrayV3(rgb)<<std::endl;
    else if(modelColor == "hsv")
        std::cout<<calculator.RGBtoHSV(rgb)<<std::endl;
    else if(modelColor == "hsl")
        std::cout<<calculator.RGBtoHSL(rgb)<<std::endl;
    else if(modelColor == "CMYKv1")
        std::cout<<calculator.RGBtoCMYKv1(rgb)<<std::endl;
    else if(modelColor == "CMYKv2")
        std::cout<<calculator.RGBtoCMYKv2(rgb)<<std::endl;
    else if(modelColor == "CMYKv3")
        std::cout<<calculator.RGBtoCMYKv3(rgb)<<std::endl;
    else if(modelColor == "xyz")
        std::cout<<calculator.RGBtoXYZ(rgb)<<std::endl;
    else if(modelColor == "lab")
    {
        XYZ xyz = calculator.RGBtoXYZ(rgb);
        std::cout<<calculator.XYZtoLAB(xyz)<<std::endl;
    }
    else
       std::cout<<"Modelo de colo desconocido"<<std::endl;
}

void modelHSVConverter(float h, float s, float v, std::string modelColor)
{
    HSV hsv(h, s, v);
    if(modelColor == "rgb")
        std::cout<<calculator.HSVtoRGB(hsv)<<std::endl;
    else if(modelColor == "GrayV1")
    {
        RGB rgb = calculator.HSVtoRGB(hsv);
        std::cout<<calculator.RGBtoGrayV1(rgb)<<std::endl;
    }
    else if(modelColor == "GrayV2")
    {
        RGB rgb = calculator.HSVtoRGB(hsv);
        std::cout<<calculator.RGBtoGrayV2(rgb)<<std::endl;
    }
    else if(modelColor == "GrayV3")
    {
        RGB rgb = calculator.HSVtoRGB(hsv);
        std::cout<<calculator.RGBtoGrayV3(rgb)<<std::endl;
    }
    else if(modelColor == "hsl")
    {
        RGB rgb = calculator.HSVtoRGB(hsv);
        std::cout<<calculator.RGBtoHSL(rgb)<<std::endl;
    }
    else if(modelColor == "CMYKv1")
    {
        RGB rgb = calculator.HSVtoRGB(hsv);
        std::cout<<calculator.RGBtoCMYKv1(rgb)<<std::endl;
    }
    else if(modelColor == "CMYKv2")
    {
        RGB rgb = calculator.HSVtoRGB(hsv);
        std::cout<<calculator.RGBtoCMYKv2(rgb)<<std::endl;
    }
    else if(modelColor == "CMYKv3")
    {
        RGB rgb = calculator.HSVtoRGB(hsv);
        std::cout<<calculator.RGBtoCMYKv3(rgb)<<std::endl;
    }
    else if(modelColor == "xyz")
    {
        RGB rgb = calculator.HSVtoRGB(hsv);
        std::cout<<calculator.RGBtoXYZ(rgb)<<std::endl;
    }
    else if(modelColor == "lab")
    {
        RGB rgb = calculator.HSVtoRGB(hsv);
        XYZ xyz = calculator.RGBtoXYZ(rgb);
        std::cout<<calculator.XYZtoLAB(xyz)<<std::endl;
    }
    else
       std::cout<<"Modelo de colo desconocido"<<std::endl;
}

void modelHSLConverter(float h, float s, float l, std::string modelColor)
{
    HSL hsl(h, s, l);
    if(modelColor == "rgb")
        std::cout<<calculator.HSLtoRGB(hsl)<<std::endl;
    else if(modelColor == "GrayV1")
    {
        RGB rgb = calculator.HSLtoRGB(hsl);
        std::cout<<calculator.RGBtoGrayV1(rgb)<<std::endl;
    }
    else if(modelColor == "GrayV2")
    {
        RGB rgb = calculator.HSLtoRGB(hsl);
        std::cout<<calculator.RGBtoGrayV2(rgb)<<std::endl;
    }
    else if(modelColor == "GrayV3")
    {
        RGB rgb = calculator.HSLtoRGB(hsl);
        std::cout<<calculator.RGBtoGrayV3(rgb)<<std::endl;
    }
    else if(modelColor == "hsv")
    {
        RGB rgb = calculator.HSLtoRGB(hsl);
        std::cout<<calculator.RGBtoHSV(rgb)<<std::endl;
    }
    else if(modelColor == "CMYKv1")
    {
        RGB rgb = calculator.HSLtoRGB(hsl);
        std::cout<<calculator.RGBtoCMYKv1(rgb)<<std::endl;
    }
    else if(modelColor == "CMYKv2")
    {
        RGB rgb = calculator.HSLtoRGB(hsl);
        std::cout<<calculator.RGBtoCMYKv2(rgb)<<std::endl;
    }
    else if(modelColor == "CMYKv3")
    {
        RGB rgb = calculator.HSLtoRGB(hsl);
        std::cout<<calculator.RGBtoCMYKv3(rgb)<<std::endl;
    }
    else if(modelColor == "xyz")
    {
        RGB rgb = calculator.HSLtoRGB(hsl);
        std::cout<<calculator.RGBtoXYZ(rgb)<<std::endl;
    }
    else if(modelColor == "lab")
    {
        RGB rgb = calculator.HSLtoRGB(hsl);
        XYZ xyz = calculator.RGBtoXYZ(rgb);
        std::cout<<calculator.XYZtoLAB(xyz)<<std::endl;
    }
    else
       std::cout<<"Modelo de colo desconocido"<<std::endl;
}

void modelCMYKv1Converter(float c, float m, float y, float k, std::string modelColor)
{
    CMYK cmyk(c, m, y, k);
    if(modelColor == "rgb")
        std::cout<<calculator.CMYKv1toRGB(cmyk)<<std::endl;
    else if(modelColor == "GrayV1")
    {
        RGB rgb = calculator.CMYKv1toRGB(cmyk);
        std::cout<<calculator.RGBtoGrayV1(rgb)<<std::endl;
    }
    else if(modelColor == "GrayV2")
    {
        RGB rgb = calculator.CMYKv1toRGB(cmyk);
        std::cout<<calculator.RGBtoGrayV2(rgb)<<std::endl;
    }
    else if(modelColor == "GrayV3")
    {
        RGB rgb = calculator.CMYKv1toRGB(cmyk);
        std::cout<<calculator.RGBtoGrayV3(rgb)<<std::endl;
    }
    else if(modelColor == "hsv")
    {
        RGB rgb = calculator.CMYKv1toRGB(cmyk);
        std::cout<<calculator.RGBtoHSV(rgb)<<std::endl;
    }
    else if(modelColor == "hsl")
    {
        RGB rgb = calculator.CMYKv1toRGB(cmyk);
        std::cout<<calculator.RGBtoHSL(rgb)<<std::endl;
    }
    else if(modelColor == "CMYKv2")
    {
        RGB rgb = calculator.CMYKv1toRGB(cmyk);
        std::cout<<calculator.RGBtoCMYKv2(rgb)<<std::endl;
    }
    else if(modelColor == "CMYKv3")
    {
        RGB rgb = calculator.CMYKv1toRGB(cmyk);
        std::cout<<calculator.RGBtoCMYKv3(rgb)<<std::endl;
    }
    else if(modelColor == "xyz")
    {
        RGB rgb = calculator.CMYKv1toRGB(cmyk);
        std::cout<<calculator.RGBtoXYZ(rgb)<<std::endl;
    }
    else if(modelColor == "lab")
    {
        RGB rgb = calculator.CMYKv1toRGB(cmyk);
        XYZ xyz = calculator.RGBtoXYZ(rgb);
        std::cout<<calculator.XYZtoLAB(xyz)<<std::endl;
    }
    else
       std::cout<<"Modelo de colo desconocido"<<std::endl;
}

void modelCMYKv2Converter(float c, float m, float y, float k, std::string modelColor)
{
    CMYK cmyk(c, m, y, k);
    if(modelColor == "rgb")
        std::cout<<calculator.CMYKv2toRGB(cmyk)<<std::endl;
    else if(modelColor == "GrayV1")
    {
        RGB rgb = calculator.CMYKv2toRGB(cmyk);
        std::cout<<calculator.RGBtoGrayV1(rgb)<<std::endl;
    }
    else if(modelColor == "GrayV2")
    {
        RGB rgb = calculator.CMYKv2toRGB(cmyk);
        std::cout<<calculator.RGBtoGrayV2(rgb)<<std::endl;
    }
    else if(modelColor == "GrayV3")
    {
        RGB rgb = calculator.CMYKv2toRGB(cmyk);
        std::cout<<calculator.RGBtoGrayV3(rgb)<<std::endl;
    }
    else if(modelColor == "hsv")
    {
        RGB rgb = calculator.CMYKv2toRGB(cmyk);
        std::cout<<calculator.RGBtoHSV(rgb)<<std::endl;
    }
    else if(modelColor == "hsl")
    {
        RGB rgb = calculator.CMYKv2toRGB(cmyk);
        std::cout<<calculator.RGBtoHSL(rgb)<<std::endl;
    }
    else if(modelColor == "CMYKv1")
    {
        RGB rgb = calculator.CMYKv2toRGB(cmyk);
        std::cout<<calculator.RGBtoCMYKv1(rgb)<<std::endl;
    }
    else if(modelColor == "CMYKv3")
    {
        RGB rgb = calculator.CMYKv2toRGB(cmyk);
        std::cout<<calculator.RGBtoCMYKv3(rgb)<<std::endl;
    }
    else if(modelColor == "xyz")
    {
        RGB rgb = calculator.CMYKv2toRGB(cmyk);
        std::cout<<calculator.RGBtoXYZ(rgb)<<std::endl;
    }
    else if(modelColor == "lab")
    {
        RGB rgb = calculator.CMYKv2toRGB(cmyk);
        XYZ xyz = calculator.RGBtoXYZ(rgb);
        std::cout<<calculator.XYZtoLAB(xyz)<<std::endl;
    }
    else
       std::cout<<"Modelo de colo desconocido"<<std::endl;
}

void modelCMYKv3Converter(float c, float m, float y, float k, std::string modelColor)
{
    CMYK cmyk(c, m, y, k);
    if(modelColor == "rgb")
        std::cout<<calculator.CMYKv3toRGB(cmyk)<<std::endl;
    else if(modelColor == "GrayV1")
    {
        RGB rgb = calculator.CMYKv3toRGB(cmyk);
        std::cout<<calculator.RGBtoGrayV1(rgb)<<std::endl;
    }
    else if(modelColor == "GrayV2")
    {
        RGB rgb = calculator.CMYKv3toRGB(cmyk);
        std::cout<<calculator.RGBtoGrayV2(rgb)<<std::endl;
    }
    else if(modelColor == "GrayV3")
    {
        RGB rgb = calculator.CMYKv3toRGB(cmyk);
        std::cout<<calculator.RGBtoGrayV3(rgb)<<std::endl;
    }
    else if(modelColor == "hsv")
    {
        RGB rgb = calculator.CMYKv3toRGB(cmyk);
        std::cout<<calculator.RGBtoHSV(rgb)<<std::endl;
    }
    else if(modelColor == "hsl")
    {
        RGB rgb = calculator.CMYKv3toRGB(cmyk);
        std::cout<<calculator.RGBtoHSL(rgb)<<std::endl;
    }
    else if(modelColor == "CMYKv1")
    {
        RGB rgb = calculator.CMYKv3toRGB(cmyk);
        std::cout<<calculator.RGBtoCMYKv1(rgb)<<std::endl;
    }
    else if(modelColor == "CMYKv2")
    {
        RGB rgb = calculator.CMYKv3toRGB(cmyk);
        std::cout<<calculator.RGBtoCMYKv2(rgb)<<std::endl;
    }
    else if(modelColor == "xyz")
    {
        RGB rgb = calculator.CMYKv3toRGB(cmyk);
        std::cout<<calculator.RGBtoXYZ(rgb)<<std::endl;
    }
    else if(modelColor == "lab")
    {
        RGB rgb = calculator.CMYKv3toRGB(cmyk);
        XYZ xyz = calculator.RGBtoXYZ(rgb);
        std::cout<<calculator.XYZtoLAB(xyz)<<std::endl;
    }
    else
       std::cout<<"Modelo de colo desconocido"<<std::endl;
}

void modelXYZConverter(float x, float y, float z, std::string modelColor)
{
    XYZ xyz(x, y, z);
    if(modelColor == "rgb")
        std::cout<<calculator.XYZtoRGB(xyz)<<std::endl;
    else if(modelColor == "GrayV1")
    {
        RGB rgb = calculator.XYZtoRGB(xyz);
        std::cout<<calculator.RGBtoGrayV1(rgb)<<std::endl;
    }
    else if(modelColor == "GrayV2")
    {
        RGB rgb = calculator.XYZtoRGB(xyz);
        std::cout<<calculator.RGBtoGrayV2(rgb)<<std::endl;
    }
    else if(modelColor == "GrayV3")
    {
        RGB rgb = calculator.XYZtoRGB(xyz);
        std::cout<<calculator.RGBtoGrayV3(rgb)<<std::endl;
    }
    else if(modelColor == "hsv")
    {
        RGB rgb = calculator.XYZtoRGB(xyz);
        std::cout<<calculator.RGBtoHSV(rgb)<<std::endl;
    }
    else if(modelColor == "hsl")
    {
        RGB rgb = calculator.XYZtoRGB(xyz);
        std::cout<<calculator.RGBtoHSL(rgb)<<std::endl;
    }
    else if(modelColor == "CMYKv1")
    {
        RGB rgb = calculator.XYZtoRGB(xyz);
        std::cout<<calculator.RGBtoCMYKv1(rgb)<<std::endl;
    }
    else if(modelColor == "CMYKv2")
    {
        RGB rgb = calculator.XYZtoRGB(xyz);
        std::cout<<calculator.RGBtoCMYKv2(rgb)<<std::endl;
    }
    else if(modelColor == "CMYKv3")
    {
        RGB rgb = calculator.XYZtoRGB(xyz);
        std::cout<<calculator.RGBtoCMYKv3(rgb)<<std::endl;
    }
    else if(modelColor == "lab")
    {
        std::cout<<calculator.XYZtoLAB(xyz)<<std::endl;
    }
    else
       std::cout<<"Modelo de colo desconocido"<<std::endl;
}

void modelLABConverter(float l, float a, float b, std::string modelColor)
{
    LAB lab(l, a, b);
    if(modelColor == "rgb")
    {
        XYZ xyz = calculator.LABtoXYZ(lab);
        std::cout<<calculator.XYZtoRGB(xyz)<<std::endl;
    }
    else if(modelColor == "GrayV1")
    {
        XYZ xyz = calculator.LABtoXYZ(lab);
        RGB rgb = calculator.XYZtoRGB(xyz);
        std::cout<<calculator.RGBtoGrayV1(rgb)<<std::endl;
    }
    else if(modelColor == "GrayV2")
    {
        XYZ xyz = calculator.LABtoXYZ(lab);
        RGB rgb = calculator.XYZtoRGB(xyz);
        std::cout<<calculator.RGBtoGrayV2(rgb)<<std::endl;
    }
    else if(modelColor == "GrayV3")
    {
        XYZ xyz = calculator.LABtoXYZ(lab);
        RGB rgb = calculator.XYZtoRGB(xyz);
        std::cout<<calculator.RGBtoGrayV3(rgb)<<std::endl;
    }
    else if(modelColor == "hsv")
    {
        XYZ xyz = calculator.LABtoXYZ(lab);
        RGB rgb = calculator.XYZtoRGB(xyz);
        std::cout<<calculator.RGBtoHSV(rgb)<<std::endl;
    }
    else if(modelColor == "hsl")
    {
        XYZ xyz = calculator.LABtoXYZ(lab);
        RGB rgb = calculator.XYZtoRGB(xyz);
        std::cout<<calculator.RGBtoHSL(rgb)<<std::endl;
    }
    else if(modelColor == "CMYKv1")
    {
        XYZ xyz = calculator.LABtoXYZ(lab);
        RGB rgb = calculator.XYZtoRGB(xyz);
        std::cout<<calculator.RGBtoCMYKv1(rgb)<<std::endl;
    }
    else if(modelColor == "CMYKv2")
    {
        XYZ xyz = calculator.LABtoXYZ(lab);
        RGB rgb = calculator.XYZtoRGB(xyz);
        std::cout<<calculator.RGBtoCMYKv2(rgb)<<std::endl;
    }
    else if(modelColor == "CMYKv3")
    {
        XYZ xyz = calculator.LABtoXYZ(lab);
        RGB rgb = calculator.XYZtoRGB(xyz);
        std::cout<<calculator.RGBtoCMYKv3(rgb)<<std::endl;
    }
    else if(modelColor == "xyz")
    {
        std::cout<<calculator.LABtoXYZ(lab)<<std::endl;
    }
    else
       std::cout<<"Modelo de colo desconocido"<<std::endl;
}

int main(int argc, char *argv[])
{
    if(argc == 6)
    {
        std::string model1 = std::string(argv[1]);
        if(model1 == "rgb" || model1 == "GrayV1" || model1 == "GrayV2" || model1 == "GrayV3")
            modelRGBConverter(std::stoi(argv[2]), std::stoi(argv[3]), std::stoi(argv[4]), std::string(argv[5]));
        else if(model1 == "hsv")
            modelHSVConverter(std::stof(argv[2]), std::stof(argv[3]), std::stof(argv[4]), std::string(argv[5]));
        else if(model1 == "hsl")
            modelHSLConverter(std::stof(argv[2]), std::stof(argv[3]), std::stof(argv[4]), std::string(argv[5]));
        else if(model1 == "xyz")
            modelXYZConverter(std::stof(argv[2]), std::stof(argv[3]), std::stof(argv[4]), std::string(argv[5]));
        else if(model1 == "lab")
            modelLABConverter(std::stof(argv[2]), std::stof(argv[3]), std::stof(argv[4]), std::string(argv[5]));
        else
            std::cout<<"Modelo de color desconocido"<<std::endl;
    }
    else if(argc == 7)
    {
        std::string model1 = std::string(argv[1]);
        if(model1 == "CMYKv1")
            modelCMYKv1Converter(std::stof(argv[2]), std::stof(argv[3]), std::stof(argv[4]), std::stof(argv[5]), std::string(argv[6]));
        if(model1 == "CMYKv2")
            modelCMYKv2Converter(std::stof(argv[2]), std::stof(argv[3]), std::stof(argv[4]), std::stof(argv[5]), std::string(argv[6]));
        if(model1 == "CMYKv3")
            modelCMYKv3Converter(std::stof(argv[2]), std::stof(argv[3]), std::stof(argv[4]), std::stof(argv[5]), std::string(argv[6]));
    }
    else
    {
        std::cout<<"No se pudo realizar la conversión"<<std::endl;
    }
    return 0;
}
