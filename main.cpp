#include <iostream>
#include <cmath>


float moduloOperator(float a, float b)
{
    return a - b * std::floor(a/b);
}

void RGBtoGrayV1(unsigned r, unsigned g, unsigned b)
{
    float y = (r+g+b)/3.0f;
    std::cout<<y<<" "<<y<<" "<<y<<std::endl;
}

void RGBtoGrayV2(unsigned r, unsigned g, unsigned b)
{
    float y = 0.299f*r + 0.587f*g + 0.114f*b;
    float s = 0.3f;
    unsigned Rdesat = y + s*(r-y);
    unsigned Gdesat = y + s*(g-y);
    unsigned Bdesat = y + s*(b-y);

    std::cout<<Rdesat<<" "<<Gdesat<<" "<<Bdesat<<std::endl;
}

void RGBtoGrayV3(unsigned r, unsigned g, unsigned b)
{
    unsigned y = 0;
    y = 0.2126f*r + 0.7152f*g + 0.0722f*b;


    std::cout<<y<<" "<<y<<" "<<y<<std::endl;
}

void RGBtoHSV(unsigned r, unsigned g, unsigned b)
{
    float cHigh = std::max(r, std::max(g, b));
    float cLow = std::min(r, std::min(g, b));
    float cRng = cHigh - cLow;
    float h = 0.0f;
    float s = 0.0f;
    float v = 0.0f;
    float cMax = 255.0f;

    //calculando v
    v = cHigh / cMax;

    //calculando h
    if(cHigh > 0)
        s = cRng / cHigh;

    //calculando h, definiendo el tono solo para pixeles de color
    if(cRng > 0)
    {
        float rr = (cHigh - r) / cRng;
        float gg = (cHigh - g) / cRng;
        float bb = (cHigh - b) / cRng;
        float hh;

        if(r == cHigh)
            hh = bb - gg;
        else if(g == cHigh)
            hh = rr - bb + 2.0f;
        else if(b == cHigh)
            hh = gg - rr + 4.0f;

        if(hh < 0.0f)
            hh = hh + 6.0f;
        h = hh / 6.0f;
    }

    std::cout<<h<<" "<<s<<" "<<v<<std::endl;

    //Formato grados y porcentaje
    /*float hDegrees = h * 360;
    float sPercent = s * 100;
    float vPercent = v * 100;

    std::cout<<hDegrees<<" "<<sPercent<<" "<<vPercent<<std::endl;*/

}

void HSVtoRGB(float h, float s, float v)
{
    unsigned r = 0;
    unsigned g = 0;
    unsigned b = 0;

    float rr = 0.0f;
    float gg = 0.0f;
    float bb = 0.0f;

    float hh = moduloOperator(6.0f * h, 6.0f);

    unsigned c1 = std::floor(hh);
    float c2 = hh - c1;

    float x = (1.0f - s) * v;
    float y = (1.0f - (s * c2)) * v;
    float z = (1.0f - (s * (1.0f - c2))) * v;

    switch (c1) {
    case 0: rr = v; gg = z; bb = x; break;
    case 1: rr = y; gg = v; bb = x; break;
    case 2: rr = x; gg = v; bb = z; break;
    case 3: rr = x; gg = y; bb = v; break;
    case 4: rr = z; gg = x; bb = v; break;
    case 5: rr = v; gg = x; bb = y; break;
    }

    r = std::min(std::round(255.0f * rr), 255.0f);
    g = std::min(std::round(255.0f * gg), 255.0f);
    b = std::min(std::round(255.0f * bb), 255.0f);

    std::cout<<r<<" "<<g<<" "<<b<<std::endl;
}


void RGBtoHSL(unsigned r, unsigned g, unsigned b)
{
    float cHigh = std::max(r, std::max(g, b));
    float cLow = std::min(r, std::min(g, b));
    float cRng = cHigh - cLow;

    //calculando l
    float l = ((cHigh + cLow) / 255.0f) / 2;

    //calculando s
    float s = 0;
    if(0 < l && l < 1)
    {
        float d = (l <= 0.5f) ? l : (1 - l);
        s = 0.5f * (cRng / 255.0f) / d;
    }

    //calculando h
    float h = 0.0f;
    if(cHigh > 0.0f && cRng > 0.0f) //Para pixeles de color
    {
        float rr = (cHigh - r) / cRng;
        float gg = (cHigh - g) / cRng;
        float bb = (cHigh - b) / cRng;
        float hh;

        if(r == cHigh)
            hh = bb - gg;
        else if(g == cHigh)
            hh = rr - bb + 2.0f;
        else if(b == cHigh)
            hh = gg - rr + 4.0f;

        if(hh < 0)
            hh = hh + 6.0f;
        h = hh / 6.0f;
    }

    std::cout<<h<<" "<<s<<" "<<l<<std::endl;

}

