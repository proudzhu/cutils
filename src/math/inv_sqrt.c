#include <stdio.h>

float InvSqrt(float x)
{
    float xhalf = 0.5f * x;
    int i = *(int *)&x;
    i = 0x5f3759df - (i >> 1);
    x = *(float *)&i;
    x = x * (1.5f - xhalf * x * x);
    return x;
}

#ifdef INV_SQRT_MAIN
int main(void)
{
    float x_min = 0.01, x_max = 100.0, x_inc = 0.01;

    FILE *out = fopen("test_inv_sqrt.m", "w");
    fprintf(out, "clc; clear;\n\n");
    fprintf(out, "x = %f:%f:%f;\n", x_min, x_inc, x_max);
    
    fprintf(out, "invsqrt = [ ");
    for (float x = x_min; x < x_max + x_inc; x += x_inc) {
        fprintf(out, "%f ", InvSqrt(x));
    }
    fprintf(out, "];\n");
    fprintf(out, "sqrt_org = 1./sqrt(x);\n"
                 "diff = sqrt_org - invsqrt;\n"
                 "figure();\n"
                 "subplot(2, 1, 1);\n"
                 "plot(x, invsqrt, x, sqrt_org);\n"
                 "subplot(2, 1, 2);\n"
                 "plot(x, diff);\n");
    
    fclose(out);
    
    return 0;
}
#endif