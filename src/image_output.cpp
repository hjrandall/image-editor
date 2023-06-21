#include "image_menu.h"
#include <vector>

void drawAsciiImage( ActionData& action_data){
    int width=action_data.getOutputImage().getWidth();
    int height=action_data.getOutputImage().getHeight();
    int image_size=width*height*3;
    std::vector <char> symbols (width*height);
    int kount=0;
    int row=0;
    int column=0;
    for(int i=0;i<image_size;i+=3){
        double red=action_data.getOutputImage().getChannel(row,column,0);
        double green=action_data.getOutputImage().getChannel(row,column,1);
        double blue=action_data.getOutputImage().getChannel(row,column,2);
        double pixel_strength=(red+green+blue)/765.0;
        if (column==width-1){
                column=0;
                row+=1;
        }
        else{
                column+=1;
         }
        if(pixel_strength>=1.0){
             symbols[kount]='@';
         }
        else if(pixel_strength>=.9){
             symbols[kount]='#';
         }
        else if(pixel_strength>=.8){
             symbols[kount]='%';
         }
        else if(pixel_strength>=.7){
             symbols[kount]='*';
         }
        else if(pixel_strength>=.6){
             symbols[kount]='|';
         }
        else if(pixel_strength>=.5){
             symbols[kount]='+';
         }
        else if(pixel_strength>=.4){
             symbols[kount]=';';
         }
        else if(pixel_strength>=.3){
             symbols[kount]='~';
         }
        else if(pixel_strength>=.2){
             symbols[kount]='-';
         }
        else if(pixel_strength>=.1){
             symbols[kount]='.';
         }
        else if(pixel_strength>=.0){
             symbols[kount]=' ';
         }
        
        kount+=1;

        
    }
    kount=0;
    for (int i=0;i<(width*height);i++){
       if (kount>(width-1)){
           action_data.getOS()<< std::endl;
           kount=0;
        }
        action_data.getOS()<<symbols.at(i);
        kount+=1;
    }
    action_data.getOS()<<std::endl;


}


void writeUserImage( ActionData& action_data){
    std::string file_name= getString(action_data,"Output filename? ");
    std::ofstream file(file_name, std::ios::binary);
    action_data.getOutputImage().writeStream(file);

    file.close();
}

void copyImage(ActionData& action_data){
    action_data.getOutputImage() = action_data.getInputImage1();
}

void readUserImage1( ActionData& action_data ){
    std::string prompt="Input filename? ";
    std::string file_name= getString(action_data,prompt);
    std::ifstream file(file_name,std::ios::in);
    if(file.is_open()){
        action_data.getInputImage1().readStream(file);
    }
    else{
        action_data.getOS()<<"'"<<file_name<<"' could not be opened."<<std::endl;
    }
    
    file.close();
}
void readUserImage2( ActionData& action_data ){
    std::string prompt="Input filename? ";
    std::string file_name= getString(action_data,prompt);
    std::ifstream file(file_name,std::ios::in);
    if(file.is_open()){
        action_data.getInputImage2().readStream(file);
    }
    else{
        action_data.getOS()<<"'"<<file_name<<"' could not be opened."<<std::endl;
    }
    
    file.close();
}


