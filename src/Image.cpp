#include "Image.h"
Image::Image(){
    mHeight=0;
    mWidth=0;
    mVect.resize(0);

}
Image::Image(const int& height, const int& width){
    mHeight=height;
    mWidth=width;
    mVect.resize(height*width*3);
}
int Image:: getHeight() const{
    return mHeight;
}

int Image:: getWidth() const{
    return mWidth;
}
bool Image:: indexValid(const int& row, const int& column, const int& channel) const{
    bool valid=true;
    if (row<0 or row> mHeight-1){
        valid=false;
    }
    if (column<0 or column> mWidth-1){
        valid=false;
    }
    if (channel<0 or channel>2){
        valid=false;
    }
    return valid;
}
int Image:: index(const int& row, const int& column, const int& channel) const{
    int position= (row*mWidth*3+column*3)+channel;
    return position;
}
int Image:: getChannel(const int& row, const int& column, const int& channel) const{
    int value=-1;
    if (indexValid(row,column,channel)){
        int position=index(row,column,channel);
        value= mVect[position];
    }
    return value;
}
void Image:: setHeight( const int& height){
    if (height>-1){
        mHeight=height;
        mVect.resize(mHeight*mWidth*3);
    }

}
void Image:: setWidth(const int& width){
    if (width>-1){
        mWidth=width;
        mVect.resize(mHeight*mWidth*3);
    }
}
void Image:: setChannel(const int& row, const int& column, const int& channel, const int& value){
    bool valid=indexValid(row,column,channel);
    if (valid){
        int position = index(row,column,channel);
        mVect[position]=value;
        
    }
}
