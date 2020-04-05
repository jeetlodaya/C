#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <math.h>

#define RESOLUTION_X 640
#define RESOLUTION_Y 480
#define SCALE 0.1
#define MANDELBROT_START_REAL -0.16
#define MANDELBROT_START_IMG -0.9
#define MANDELBROT_STEP_REAL SCALE/RESOLUTION_X
#define MANDELBROT_STEP_IMG SCALE/RESOLUTION_Y
#define MANDELBROT_ITERATIONS 1023

int count;

struct complex
{
    double real;
    double img;
};

complex complex_square(complex no)
{
    complex result;
    result.real = (no.real)*(no.real) - (no.img)*(no.img);
    result.img = 2*(no.real)*(no.img) ;
    return result;
}

complex complex_addition(complex no_1,complex no_2)
{
    complex result;
    result.real = (no_1.real) + (no_2.real);
    result.img = (no_1.img) + (no_2.img);
    return result;
}

double complex_magnitude(complex no)
{
    double result;
    result = sqrt((no.real)*(no.real) + (no.img)*(no.img));
    return result;
}

int divergence(complex no)
{
    count = 0 ;
    complex result;
    result.real = 0;
    result.img = 0;

    do
    {
        result = complex_addition(complex_square(result),no) ;
        if(complex_magnitude(result) >= 2.0)
                         break;
    }while(++count < MANDELBROT_ITERATIONS);

    if(count == MANDELBROT_ITERATIONS)
        return 0;
    else
        return 1 ;
}

void mandelbrot()
{
    complex no;
    no.real = MANDELBROT_START_REAL;
    no.img = MANDELBROT_START_IMG;

    for(int y = RESOLUTION_Y - 1;y >= 0;y--)
    {
        for(int x = 0;x < RESOLUTION_X;x++)
        {
            if(divergence(no) == 1)
            {

                   putpixel(x,y,(int)((log(count)/7)*14 + 1));
            }
                no.real = no.real + (double)MANDELBROT_STEP_REAL;

        }
            no.real = MANDELBROT_START_REAL ;
            no.img = no.img + (double)MANDELBROT_STEP_IMG;
    }
}

int main( )
{
    initwindow(RESOLUTION_X,RESOLUTION_Y);
    mandelbrot();
    getch();
    closegraph();
    return 0;
}
