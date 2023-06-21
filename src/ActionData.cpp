#include "ActionData.h"
ActionData::ActionData(std::istream& is, std::ostream& os) : input_s(is), output_s(os),Color_Table(16){
    done=false;
    mGrid=0;
    Color color1(0,255,0);
    Color color2(255,0,255);
    Color_Table.insertGradient(color1,color2,0,15);
}
ActionData::~ActionData(){
    if (mGrid!=0){
         delete mGrid;
         mGrid=0;
    }
}
ColorTable& ActionData::getTable(){
    return Color_Table;
}
std::istream& ActionData::getIS(){
    return input_s;
}
std::ostream& ActionData::getOS(){
    return output_s;
}
PPM& ActionData::getInputImage1(){
    return input_image1;
}
PPM& ActionData::getInputImage2(){
    return input_image2;
}
PPM& ActionData::getOutputImage(){
    return output_image;
}
bool ActionData::getDone() const{
    return done;
}
void ActionData::setDone(){
    done = true;
}
NumberGrid& ActionData::getGrid(){
    return *mGrid;
}
void ActionData::setGrid(NumberGrid *grid){
    if (mGrid!=0){
         delete mGrid;
         mGrid=0;
    }
    mGrid=grid;


    
}