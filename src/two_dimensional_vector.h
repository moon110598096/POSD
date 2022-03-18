#pragma once
#include<cmath>
class TwoDimensionalVector {
public:
    TwoDimensionalVector(double x, double y) {
        _x=x;
        _y=y;
    }

    double x() const {
        return _x;
    }

    double y() const {
        return _y;
    }

    double length() const {
        return pow(pow(_x,2)+pow(_y,2),0.5);
    }

    double dot(TwoDimensionalVector vec) const { 
        return vec.x()*_x+vec.y()*_y;   
    }

    double cross(TwoDimensionalVector vec) const {
        return _x*vec.y()-_y*vec.x();
    }

    TwoDimensionalVector subtract (TwoDimensionalVector vec) const {
        return TwoDimensionalVector(_x-vec.x(),_y-vec.y());
    }

    std::string info() const {
            std::stringstream ss;
            ss<<std::setprecision(2)<< std::fixed <<_x;
            std::string str=ss.str();
            str="[" +str + ",";
            ss.str("");
            ss<<std::setprecision(2)<< std::fixed <<_y;
            str+=ss.str()+"]";
            return str;
     }
private:
    double _x;
    double _y;

};