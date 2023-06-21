#include "JuliaSet.h"
#include <cmath>

JuliaSet::JuliaSet( ):ComplexFractal(),mA(-0.650492),mB(-0.478235){
}
JuliaSet::JuliaSet( const int& height, const int& width, const double& min_x, const double& max_x, const double& min_y, const double& max_y, const double& a, const double& b ):ComplexFractal(height,width,min_x,max_x,min_y,max_y),mA(a),mB(b) {

}
JuliaSet::~JuliaSet( ){

}
double JuliaSet::getA( ) const{
    return mA;
}
double JuliaSet::getB( ) const{
    return mB;
}
void JuliaSet::setParameters( const double& a, const double& b ){
    if (a >=-2 && a <=2 && b >=-2 && b <=2){
        mA=a;
        mB=b;
    }
}
void JuliaSet::calculateNextPoint( const double x0, const double y0, double& x1, double &y1 ) const{
    x1 = (x0*x0 - y0*y0) + mA;
    y1 = (2*x0*y0 )+ mB;
}
int JuliaSet::calculatePlaneEscapeCount( const double& x0, const double& y0 ) const{
    double x1,y1,x2,y2;
    x1=x0;
    y1=y0;
    int escape_count=0;
    bool escaped=false;
    
    if (sqrt((x0*x0)+(y0*y0))>2){
            escaped=true;
        }
    while(escape_count < mMax_color_value && escaped==false){
        calculateNextPoint(x1,y1,x2,y2);
        x1=x2;
        y1=y2;
        double sqr=sqrt((x1*x1)+(y1*y1));
        if (sqr>2){
            escaped=true;
        }
        escape_count+=1;
    }
    return escape_count;
}
int JuliaSet::calculateNumber( const int& row, const int& column ) const{
    if (indexValid(row,column)){
        double x0,y0;
        calculatePlaneCoordinatesFromPixelCoordinates(row,column,x0,y0);
        int num_of_escapes=calculatePlaneEscapeCount(x0,y0);
        return num_of_escapes;
    }
    else{
        return -1;
    }
}