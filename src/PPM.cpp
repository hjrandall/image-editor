#include "image_menu.h"

PPM::PPM():Image(){
   mMax_color_value=1;
}
PPM::PPM(const int& height, const int& width):Image(height, width){
    mMax_color_value=1;
}

int PPM::getMaxColorValue( ) const{
    return mMax_color_value;
}

bool PPM::valueValid( const int& value ) const{
    bool valid= false;
    if (value>=0 and value<=mMax_color_value){
        valid=true;
    }
    return valid;
}

void PPM::setMaxColorValue( const int& max_color_value ){
    if (max_color_value>=1 and max_color_value<=255){
        mMax_color_value=max_color_value;
    }
}

void PPM::setChannel( const int& row, const int& column, const int& channel, const int& value ){
    if (valueValid(value)){
        Image::setChannel(row,column,channel,value);
    }
}

void PPM::setPixel( const int& row, const int& column, const int& red, const int& green, const int& blue ){
    //set red green and blue 
    setChannel(row, column,0,red );
    setChannel(row, column,1,green);
    setChannel(row, column,2,blue);
}

void PPM::writeStream(std::ostream& os) const{
    os<<"P6"<<" "<<getWidth()<<" "<<getHeight()<<" "<<getMaxColorValue()<<std::endl;
    
    for (int row=0;row<(mHeight);row++){
        for (int column=0; column<(mWidth);column++){
            for (int channel=0;channel<=2;channel++){
                int num=getChannel(row,column,channel);
                unsigned char byte =num;
                os.write((char*)&byte,1);
            }
            
            
        }
    }
}
void PPM::readStream(std::istream& is){
    std::string p6;
    int width,height,max_color;
    unsigned char byte ;
    is >>p6>>width>>height>>max_color;
    setWidth(width);
    setHeight(height);
    setMaxColorValue(max_color);
    is.read((char*)&byte,1);

    for (int row=0;row<(height);row++){
        for (int column=0; column<(width);column++){
            for (int channel=0;channel<=2;channel++){
                is.read((char*)&byte,1);
                setChannel(row,column,channel,byte);
            }
        }
    }
}
bool PPM::operator==( const PPM& rhs ) const{
    int left_width= getWidth();
    int left_height=getHeight();
    int right_width= rhs.getWidth();
    int right_height=rhs.getHeight();
    if (left_width==right_width && left_height==right_height){
        return true;
    }
    return false;
}
bool PPM::operator!=( const PPM& rhs ) const{
    if (*this==rhs){
        return false;
    }
    return true;
}
bool PPM::operator<( const PPM& rhs ) const{
    int left_pixels=getHeight()*getWidth();
    int right_pixels=rhs.getHeight()*rhs.getWidth();
    if (left_pixels<right_pixels){
        return true;
    }
    return false;
}
bool PPM::operator<=( const PPM& rhs ) const{
    if (*this<rhs || *this==rhs){
        return true;
    }
    return false;

}
bool PPM::operator>( const PPM& rhs ) const{
    if (rhs<*this){
        return true;
    }
    return false;
}
bool PPM::operator>=( const PPM& rhs ) const{
    if (rhs<=*this){
        return true;
    }
    return false;
}
PPM& PPM::operator+=( const PPM& rhs ){
    for (int row=0;row<getHeight();row++){
        for (int column=0;column<getWidth();column++){
            for (int channel=0;channel<3;channel++){
                int lh_value=getChannel(row,column,channel);
                int rh_value=rhs.getChannel(row,column,channel);
                int new_value=lh_value+rh_value;
                if (new_value>getMaxColorValue()){
                    new_value=getMaxColorValue();
                }
                setChannel(row,column,channel,new_value);
            }
        }
    }
    return *this;
}
PPM& PPM::operator-=( const PPM& rhs ){
    for (int row=0;row<getHeight();row++){
        for (int column=0;column<getWidth();column++){
            for (int channel=0;channel<3;channel++){
                int lh_value=getChannel(row,column,channel);
                int rh_value=rhs.getChannel(row,column,channel);
                int new_value=lh_value-rh_value;
                if (new_value<0){
                    new_value=0;
                }
                setChannel(row,column,channel,new_value);
            }
        }
    }
    return *this;

}
PPM& PPM::operator*=( const double& rhs ){
    for (int row=0;row<getHeight();row++){
        for (int column=0;column<getWidth();column++){
            for (int channel=0;channel<3;channel++){
                int lh_value=getChannel(row,column,channel);
                int new_value=lh_value*rhs;
                if (new_value>getMaxColorValue()){
                    new_value=getMaxColorValue();
                }
                else if (new_value<0){
                    new_value=0;
                }
                setChannel(row,column,channel,new_value);
            }
        }
    }
    return *this;
}
PPM& PPM::operator/=( const double& rhs ){
    for (int row=0;row<getHeight();row++){
        for (int column=0;column<getWidth();column++){
            for (int channel=0;channel<3;channel++){
                int lh_value=getChannel(row,column,channel);
                int new_value=lh_value/rhs;
                if (new_value>getMaxColorValue()){
                    new_value=getMaxColorValue();
                }
                else if (new_value<0){
                    new_value=0;
                }
                setChannel(row,column,channel,new_value);
            }
        }
    }
    return *this;
}
PPM PPM::operator+( const PPM& rhs ) const{
     PPM new_ppm;
     new_ppm.setHeight(getHeight());
     new_ppm.setWidth(getWidth());
     new_ppm.setMaxColorValue(getMaxColorValue());
     for (int row=0;row<getHeight();row++){
        for (int column=0;column<getWidth();column++){
            for (int channel=0;channel<3;channel++){
                int lh_value=getChannel(row,column,channel);
                int rh_value=rhs.getChannel(row,column,channel);
                int new_value=lh_value+rh_value;
                if (new_value>getMaxColorValue()){
                    new_value=getMaxColorValue();
                }
                new_ppm.setChannel(row,column,channel,new_value);
            }
        }
    }
    return new_ppm;
}
PPM PPM::operator-( const PPM& rhs ) const{
    PPM new_ppm;
    new_ppm.setHeight(getHeight());
    new_ppm.setWidth(getWidth());
    new_ppm.setMaxColorValue(getMaxColorValue());
    for (int row=0;row<getHeight();row++){
        for (int column=0;column<getWidth();column++){
            for (int channel=0;channel<3;channel++){
                int lh_value=getChannel(row,column,channel);
                int rh_value=rhs.getChannel(row,column,channel);
                int new_value=lh_value-rh_value;
                if (new_value<0){
                    new_value=0;
                }
                new_ppm.setChannel(row,column,channel,new_value);
            }
        }
    }
    return new_ppm;
}
PPM PPM::operator*( const double& rhs ) const{
    PPM new_ppm;
    new_ppm.setHeight(getHeight());
    new_ppm.setWidth(getWidth());
    new_ppm.setMaxColorValue(getMaxColorValue());
    for (int row=0;row<getHeight();row++){
        for (int column=0;column<getWidth();column++){
            for (int channel=0;channel<3;channel++){
                int lh_value=getChannel(row,column,channel);
                int new_value=lh_value*rhs;
                if (new_value>getMaxColorValue()){
                    new_value=getMaxColorValue();
                }
                else if (new_value<0){
                    new_value=0;
                }
                new_ppm.setChannel(row,column,channel,new_value);
            }
        }
    }
    return new_ppm;
}

