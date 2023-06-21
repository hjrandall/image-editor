#include "NumberGrid.h"


NumberGrid::NumberGrid( ):mHeight(300),mWidth(400),mMax_color_value(255){
    mGrid.resize((mWidth*mHeight),0);
}
NumberGrid::NumberGrid( const int& height, const int& width ):mHeight(height),mWidth(width),mMax_color_value(255){
    mGrid.resize((width*height),0);
}
NumberGrid::~NumberGrid(){

}
int NumberGrid::getHeight( ) const{
    return mHeight;
}
int NumberGrid::getWidth( ) const{
     return mWidth;
}
int NumberGrid::getMaxNumber( ) const{
     return mMax_color_value;
}
void NumberGrid::setGridSize( const int& height, const int& width ){
    if (height >=2 && width>=2){
        mHeight=height;
        mWidth=width;
        mGrid.resize(mWidth*mHeight);
    }
}
void NumberGrid::setMaxNumber( const int& number ){
   if(number>=0){
        mMax_color_value=number;
        for(unsigned long i=0;i<(mGrid.size());i++){
            if (mGrid[i]>mMax_color_value){
                mGrid[i]=mMax_color_value;
            }
        }
   }
}
const std::vector< int >& NumberGrid::getNumbers( ) const{
    return mGrid;
}
int NumberGrid::index( const int& row, const int& column ) const{
    int num= (row*mWidth)+column;
    return num;
}
bool NumberGrid::indexValid( const int& row, const int& column ) const{
    if(row<mHeight && row>=0 && column<mWidth && column>=0){
        return true;
    }
    return false;
}
bool NumberGrid::numberValid( const int& number ) const{
    if (number >=0 && number<=mMax_color_value){
        return true;
    }
    return false;
}
int NumberGrid::getNumber( const int& row, const int& column ) const{
    if (indexValid(row,column)){
        return mGrid[index(row,column)];
    }
    return -1;
}
void NumberGrid::setNumber( const int& row, const int& column, const int& number ){
    if (numberValid(number) && indexValid(row,column)){
        mGrid[index(row,column)]=number;
    }
}
void NumberGrid::setPPM( PPM& ppm ) const{
    ppm.setWidth(mWidth);
    ppm.setHeight(mHeight);
    ppm.setMaxColorValue(63);
    for (int row=0;row<mHeight;row++){
        for( int column=0;column<mWidth;column++){
           int value= mGrid[index(row,column)];
            if (value==0){
                ppm.setPixel(row,column,0,0,0);
            }
           else if(value==mMax_color_value){
               ppm.setPixel(row,column,63,31,31);
           }
           else if (value%8==0){
               ppm.setPixel(row,column,63,63,63);
           }
           else if (value%8==1){
               ppm.setPixel(row,column,63,31,31);
           }
           else if (value%8==2){
               ppm.setPixel(row,column,63,63,31);
           }
           else if (value%8==3){
               ppm.setPixel(row,column,31,63,31);
           }
           else if (value%8==4){
               ppm.setPixel(row,column,0,0,0);
           }
           else if (value%8==5){
               ppm.setPixel(row,column,31,63,63);
           }
           else if (value%8==6){
               ppm.setPixel(row,column,31,31,63);
           }
           else if (value%8==7){
               ppm.setPixel(row,column,63,31,63);
           }
        }
    }
}
void NumberGrid::setPPM( PPM& ppm, const ColorTable& colors ) const{
    if (colors.getNumberOfColors()<2){
        return;
    }
    Color color;

    ppm.setHeight(mHeight);
    ppm.setWidth(mWidth);
    ppm.setMaxColorValue(colors.getMaxChannelValue());
    int color_size=colors.getNumberOfColors();
    for (int row=0;row<mHeight;row++){
        for (int column=0;column<mWidth;column++){
            int num= getNumber(row,column);
            if (num==getMaxNumber()){
                color= colors[color_size-1];
            }
            else{
                color = colors[num%color_size];
            }
            ppm.setPixel(row ,column, color.getRed(),color.getGreen(),color.getBlue());
        }
        
    }
}

void NumberGrid::calculateAllNumbers(){
    int num;
    for (int row=0;row<mHeight;row++){
        for( int column=0; column<mWidth;column++){
            num=calculateNumber(row,column);
            setNumber(row,column,num);
        }
    }
}
ManhattanNumbers::ManhattanNumbers(): NumberGrid(600,800){

}
ManhattanNumbers::ManhattanNumbers(const int& height, const int& width): NumberGrid(height,width){

}
ManhattanNumbers:: ~ManhattanNumbers(){

}
int ManhattanNumbers::calculateNumber(const int& row, const int& column) const{
    int x1=mHeight/2;
    int y1=mWidth/2;
    int x2=row;
    int y2=column;
    int d= std::abs(x2-x1)+ std::abs(y2-y1);
    return d;
}