/*
 * Approximate the volume of 5-dimensional superellipsoids with exponents of 1 through 9 
 * using the monte carlo method. 
 */
#include <stdio.h>

#include <gsl/gsl_rng.h>
#include <gsl/gsl_statistics.h>

double mc_se (long m, int n, gsl_rng *r);

#define POINTS 1024       /* 2^10, initial number of random points to generate */
#define NEXP 64           /* number of experiments for each value of points */
#define M 11              /* number of different points values */

int main(void)
{
    double v[NEXP];      /* calculated volumes */
    gsl_rng *r;
    double mean, sd = 1;
    int n, j;
    unsigned long seed = 1UL;
    long p = POINTS;

    /* allocate random number generator */
    r = gsl_rng_alloc(gsl_rng_taus2);

    /* seed the random number generator */
    gsl_rng_set(r, seed);

    for (n = 1; n <= 9; n++)
    {
        while (sd >= .03)
        {
            for (j = 0; j < NEXP; j++)
            {
                /* calculate volume using Monte Carlo algorithm */
                v[j] = mc_se(p, n, r);
            }
            mean = gsl_stats_mean(v, 1, NEXP);
            sd = gsl_stats_sd_m(v, 1, NEXP, mean);
            p *= 2;
        }
        printf("%d  %10.8f   %10.8f\n", n, mean, sd);
        /* reset the standard deviation and the number of points at each iteration */
        sd = 1;
        p = POINTS;
    }

    gsl_rng_free(r);

    return(0);
}