PPM PPM::operator/( const double& rhs ) const{
    PPM new_ppm;
    new_ppm.setHeight(getHeight());
    new_ppm.setWidth(getWidth());
    new_ppm.setMaxColorValue(getMaxColorValue());
    for (int row=0;row<getHeight();row++){
        for (int column=0;column<getWidth();column++){
            for (int channel=0;channel<3;channel++){
                int lh_value=getChannel(row,column,channel);
                int new_value=lh_value/rhs;
                if (new_value>getMaxColorValue()){
                    new_value=getMaxColorValue();
                }
                else if (new_value<0){
                    new_value=0;
                }
                new_ppm.setChannel(row,column,channel,new_value);
            }
        }
    }
    return new_ppm;
}

void PPM::grayFromChannel( PPM& dst, const int& src_channel ) const{
    dst.setHeight(getHeight());
    dst.setWidth(getWidth());
    dst.setMaxColorValue(getMaxColorValue());

    for (int row=0;row<getHeight();row++){
        for (int column=0;column<getWidth();column++){
            int color=getChannel(row,column,src_channel);
            for (int channel=0;channel<3;channel++){
               dst.setChannel(row,column,channel,color);
            }
        }
    }
}
void PPM::grayFromRed( PPM& dst ) const{
    grayFromChannel(dst,0);
}
void PPM::grayFromGreen( PPM& dst ) const{
    grayFromChannel(dst,1);
}
void PPM::grayFromBlue( PPM& dst ) const{
    grayFromChannel(dst,2);
}
double PPM::linearColorimetricPixelValue( const int& row, const int& column ) const{
    double red= (getChannel(row,column,0))*0.2126;
    double green= (getChannel(row,column,1))*0.7152;
    double blue= (getChannel(row,column,2))*0.0722;
    return red+green+blue;
}
void PPM::grayFromLinearColorimetric( PPM& dst ) const{
    dst.setHeight(getHeight());
    dst.setWidth(getWidth());
    dst.setMaxColorValue(getMaxColorValue());

    for (int row=0;row<getHeight();row++){
        for (int column=0;column<getWidth();column++){
            double color=linearColorimetricPixelValue(row,column);
            for (int channel=0;channel<3;channel++){
               dst.setChannel(row,column,channel,color);
            }
        }
    }
}
void PPM::orangeFilter(PPM& dst) const{
    dst.setHeight(getHeight());
    dst.setWidth(getWidth());
    dst.setMaxColorValue(getMaxColorValue());

    for (int row=0;row<getHeight();row++){
        for (int column=0;column<getWidth();column++){
            int red=getChannel(row,column,0);
            int green=getChannel(row,column,1);
            int blue=getChannel(row,column,2);

            int new_red=2*(2*red+green)/3;
            int new_green=2*(2*red+green)/6;
            int new_blue=blue/2;
            if (new_red>getMaxColorValue()){
                new_red=getMaxColorValue();
            }
             if (new_green>getMaxColorValue()){
                new_green=getMaxColorValue();
            }
             if (new_blue>getMaxColorValue()){
                new_blue=getMaxColorValue();
            }
            dst.setPixel(row,column,new_red,new_green,new_blue);

            
        }
    }
}
