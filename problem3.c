/* Estimate the value of pi^4/90 with relative error less than 3 times machine epsilon. */

#include <stdio.h>
#include <math.h>

int main(void)
{
    float macheps = 1.;
    float s, errmax, w;
    float err = 1;
    float exact = pow(M_PI, 4.)/90.;
    int n = 5;
    int k;
    
    /* find machine epsilon */
    while((float)(1. + macheps) != 1.)
    {
        macheps /= 2;
    }

    printf("macheps = %g\n", macheps);
    errmax = 3*macheps;
    
    /* keep summing until the error is less than 3*macheps */
    while(err >= errmax)
    {
        s = 0;
        n *= 2;
        for(k = n; k > 0; k--)
        {
            w = 1./k;
            s += w*w*w*w;
        }
        err = fabs(s - exact);
        printf("%12d %.9g %.9g %.9g %.9g\n", n, s, exact, err, errmax);
    }
    return 0;
}

