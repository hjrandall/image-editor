#include "image_menu.h"



void diagonalQuadPattern( ActionData& action_data){
    int imageHeight=getInteger(action_data, "Image height? ");
    int imageWidth=getInteger(action_data, "Image width? ");
    action_data.getInputImage1().setHeight(imageHeight);
    action_data.getInputImage1().setWidth(imageWidth);
    action_data.getInputImage1().setMaxColorValue(255);
    int image_size=imageHeight*imageWidth*3;

    // set color values
    int row=0;
    int column=0;
    for(int i=0;i<image_size;i+=3){
        int r_channel=0;
        int g_channel=1;
        int b_channel=2;
        int half_height=(imageHeight/2);
        int half_width=(imageWidth/2);
    
    // set red value
        if (row< half_height){
            action_data.getInputImage1().setChannel(row,column,r_channel,0);
        }
        else {
            action_data.getInputImage1().setChannel(row,column,r_channel,255);
        }
    // set green value
        action_data.getInputImage1().setChannel(row,column,g_channel,( 2*row + 2*column ) % 256);
    // set blue value
        if (column<half_width){
            action_data.getInputImage1().setChannel(row,column,b_channel,0);
        }
        else{
            action_data.getInputImage1().setChannel(row,column,b_channel,255);
        }
    //increment row and column
        if (column==imageWidth-1){
                column=0;
                row+=1;
        }
        else{
            column+=1;
         }
    }
}

void stripedDiagonalPattern( ActionData& action_data){
    int height=getInteger(action_data,"Image height? ");
    int width=getInteger(action_data,"Image width? ");
    int max_value=(height+width)/3;
    if (max_value>255){
        max_value=255;
    }
    
    action_data.getInputImage1().setHeight(height);
    action_data.getInputImage1().setWidth(width);
    action_data.getInputImage1().setMaxColorValue(max_value);

    int image_size=height*width*3;
    int half_height=(height/2);
    // set color values
    int row=0;
    int column=0;
    int r_channel=0;
    int g_channel=1;
    int b_channel=2;
    int green;

    for(int i=0;i<image_size;i+=3){
        // set green value
        
         green=(row+width-column-1)%(max_value+1);
        action_data.getInputImage1().setChannel(row,column,g_channel,green);

        // set red value
        if (row< half_height){
            action_data.getInputImage1().setChannel(row,column,r_channel,0);
        }
        else if(row%3==0) {
            action_data.getInputImage1().setChannel(row,column,r_channel,0);
        }
        else{
            action_data.getInputImage1().setChannel(row,column,r_channel,max_value);
        }
        //set blue
         if (column<row){
            action_data.getInputImage1().setChannel(row,column,b_channel,0);
        }
        else{
            action_data.getInputImage1().setChannel(row,column,b_channel,max_value);
        }

        //increment row and column
        if (column==width-1){
                column=0;
                row+=1;
        }
        else{
            column+=1;
         }
    }
}

void simpleSquaresPattern(ActionData& action_data){
     int imageWidth=getInteger(action_data, "Image size? ");
    action_data.getInputImage1().setHeight(imageWidth);
    action_data.getInputImage1().setWidth(imageWidth);
    int image_size=imageWidth*imageWidth*3;

    // set color values
    int row=0;
    int column=0;
    int r_channel=0;
    int g_channel=1;
    int b_channel=2;
    int half_height=(imageWidth/2);
    int half_width=(imageWidth/2);
    for(int i=0;i<image_size;i+=3){
    // set red value
        if (row< half_height){
            action_data.getInputImage1().setChannel(row,column,r_channel,127);
        }
        else {
            action_data.getInputImage1().setChannel(row,column,r_channel,255);
        }
    // set blue value
        action_data.getInputImage1().setChannel(row,column,b_channel,255);
    // set green value
        if (column<half_width){
            action_data.getInputImage1().setChannel(row,column,g_channel,0);
        }
        else{
            action_data.getInputImage1().setChannel(row,column,g_channel,255);
        }
    //increment row and column
        if (column==imageWidth-1){
                column=0;
                row+=1;
        }
        else{
            column+=1;
         }
    }
}

void setSize( ActionData& action_data){
    int width,height;
    std::string prompt="Height? ";
    height=getInteger(action_data,prompt);
   
    prompt="Width? ";
    width=getInteger(action_data,prompt);

    action_data.getInputImage1().setHeight(height);
    action_data.getInputImage1().setWidth(width);

}

