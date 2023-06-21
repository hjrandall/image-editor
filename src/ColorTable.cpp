
#include "ColorTable.h"
#include <cmath>
Color::Color( ): mRed(0),mGreen(0),mBlue(0){

}
Color::Color( const int& red, const int& green, const int& blue ):mRed(red),mGreen(green),mBlue(blue){

}
int Color::getRed( ) const{
    return mRed;
}
int Color::getGreen( ) const{
    return mGreen;
}
int Color::getBlue( ) const{
    return mBlue;
}
int Color::getChannel( const int& channel ) const{
    if (channel==0){
        return mRed;
    }
    else if (channel==1){
        return mGreen;
    }
    else if (channel==2){
        return mBlue;
    }
    else{
        return -1;
    }

}
void Color::setRed( const int& value ){
    if (value >=0){
        mRed=value;
    }

}
void Color::setGreen( const int& value ){
    if (value >=0){
        mGreen=value;
    }
}
void Color::setBlue( const int& value ){
    if (value >=0){
        mBlue=value;
    }
}
void Color::setChannel( const int& channel, const int& value ){
    if (channel==0){
        setRed(value);
    }
    else if (channel==1){
        setGreen(value);
    }
    else if (channel==2){
        setBlue(value);
    }
}
void Color::invert( const int& max_color_value ){
    if (mRed<=max_color_value && mGreen<=max_color_value && mBlue<=max_color_value){
        mRed = max_color_value-mRed;
        mGreen =max_color_value-mGreen;
        mBlue =max_color_value-mBlue;
    }
}
bool Color::operator==( const Color& rhs ) const{
    if (mRed==rhs.getRed() && mGreen == rhs.getGreen() && mBlue== rhs.getBlue()){
        return true;
    }
    else{
        return false;
    }
    
}
void Color::setFromHSV(const double& hue, const double& saturation, const double& value){
    double red= getRed();
    double green= getGreen();
    double blue= getBlue();
    HSV_to_RGB(hue,saturation,value,red,green,blue);
    setRed(red);
    setGreen(green);
    setBlue(blue);
}
void Color::getHSV(double& hue, double& saturation, double& value) const{
    double red= getRed();
    double green= getGreen();
    double blue= getBlue();
    RGB_to_HSV(red,green,blue,hue,saturation,value);
}
std::ostream& operator<<( std::ostream& os, const Color& color ){
    return os << color.getRed() <<":"<< color.getGreen()<<":"<< color.getBlue();
}




// new class 

ColorTable::ColorTable( const int& num_color ){
    mColor_List.resize(num_color);
}
int ColorTable::getNumberOfColors( ) const{
    return mColor_List.size();
}
void ColorTable::setNumberOfColors( const int& num_color ){
    mColor_List.resize(num_color);
}
const Color& ColorTable::operator[]( const int& i ) const{
    if(i<getNumberOfColors() && i>=0){
        return mColor_List[i];
    }
    else{
        static Color ec( -1, -1, -1 );
        static Color c( -1, -1, -1 );
        c = ec;
        return c;
    }
}
Color& ColorTable::operator[]( const int& i ){
    if(i<getNumberOfColors() && i>=0){
        return mColor_List[i];
    }
    else{
        static Color ec( -1, -1, -1 );
        static Color c( -1, -1, -1 );
        c = ec;
        return c;
    }
}
void ColorTable::setRandomColor( const int& max_color_value, const int& position ){
    if (position>= getNumberOfColors() || position<0  || max_color_value<0){
            return;
        
    }
    int random_num;
    for (int i=0;i<3;i++){
        if (max_color_value==0){
            mColor_List[position].setChannel(i,0);
        }
        else{
            random_num=std::rand()%max_color_value;
            mColor_List[position].setChannel(i,random_num);
        }
    }
}
double ColorTable::gradientSlope(const double y1, const double y2, const double x1, const double x2) const{
    return (y1-y2)/(x1-x2);
}
double ColorTable::gradientValue(const double y1, const double x1, const double slope, const double x) const{
    double B=y1-(slope*x1);
    double y = (slope*x)+B;
    return y;
}
void ColorTable::insertGradient( const Color& color1, const Color& color2, const int& position1, const int& position2 ){
    if (position1>=position2 || position1 >= getNumberOfColors() || position2 >= getNumberOfColors() || position1 <0){
        return;
    }
    double red_slope=gradientSlope(color1.getRed(),color2.getRed(),position1,position2);
    double green_slope=gradientSlope(color1.getGreen(),color2.getGreen(),position1,position2);
    double blue_slope=gradientSlope(color1.getBlue(),color2.getBlue(),position1,position2);
    for (int i=position1;i<=position2;i++){
        int new_red=gradientValue(color1.getRed(),position1,red_slope,i);
        int new_green=gradientValue(color1.getGreen(),position1,green_slope,i);
        int new_blue=gradientValue(color1.getBlue(),position1,blue_slope,i);
        mColor_List[i].setRed(new_red);
        mColor_List[i].setGreen(new_green);
        mColor_List[i].setBlue(new_blue);

    }

}
void ColorTable::insertHueSaturationValueGradient(const Color& color1, const Color& color2, const int& position1, const int& position2){
    if (position1>=position2 || position1 >= getNumberOfColors() || position2 >= getNumberOfColors() || position1 <0){
        return;
    }
    double hue1,saturation1,value1,hue2,saturation2,value2;
    color1.getHSV(hue1,saturation1,value1);
    color2.getHSV(hue2,saturation2,value2);
    double hue_slope=gradientSlope(hue1,hue2,position1,position2);
    double saturation_slope=gradientSlope(saturation1,saturation2,position1,position2);
    double value_slope=gradientSlope(value1,value2,position1,position2);
    for (int i=position1;i<=position2;i++){
        double new_hue=gradientValue(hue1,position1,hue_slope,i);
        double new_saturation=gradientValue(saturation1,position1,saturation_slope,i);
        double new_value=gradientValue(value1,position1,value_slope,i);
        double red,green,blue;
        HSV_to_RGB(new_hue,new_saturation,new_value,red,green,blue);
        mColor_List[i].setRed(red);
        mColor_List[i].setGreen(green);
        mColor_List[i].setBlue(blue);

    }
}
int ColorTable::getMaxChannelValue( ) const{
    int largest_num=0;
    for (int i=0;i<getNumberOfColors();i++){
        if (mColor_List[i].getRed()>largest_num){
            largest_num=mColor_List[i].getRed();
        }
        if (mColor_List[i].getGreen()>largest_num){
            largest_num=mColor_List[i].getGreen();
        }  
        if (mColor_List[i].getBlue()>largest_num){
            largest_num=mColor_List[i].getBlue();
        }  
    }
    return largest_num;
}

