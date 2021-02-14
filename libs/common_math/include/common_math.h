#ifndef _COMMON_MATH_H_
#define _COMMON_MATH_H_

#include <cmath>
//Useful macros
#ifdef _USE_MATH_HELPERS_

#define SQR(x) ((x)*(x))

#define CUBE(x) ((x)*(x)*(x))

#define N_ROOT(x, n) ((x) < 0 && (n)&1 ? -pow(abs(x), 1.0/(n)) : pow(x, 1.0/(n)))

#define ODD_NUM(n) ((n)&1)

#define EVN_NUM(n) (!(ODD_NUM(n)))

#define DEVIATE_EPS(y1, y2) (100.0*abs((y1)-(y2))/abs(y1))

#endif

namespace common {
    namespace math {
        typedef double (*func1_t)(double);
        typedef double (*func2_t)(double, double);
        typedef double (*funcp_t)(double, void*);

        typedef double (*sequenct_item_t)(double x, int n);

        int generate_random(int, int, bool exclusive = false);

        double generate_random(double, double);

        double compute_sequence_value(double, double, sequenct_item_t, int start_pos = 0, int count = 100);
    }
}

#endif //CPP_BASIC_COMMON_MATH_H
