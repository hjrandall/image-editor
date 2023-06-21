#include "ComplexFractal.h"
#include <cmath>
ComplexFractal::ComplexFractal( ): ThreadedGrid(200,300), mMin_x(-1.5),mMax_x(1.5),mMin_y(-1), mMax_y(1),mDelta_x(.01),mDelta_y(.01){

}
ComplexFractal::ComplexFractal( const int& height, const int& width, const double& min_x, const double& max_x, const double& min_y, const double& max_y ):ThreadedGrid(height,width),mMin_x(min_x),mMax_x(max_x),mMin_y(min_y),mMax_y(max_y),mDelta_x(.01),mDelta_y(.01){

}
ComplexFractal::~ComplexFractal( ){

}
double ComplexFractal::getMinX( ) const{
    return mMin_x;
}
double ComplexFractal::getMaxX( ) const{
    return mMax_x;
}
double ComplexFractal::getMinY( ) const{
    return mMin_y;
}
double ComplexFractal::getMaxY( ) const{
    return mMax_y;
}
void ComplexFractal::setGridSize( const int& height, const int& width ){
    if (height>=2 && width>=2){
        NumberGrid::setGridSize(height,width);
        double delta_x=calculateDeltaX();
        double delta_y=calculateDeltaY();
        setDeltas(delta_x,delta_y);
    }
}
void ComplexFractal::setPlaneSize( const double& min_x, const double& max_x, const double& min_y, const double& max_y ){
    if (min_x==max_x || min_y==max_y){
        return;
    }
    else if (min_x>=-2.0 && min_x<=2.0 && max_x<=2.0 && max_x>=-2.0 && min_y>=-2.0 && min_y<=2.0 && max_y<=2.0 && max_y>=-2.0){
        if (min_x>max_x){
            mMin_x=max_x;
            mMax_x=min_x;
        }
        else{
            mMin_x=min_x;
            mMax_x=max_x;
        }
        if(min_y>max_y){
            mMin_y=max_y;
            mMax_y=min_y;
        }
        else{
            mMin_y=min_y;
            mMax_y=max_y;
        }
        double delta_x=calculateDeltaX();
        double delta_y=calculateDeltaY();
        setDeltas(delta_x,delta_y);

        
    }
}
 

double ComplexFractal::getDeltaX( ) const{
    return mDelta_x;
}
double ComplexFractal::getDeltaY( ) const{
    return mDelta_y;
}
void ComplexFractal::setDeltas( const double& delta_x, const double& delta_y ){
    if (delta_x>0 && delta_y>0){
        mDelta_x=delta_x;
        mDelta_y=delta_y;
    }
}
double ComplexFractal::calculateDeltaY( ) const{
    return (mMax_y-mMin_y)/(mHeight-1);
}
double ComplexFractal::calculateDeltaX( ) const{
    return (mMax_x-mMin_x)/(mWidth-1);
}
double ComplexFractal::calculatePlaneXFromPixelColumn( const int& column ) const{
    if (column<0 || column>= mWidth){
        return 0;
    }
    else{
        return mMin_x+(column*getDeltaX());
    }
}
double ComplexFractal::calculatePlaneYFromPixelRow( const int& row ) const{
    if (row<0 || row>= mHeight){
        return 0;
    }
    else{
        return mMax_y-(row*getDeltaY());
    }
}
void ComplexFractal::calculatePlaneCoordinatesFromPixelCoordinates( const int& row, const int& column, double& x, double& y ) const{
    x=calculatePlaneXFromPixelColumn(column);
    y=calculatePlaneYFromPixelRow(row);
    if (x==0 || y==0){
        x=0;
        y=0;
    }
}
int ComplexFractal::calculateNumber( const int& row, const int& column ) const{
    double x,y;
    calculatePlaneCoordinatesFromPixelCoordinates(row,column,x,y);
    if (x==0 || y==0){
        return -1;
    }
    else{
        return std::abs(getMaxNumber() * std::sin(10*x) * std::cos(10*y));
    }

}