void HSV_to_RGB(const double& hue, const double& saturation, const double& value, double& red, double &green, double& blue) {
  /* Convert Hue, Saturation, Value to Red, Green, Blue
   * Implementation of algorithm from:
   * https://en.wikipedia.org/wiki/HSL_and_HSV#HSV_to_RGB
   *
   * Inputs and ranges:
   * 0.0 <= hue <= 360.0
   * 0.0 <= saturation <= 1.0
   * 0.0 <= value <= 1.0
   *
   * Outputs and ranges:
   * 0.0 <= red <= 255.0
   * 0.0 <= green <= 255.0
   * 0.0 <= blue <= 255.0
   */
  if(hue < 0.0 || hue > 360.0 || saturation < 0.0 || saturation > 1.0 || value < 0.0 || value > 1.0) {
    red = green = blue = 0.0;
    std::cerr << "HSV_to_RGB() input parameters out of range." << std::endl
              << " hue: " << hue  << std::endl
              << " saturation: " << saturation << std::endl
              << " value: " << value << std::endl;
    return;
  }

  // chroma selects the strength of the "primary" color of the current area of the wheel
  double chroma = value * saturation;
  // hue2 selects which 60-degree wedge of the color wheel we are in
  double hue2 = hue / 60.0;
  // x selects the strength of the "secondary" color of the current area of the wheel
  double x = chroma * ( 1 - std::abs( std::fmod( hue2, 2 ) - 1 ) );
  if( hue2 >= 0 && hue2 < 1 ) {
    red = chroma;
    green = x;
    blue = 0.0;
  } else if( hue2 >= 1 && hue2 < 2 ) {
    red = x;
    green = chroma;
    blue = 0.0;
  } else if( hue2 >= 2 && hue2 < 3 ) {
    red = 0.0;
    green = chroma;
    blue = x;
  } else if( hue2 >= 3 && hue2 < 4 ) {
    red = 0.0;
    green = x;
    blue = chroma;
  } else if( hue2 >= 4 && hue2 < 5 ) {
    red = x;
    green = 0.0;
    blue = chroma;
  } else if( hue2 >= 5 && hue2 <= 6 ) {
    red = chroma;
    green = 0.0;
    blue = x;
  } else {
    red = 0;
    green = 0;
    blue = 0;
  }

  // m scales all color channels to obtain the overall brightness.
  double m = value - chroma;
  red = 255.0*( red + m );
  green = 255.0*( green + m );
  blue = 255.0*( blue + m );
}

void RGB_to_HSV(const double& red0, const double &green0, const double& blue0, double& hue, double& saturation, double& value) {
  /* Red, Green, Blue to Convert Hue, Saturation, Value
   * Implementation of algorithm from:
   * https://en.wikipedia.org/wiki/HSL_and_HSV#From_RGB
   *
   * Inputs and ranges:
   * 0.0 <= red <= 255.0
   * 0.0 <= green <= 255.0
   * 0.0 <= blue <= 255.0
   *
   * Outputs and ranges:
   * 0.0 <= hue <= 360.0
   * 0.0 <= saturation <= 1.0
   * 0.0 <= value <= 1.0
   */
  if(red0 < 0.0 || red0 > 255.0 || green0 < 0.0 || green0 > 255.0 || blue0 < 0.0 || blue0 > 255.0) {
    hue = saturation = value = 0.0;
    std::cerr << "RGB_to_HSV() input parameters out of range." << std::endl
              << " red: " << red0  << std::endl
              << " green: " << green0 << std::endl
              << " blue: " << blue0 << std::endl;
    return;
  }

  double red   = red0 / 255.0;
  double green = green0 / 255.0;
  double blue  = blue0 / 255.0;

  // x_max helps identify the primary hue
  double x_max = red;
  if(green > x_max) { x_max = green; }
  if(blue > x_max) { x_max = blue; }
  value = x_max;

  double x_min = red;
  if(green < x_min) { x_min = green; }
  if(blue < x_min) { x_min = blue; }

  double chroma = x_max - x_min;

  if(chroma == 0) {
    hue = 0;
  } else if(value == red) {
    hue = 60.0 * (0 + (green - blue)/chroma);
  } else if(value == green) {
    hue = 60.0 * (2 + (blue - red)/chroma);
  } else if(value == blue) {
    hue = 60.0 * (4 + (red - green)/chroma);
  } else {
    hue = -720.0;
  }
  if(hue < 0.0) {
    hue += 360.0;
  }

  if(value == 0.0) {
    saturation = 0.0;
  } else {
    saturation = chroma/value;
  }

}

