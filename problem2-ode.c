#include <stdio.h>
#include <math.h>

#include <gsl/gsl_errno.h>
#include <gsl/gsl_odeiv2.h>

int func (double tau, const double y[], double f[],
          void *params)
{
    /*
     * y[0] - phi
     * y[1] - x
     */
    double omega = *(double *) params;

    f[0] = y[1];
    f[1] = -(1. - 0.01*omega*omega*sin(omega*tau))*sin(y[0]);

    return GSL_SUCCESS;
}
