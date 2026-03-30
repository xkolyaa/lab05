#include <iostream>
#include "formatter_ex.h"
#include "solver.h"

int main() {
    int result = solve(2, 3);
    std::cout << format_ex(std::to_string(result)) << std::endl;
    return 0;
}
