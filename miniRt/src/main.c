#include "minirt.h"

int     main(int argc, char *argv[]) {

   t_tuple a;
   t_tuple b;
   t_rays c;

    a = point(1, 2, 3);
    b = vector(4, 5, 6);
    c = create_ray(a, b);

    printf("r.origine(%.0f)", c.a.x);

    return (0);
}