void HSLtoRGB(float h, float s, float l)
{
    unsigned r = 0;
    unsigned g = 0;
    unsigned b = 0;

    float rr = 0.0f;
    float gg = 0.0f;
    float bb = 0.0f;

    if(l <= 0.0f)
    {
        rr = 0.0f;
        gg = 0.0f;
        bb = 0.0f;
    }
    else if(l >= 1.0f)
    {
        rr = 1.0f;
        gg = 1.0f;
        bb = 1.0f;
    }
    else
    {
        float hh = moduloOperator((6.0f * h), 6.0f);
        unsigned c1 = hh;
        float c2 = hh - c1;
        float d = (l <= 0.5f) ? (s * l) : (s * (1.0f - l));
        float w = l + d;
        float x = l - d;
        float y = w - (w - x) * c2;
        float z = x + (w - x) * c2;
        switch (c1) {
        case 0: rr = w; gg = z; bb = x; break;
        case 1: rr = y; gg = w; bb = x; break;
        case 2: rr = x; gg = w; bb = z; break;
        case 3: rr = x; gg = y; bb = w; break;
        case 4: rr = z; gg = x; bb = w; break;
        case 5: rr = w; gg = x; bb = y; break;
        }
    }
    r = std::min(std::round(255.0f * rr), 255.0f);
    g = std::min(std::round(255.0f * gg), 255.0f);
    b = std::min(std::round(255.0f * bb), 255.0f);

    std::cout<<r<<" "<<g<<" "<<b<<std::endl;
}

void RGBtoCMYKv1(unsigned r, unsigned g, unsigned b)
{
    float c = 1.0f - (r / 255.0f);
    float m = 1.0f - (g / 255.0f);
    float y = 1.0f - (b / 255.0f);
    float k = std::min(c, std::min(m, y));

    std::cout<<c<<" "<<m<<" "<<y<<" "<<k<<std::endl;
}

void CMYKv1toRGB(float c2, float m2, float y2, float k2)
{
    unsigned r = 255.0f * (1.0f - c2);
    unsigned g = 255.0f * (1.0f - m2);
    unsigned b = 255.0f * (1.0f - y2);

    std::cout<<r<<" "<<g<<" "<<b<<std::endl;
}

void RGBtoCMYKv2(unsigned r, unsigned g, unsigned b)
{
    float c = 1.0f - (r / 255.0f);
    float m = 1.0f - (g / 255.0f);
    float y = 1.0f - (b / 255.0f);
    float k = std::min(c, std::min(m, y));

    float s = (k < 1.0f) ? (1.0f / (1.0f - k)) : 1.0f;
    float c2 = (c - k) * s;
    float m2 = (m - k) * s;
    float y2 = (y - k) * s;
    float k2 = k;

    std::cout<<c2<<" "<<m2<<" "<<y2<<" "<<k2<<std::endl;
}

void CMYKv2toRGB(float c2, float m2, float y2, float k2)
{
    unsigned r = 255.0f * (1.0f - c2) * (1.0f - k2);
    unsigned g = 255.0f * (1.0f - m2) * (1.0f - k2);
    unsigned b = 255.0f * (1.0f - y2) * (1.0f - k2);

    std::cout<<r<<" "<<g<<" "<<b<<std::endl;
}

void RGBtoCMYKv3(unsigned r, unsigned g, unsigned b)
{
    float sk = 0.1f;
    float k0 = 0.3;
    float kMax = 0.9;

    float c = 1.0f - (r / 255.0f);
    float m = 1.0f - (g / 255.0f);
    float y = 1.0f - (b / 255.0f);
    float k = std::min(c, std::min(m, y));

    float c3 = c - (sk * k);
    float m3 = m - (sk * k);
    float y3 = y - (sk * k);
    float k3 = (k >= k0) ? (kMax * (k - k0) / (1.0f - k0)) : 0.0f;

    std::cout<<c3<<" "<<m3<<" "<<y3<<" "<<k3<<std::endl;
}