void setMaxColorValue( ActionData& action_data ){
    std::string prompt="Max color value? ";
    int max_color=getInteger(action_data,prompt);
    action_data.getInputImage1().setMaxColorValue(max_color);
}

void setChannel( ActionData& action_data ){
    int row,column,channel,value;
    std::string prompt;

    prompt="Row? ";
    row=getInteger(action_data,prompt);

    prompt="Column? ";
    column=getInteger(action_data,prompt);

    prompt="Channel? ";
    channel=getInteger(action_data,prompt);

    prompt="Value? ";
    value=getInteger(action_data,prompt);

    action_data.getInputImage1().setChannel(row,column,channel,value);

}

void setPixel( ActionData& action_data ){
    int row,column,red,green,blue;
    std::string prompt;

    prompt="Row? ";
    row=getInteger(action_data,prompt);

    prompt="Column? ";
    column=getInteger(action_data,prompt);

    prompt="Red? ";
    red=getInteger(action_data,prompt);

    prompt="Green? ";
    green=getInteger(action_data,prompt);

    prompt="Blue? ";
    blue=getInteger(action_data,prompt);

    action_data.getInputImage1().setChannel(row,column,0,red);
    action_data.getInputImage1().setChannel(row,column,1,green);
    action_data.getInputImage1().setChannel(row,column,2,blue);
}

void clearAll( ActionData& action_data ){
    int height=action_data.getInputImage1().getHeight();
    int width=action_data.getInputImage1().getWidth();
    int red=0;
    int green=0;
    int blue=0;
    for (int row=0;row<(height);row++){
        for (int column=0; column<(width);column++){
            action_data.getInputImage1().setPixel(row,column,red,green,blue);
        }
    }
}
void drawCircle(ActionData& action_data){
    int row2= getInteger(action_data,"Center Row? ");
    int column2=getInteger(action_data,"Center Column? ");
    int radius=getInteger(action_data,"Radius? ");
    int red=getInteger(action_data,"Red? ");
    int green=getInteger(action_data,"Green? ");
    int blue=getInteger(action_data,"Blue? ");

    for (int row=0;row<action_data.getInputImage1().getHeight();row++){
        for (int column=0;column<action_data.getInputImage1().getWidth();column++){
            double distance= std::sqrt(((row2-row)*(row2-row))+((column2-column)*(column2-column)));
            if (distance<=radius){
                action_data.getInputImage1().setChannel(row,column,0,red);
                action_data.getInputImage1().setChannel(row,column,1,green);
                action_data.getInputImage1().setChannel(row,column,2,blue);    
            }
        }
    }

}
void drawBox(ActionData& action_data){
    int top= getInteger(action_data,"Top Row? ");
    int left=getInteger(action_data,"Left Column? ");
    int bottom= getInteger(action_data,"Bottom Row? ");
    int right=getInteger(action_data,"Right Column? ");
    int red=getInteger(action_data,"Red? ");
    int green=getInteger(action_data,"Green? ");
    int blue=getInteger(action_data,"Blue? ");

     for (int row=0;row<action_data.getInputImage1().getHeight();row++){
        for (int column=0;column<action_data.getInputImage1().getWidth();column++){
            if (row>=top && row<=bottom && column>=left && column<=right){
                action_data.getInputImage1().setChannel(row,column,0,red);
                action_data.getInputImage1().setChannel(row,column,1,green);
                action_data.getInputImage1().setChannel(row,column,2,blue);    
            }
        }
    }
}
void drawSquare(ActionData& action_data){
    int row2= getInteger(action_data,"Row? ");
    int column2=getInteger(action_data,"Column? ");
    int size=getInteger(action_data,"Size? ");
    int red=getInteger(action_data,"Red? ");
    int green=getInteger(action_data,"Green? ");
    int blue=getInteger(action_data,"Blue? ");
    int radius=size/2;

    for (int row=0;row<action_data.getInputImage1().getHeight();row++){
        for (int column=0;column<action_data.getInputImage1().getWidth();column++){
            // double distance= std::sqrt(((row2-row)*(row2-row))+((column2-column)*(column2-column)));
            if (row>=row2-radius && column>=column2-radius && row<=row2+radius && column<=column2+radius){
                action_data.getInputImage1().setChannel(row,column,0,red);
                action_data.getInputImage1().setChannel(row,column,1,green);
                action_data.getInputImage1().setChannel(row,column,2,blue);    
            }
        }
    }

}

