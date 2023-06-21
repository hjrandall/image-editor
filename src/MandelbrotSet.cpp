#include "MandelbrotSet.h"
#include <cmath>

MandelbrotSet::MandelbrotSet( ): ComplexFractal(){

}
MandelbrotSet::MandelbrotSet( const int& height, const int& width, const double& min_x, const double& max_x, const double& min_y, const double& max_y ): ComplexFractal(height,width,min_x,max_x,min_y,max_y){

}
MandelbrotSet::~MandelbrotSet( ){

}
void MandelbrotSet::calculateNextPoint( const double x0, const double y0, const double& a, const double& b, double& x1, double &y1 ) const{
    x1 = (x0*x0 - y0*y0) + a;
    y1 = (2*x0*y0 )+ b;
}
int MandelbrotSet::calculatePlaneEscapeCount( const double& a, const double& b ) const{
    double x1,y1,x2,y2;
    x1=a;
    y1=b;
    int escape_count=0;
    bool escaped=false;
    
    if (sqrt((a*a)+(b*b))>2){
            escaped=true;
        }
    while(escape_count < mMax_color_value && escaped==false){
        calculateNextPoint(x1,y1,a,b,x2,y2);
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
int MandelbrotSet::calculateNumber( const int& row, const int& column ) const{
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
MandelbrotPower::MandelbrotPower(): MandelbrotSet(), mpower(2){

}
MandelbrotPower:: ~MandelbrotPower(){

}
double MandelbrotPower::getPower() const{
    return mpower;
}
void MandelbrotPower::setPower(const double& power){
    mpower=power;
}
void MandelbrotPower::calculateNextPoint(const double x0, const double y0, const double& a, const double& b, double& x1, double &y1) const{
    double r = sqrt( x0*x0 + y0*y0 );
    double theta = atan2( y0, x0 );
    x1 = (pow(r ,mpower)) * cos( mpower * theta ) + a;
    y1 = (pow(r ,mpower)) * sin( mpower * theta ) + b;
}