void CMYKv3toRGB(float c3, float m3, float y3, float k3)
{
    float k0 = 0.3;
    float kMax = 0.9;
    float sk = 0.1;

    float k = (k3 > 0) ? ((k3 * (1 - k0) / kMax) + k0) : 0;
    float c = c3 + (sk * k);
    float m = m3 + (sk * k);
    float y = y3 + (sk * k);

    unsigned r = 255.0f * (1 - c);
    unsigned g = 255.0f * (1 - m);
    unsigned b = 255.0f * (1 - y);

    std::cout<<r<<" "<<g<<" "<<b<<std::endl;
}

void RGBtoXYZ(unsigned r, unsigned g, unsigned b)
{
    float rr = r / 255.0f;
    float gg = g / 255.0f;
    float bb = b / 255.0f;

    auto cLinear = [](float cl)
    {
        return (cl <= 0.04045) ? (cl / 12.92) : std::pow((cl + 0.055) / 1.055, 2.4);
    };

    float rLinear = cLinear(rr);
    float gLinear = cLinear(gg);
    float bLinear = cLinear(bb);

    // x, y, z en D65
    float x = 0.4124 * rLinear + 0.3576 * gLinear + 0.1805 * bLinear;
    float y = 0.2126 * rLinear + 0.7152 * gLinear + 0.0722 * bLinear;
    float z = 0.0193 * rLinear + 0.1192 * gLinear + 0.9505 * bLinear;

    std::cout<<x<<" "<<y<<" "<<z<<std::endl;
}

void XYZtoRGB(float x, float y, float z)
{
    auto cRGB = [](float cl)
    {
        return (cl <= 0.0031308) ? (12.92 * cl) : (1.055 * std::pow(cl, 1 / 2.4)) - 0.055;
    };

    //x, y, z estan en D65
    float rLinear = 3.2406 * x - 1.5372 * y - 0.4986 * z;
    float gLinear = -0.9689 * x + 1.8758 * y + 0.0415 * z;
    float bLinear = 0.0557 * x - 0.2040 * y + 1.0570 * z;

    unsigned r = cRGB(rLinear) * 255;
    unsigned g = cRGB(gLinear) * 255;
    unsigned b = cRGB(bLinear) * 255;

    std::cout<<r<<" "<<g<<" "<<b<<std::endl;
}

void XYZtoLAB(float x, float y, float z)
{
    auto ft = [](float t)
    {
        float delta = 6.0f / 29.0f;
        return (t > std::pow(delta, 3.0f)) ? (std::pow(t, 1.0f / 3.0f)) : ((t / (3.0f * std::pow(delta, 2.0f))) + (4.0f / 29.0f));
    };

    float xn = 95.0489f;
    float yn = 100.0f;
    float zn = 108.8840f;

    float l = 116.0f * ft(y / yn) - 16.0f;
    float a = 500.0f * (ft(x / xn) - ft(y / yn));
    float b = 200.0f * (ft(y / yn) - ft(z / zn));

    std::cout<<l<<" "<<a<<" "<<b<<std::endl;
}

void LABtoXYZ(float l, float a, float b)
{
    auto ftInv = [](float t)
    {
        float delta = 6.0f / 29.0f;
        return (t > delta) ? (std::pow(t, 3.0f)) : (3 * std::pow(delta, 2.0f) * (t - (4.0f / 29.0f)));
    };

    float xn = 95.0489f;
    float yn = 100.0f;
    float zn = 108.8840f;

    float x = xn * ftInv(((l + 16.0f) / 116.0f) + (a / 500.0f));
    float y = yn * ftInv((l + 16.0f) / 116.0f);
    float z = zn * ftInv(((l + 16.0f) / 116.0f) - (b / 200.0f));


    std::cout<<x<<" "<<y<<" "<<z<<std::endl;
}

int main(int argc, char *argv[])
{
    unsigned value1 = 0;
    unsigned value2 = 0;
    unsigned value3 = 0;
    unsigned value4 = 0;

    /*value1 = std::stoul(argv[2]);
    value2 = std::stoul(argv[3]);
    value3 = std::stoul(argv[4]);*/


    //RGBtoGrayV2(value1, value2, value3);


    return 0;
}