void configureGrid(ActionData& action_data){
    int height= getInteger(action_data,"Grid Height? ");
    int width= getInteger(action_data,"Grid Width? ");
    int max_num= getInteger(action_data,"Grid Max Value? ");
    action_data.getGrid().setGridSize(height,width);
    action_data.getGrid().setMaxNumber(max_num);
}
void setGrid(ActionData& action_data){
    int row= getInteger(action_data,"Grid Row? ");
    int column= getInteger(action_data,"Grid Column? ");
    int value= getInteger(action_data,"Grid Value? ");
    action_data.getGrid().setNumber(row,column,value);
}
void applyGrid(ActionData& action_data){
    action_data.getGrid().setPPM(action_data.getOutputImage());
    
    
}

void setColorTableSize(ActionData& action_data){
    int size= getInteger(action_data,"Size? ");
    action_data.getTable().setNumberOfColors(size);
}
void setColor(ActionData& action_data){
    int position=getInteger(action_data,"Position? ");
    int red=getInteger(action_data,"Red? ");
    int green=getInteger(action_data,"Green? ");
    int blue=getInteger(action_data,"Blue? ");
    action_data.getTable()[position].setRed(red);
    action_data.getTable()[position].setGreen(green);
    action_data.getTable()[position].setBlue(blue);
}
void setRandomColor(ActionData& action_data){
    int position=getInteger(action_data,"Position? ");
    action_data.getTable().setRandomColor(255,position);
}
void setColorGradient(ActionData& action_data){
    int position1=getInteger(action_data,"First position? ");
    int red1=getInteger(action_data,"First red? ");
    int green1=getInteger(action_data,"First green? ");
    int blue1=getInteger(action_data,"First blue? ");
    int position2=getInteger(action_data,"Second position? ");
    int red2=getInteger(action_data,"Second red? ");
    int green2=getInteger(action_data,"Second green? ");
    int blue2=getInteger(action_data,"Second blue? ");
    Color color1(red1,green1,blue1);
    Color color2(red2,green2,blue2);
    action_data.getTable().insertGradient(color1,color2,position1,position2);
}
void applyGridColorTable(ActionData& action_data){
    action_data.getGrid().setPPM(action_data.getOutputImage(),action_data.getTable());
}
void setFractalPlaneSize(ActionData& action_data){
    
    ComplexFractal *holder=dynamic_cast<ComplexFractal*>(&action_data.getGrid());
    if (holder!=0){
        double minX=getDouble(action_data,"Min X? ");
        double maxX=getDouble(action_data,"Max X? ");
        double minY=getDouble(action_data,"Min Y? ");
        double maxY=getDouble(action_data,"Max Y? ");
        holder->setPlaneSize(minX,maxX,minY,maxY);
    }
    else{
        action_data.getOS()<<"Not a ComplexFractal object. Can't set plane size."<<std::endl;
    }
}
void calculateFractal(ActionData& action_data){
    action_data.getGrid().calculateAllNumbers();
}
void setJuliaParameters(ActionData& action_data){
    JuliaSet *holder=dynamic_cast<JuliaSet*>(&action_data.getGrid());
    if (holder!=0){
        double a=getDouble(action_data,"Parameter a? ");
        double b=getDouble(action_data,"Parameter b? ");
        holder->setParameters(a,b);
    }
    else{
        action_data.getOS()<<"Not a JuliaSet object. Can't set parameters."<<std::endl;
    }
}
void setMandelbrotPower(ActionData& action_data){
    MandelbrotPower *holder=dynamic_cast<MandelbrotPower*>(&action_data.getGrid());
    if (holder!=0){
        double power = getDouble(action_data,"Power? ");
        holder->setPower(power);
    }
    else{
        action_data.getOS()<<"Not a MandelbrotPower object. Can't set power."<<std::endl;
    }
    
}
void calculateFractalSingleThread(ActionData& action_data){
    action_data.getGrid().NumberGrid::calculateAllNumbers();
}
void setHueSaturationValueGradient(ActionData& action_data){
    int position1=getInteger(action_data,"First position? ");
    double hue1=getDouble(action_data,"First hue? ");
    double saturation1=getDouble(action_data,"First saturation? ");
    double value1=getDouble(action_data,"First value? ");
    int position2=getInteger(action_data,"Second position? ");
    double hue2=getDouble(action_data,"Second hue? ");
    double saturation2=getDouble(action_data,"Second saturation? ");
    double value2=getDouble(action_data,"Second value? ");
    Color first,second;
    
    first.setFromHSV(hue1,saturation1,value1);
    second.setFromHSV(hue2,saturation2,value2);

    action_data.getTable().insertGradient(first,second,position1,position2);
}