#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>

// Converts 11.5 format -> double
double fixed_to_float(int16_t input, int frc);

// Converts double to 11.5 format
int16_t float_to_fixed(double input,int frc);

int main()
{
    int16_t i1;

for(int i = 0;i <= 255;i++)
    {
        i1 = float_to_fixed((0.99*i*250.0)/(255*200.32),8);
        printf("0x%2x, ",i1 >> 8);
        printf("0x%2x, ",i1 & 0x00ff);
    }

}

inline double fixed_to_float(int16_t input,int frc)
{
    return ((double)input / (double)(1 << frc));
}

inline int16_t float_to_fixed(double input,int frc)
{
    return (int16_t)(round(input * (1 << frc)));
}




