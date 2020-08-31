#include <stdlib.h>
#include <time.h>
export module rand_gen;

namespace rand_gen {
    export int between(int start, int end)
    {
        int number;
        srand(time(NULL));
        number = rand() % end + start;
        return number;
    }
}
