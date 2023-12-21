// How does a function passed to a function macro work
// does it split on the ,

#include <stdio.h>
#define ONE(a) printf("%s\n", #a)
#define TWO(a, b) printf("%s %s\n", #a, #b)

int two(int a, int b) {
    return a + b;
}

int main() {
    ONE(hello);
    TWO(hello, world);

    // it seems to ignore , inside ()
    ONE(TWO(hello, hello));
    ONE(two(1, 2));

    // bare parens fail: TWO((1, 2));
    // empty args work:
    TWO((1, 2),);

}
