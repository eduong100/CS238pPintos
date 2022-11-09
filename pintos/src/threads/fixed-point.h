/* Fixed point arithmetic to be used within MLFQs for computations in 
   priority, niceness, recent CPU, and  load avg per thread.
   Here, we are useing 17.14 fixed-point number reperesentaions */

#include <inttypes.h>

#define F (1 << 14)
#define INT_MAX ((1 << 31) - 1)
#define INT_MIN (-(1<<31))

/* Below, x and y represent fixed point numbers. n represents an integer */

int int_to_fp(int n)
{
    return n * F;
}

int fp_to_int_floor(int x)
{
    return x / F;
}

int fp_to_int_roun(int x)
{
    if (x >= 0)
    {
        return (x + F / 2) / F;
    }
    else
    {
        return (x - F / 2) / F;
    }
}

int add_fp(int x, int y)
{
    return x + y;
}

int subtract_fp(int x, int y)
{
    return x - y;
}

int add_mixed(int x, int n)
{
    return x + n * F;
}

int subtract_mixed(int x, int n)
{
    return x - n * F;
}

int multiply_fp(int x, int y)
{
    return ((int64_t)x) * y/F;
}

int multiply_mixed(int x, int n)
{
    return x * n;
}

int divide_fp(int x, int y)
{
    return ((int64_t)x) * F/y;
}

int divide_mixed(int x, int n)
{
    return x / n;
}