#include "canvas/canvas.h"




int     main(int argc, char *argv[]) {

   t_tuple a;
   t_tuple b;
   t_tuple c;
   t_canvas d;

    a = vector(1, 2, 3);
    b = vector(2, 3, 4);
    c = crossTuples(b, a);
    
   // printf("vector(%f, %f, %f)", c.x, c.y, c.z);

    d = createCanvas(10, 20);
    assert(d.width == 10);
    assert(d.height == 20);
    for(int i  = 0; i < 10; i++)
    {
        for(int j = 0; j < 20; j++)
        {
            colorVec color = get_pixel(&d, i, j);
            // assert(color.red == 0.0);
            // assert(color.green == 0.0);
            // assert(color.blue == 0.0);
        }
    }

    colorVec red = {1, 0, 0};
    write_pixel(&d, 2, 3, red);
    // colorVec ret = get_pixel(&d, 2, 3);
    // printf("\n%f", ret.red);
    // assert(ret.red == red.red);
    // assert(ret.green == red.green);
    // assert(ret.blue == red.blue);

    return (0);
}