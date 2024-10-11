#include <iostream>
#include <vector>
#include "lib/math_ml/linear_eq.hpp"


int main(){
    std::vector<int> x = {1, 10};
    std::vector<int> y = {2, 15};

    TwoFormPoint point;
    point.setValue(x, y);
    point.print_coord();
    std::vector<int> epochs = {1, 2, 3, 4, 5, 6, 7, 8, 9 , 10};

    // Check symmetric point
    point.symmetric_point(epochs);
    return 0;
}