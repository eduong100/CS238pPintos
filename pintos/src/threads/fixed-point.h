/* Fixed point arithmetic to be used within MLFQs for computations in 
   priority, niceness, recent CPU, and  load avg per thread.
   Here, we are useing 17.14 fixed-point number reperesentaions */

#include <inttypes.h>

#define F (1 << 14)

/* Below, x and y represent fixed point numbers. n represents an integer */

int int_to_fp(int n)
{
    return n * F;
}

int fp_to_int(int x)
{
    return x / F;
}

int fp_to_int_round(int x)
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