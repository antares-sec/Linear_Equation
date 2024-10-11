#ifndef LINEAR_EQ
#define LINEAR_EQ

// Library
#include <iostream>
#include <vector>


/*
    For simplicity, we only used two points
    (y1, y2)
    (x1, x2)
*/

class LinearEquation{
    public:
        // Have many values in each point of x and y
        // Both are dynamic array
        std::vector<int> koef_x_;
        std::vector<int> koef_y_;

        // There's an error in constructor
        const void setValue(std::vector<int> arr_x, std::vector<int> arr_y){
            koef_x_ = arr_x;
            koef_y_ = arr_y;
        }

        const void print_coord(){
            for(int i = 0; i < koef_x_.size(); i++){
                std::cout << "X" << i << " and Y" << i << " " << koef_x_[i] << " , " << koef_y_[i] << std::endl; 
            }
        }
};


class TwoFormPoint : public LinearEquation{
    public:
        using LinearEquation::setValue;

    const void setValue(std::vector<int> arr_x, std::vector<int> arr_y){
            koef_x_ = arr_x;
            koef_y_ = arr_y;
    }

    bool check_x_values() const{
        if(koef_x_[0] != koef_x_[1]){
            return true;
        }else{
            return false;
        }
    }

    // Symmetric Points
    double sym_calculate_x(int y) const{
        double x_result = koef_x_[0] + static_cast<double>(y - koef_y_[0]) * (koef_x_[1] - koef_x_[0]) / (koef_y_[1] - koef_y_[0]);
        return x_result; 
    }

    double sym_calculate_y(int x) const{
        double y_result = koef_y_[0] + static_cast<double>(koef_y_[1] - koef_y_[0]) / (koef_x_[1] - koef_x_[0]) * (x - koef_x_[0]);
        return y_result;
    }

    void symmetric_point(const std::vector<int>& epochs) const{
        if(check_x_values()){
            for(int i = 0; i < epochs.size(); i++){
                float x = sym_calculate_x(epochs[i]);
                float y = sym_calculate_y(epochs[i]);

                std::cout << "Testing X - Epoch " << i + 1 << " : " << x << std::endl;
                std::cout << "Testing Y - Epoch " << i + 1 << " : " << y << std::endl;
                std::cout << std::endl;
            }
        }
    }

    // Asymmetric_point
    double asym_calculate_x(int y) const{
        
    }



    void asymmetric_point(const std::vector<int>& epochs) const{

    }

};


#endif