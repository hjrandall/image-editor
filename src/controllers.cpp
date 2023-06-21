#include "image_menu.h"
int assignment1 (std::istream& is, std::ostream& os){
    ActionData action_data(is,os);
    int num = askQuestions3(action_data);
    return num ;
}
int assignment2 (std::istream& is, std::ostream& os ){
    ActionData action_data(is,os);
    diagonalQuadPattern(action_data);
    copyImage(action_data);
    drawAsciiImage(action_data);
    return 0;
}

int assignment3( std::istream& is, std::ostream& os ){
    ActionData action_data(is,os);
    stripedDiagonalPattern(action_data);
    copyImage(action_data);
    writeUserImage(action_data);
    return 0;
}

int simple_squares_ascii(std::istream& is, std::ostream& os){
    ActionData action_data(is,os);
    simpleSquaresPattern(action_data);
    copyImage(action_data);
    drawAsciiImage(action_data);
    return 0;
}
int hero( std::istream& is, std::ostream& os ){
    ActionData action_data(is,os);
    return askHeroQuestions(action_data);
}
void showMenu( MenuData& menu_data, ActionData& action_data ){
    std::map<std::string, std::string>::iterator it;
    for (it = menu_data.descriptions.begin(); it != menu_data.descriptions.end();it++){
        action_data.getOS()<<it->first<<") "<<it->second<<std::endl;
    }
}
void takeAction(const std::string& choice, MenuData& menu_data, ActionData& action_data){
   ActionFunctionType function= menu_data.getFunction(choice);
    if (function==0 && choice!="menu"){
        action_data.getOS()<<"Unknown action "<<"'"<<choice<<"'."<<std::endl;
    }
    else if (choice == "menu"){
        showMenu(menu_data,action_data);
    }
    else{
        function(action_data);
    }
}

void configureMenu( MenuData& menu_data ){
    menu_data.addAction("draw-ascii",                           drawAsciiImage,                 "Write output image to terminal as ASCII art."); // 1
    menu_data.addAction("write",                                writeUserImage,                 "Write output image to file."); // 2
    menu_data.addAction("copy",                                 copyImage,                      "Copy input image 1 to output image."); // 3
    menu_data.addAction("read1",                                readUserImage1,                 "Read file into input image 1."); // 4
    menu_data.addAction("#",                                    commentLine,                    "Comment to end of line."); // 5
    menu_data.addAction("max-color-value",                      setMaxColorValue,               "Set the max color value of input image 1."); // 6
    menu_data.addAction("channel",                              setChannel,                     "Set a channel value in input image 1."); // 7
    menu_data.addAction("pixel",                                setPixel,                       "Set a pixel's 3 values in input image 1."); // 8
    menu_data.addAction("clear",                                clearAll,                       "Set all pixels to 0,0,0 in input image 1."); // 9
    menu_data.addAction("quit",                                 quit,                           "Quit."); // 10
    menu_data.addAction("read2",                                readUserImage2,                 "Read file into input image 2."); // 11
    menu_data.addAction("+",                                    plus,                           "Set output image from sum of input image 1 and input image 2."); // 12
    menu_data.addAction("+=",                                   plusEquals,                     "Set input image 1 by adding in input image 2."); // 13
    menu_data.addAction("-",                                    minus,                          "Set output image from difference of input image 1 and input image 2."); // 14
    menu_data.addAction("-=",                                   minusEquals,                    "Set input image 1 by subtracting input image 2."); // 15
    menu_data.addAction("*",                                    times,                          "Set output image from input image 1 multiplied by a number."); // 16
    menu_data.addAction("*=",                                   timesEquals,                    "Set input image 1 by multiplying by a number."); // 17
    menu_data.addAction("/",                                    divide,                         "Set output image from input image 1 divided by a number."); // 18
    menu_data.addAction("/=",                                   divideEquals,                   "Set input image 1 by dividing by a number."); // 19
    menu_data.addAction("red-gray",                             grayFromRed,                    "Set output image by grayscale from red on input image 1."); // 20
    menu_data.addAction("green-gray",                           grayFromGreen,                  "Set output image by grayscale from green on input image 1."); // 21
    menu_data.addAction("blue-gray",                            grayFromBlue,                   "Set output image by grayscale from blue on input image 1."); // 22
    menu_data.addAction("linear-gray",                          grayFromLinearColorimetric,     "Set output image by linear colorimetric grayscale on input image 1."); // 23
    menu_data.addAction("circle",                               drawCircle,                     "Draw a circle shape in input image 1."); // 24
    menu_data.addAction("box",                                  drawBox,                        "Draw a box shape in input image 1."); // 25
    menu_data.addAction("orange",                               orangeFilter,                   "Set output image from orange filter on input image 1."); // 26
    menu_data.addAction("square",                               drawSquare,                     "Draw a square shape in input image 1."); // 27
    menu_data.addAction("grid",                                 configureGrid,                  "Configure the grid."); // 28
    menu_data.addAction("grid-set",                             setGrid,                        "Set a single value in the grid."); // 29
    menu_data.addAction("grid-apply",                           applyGrid,                      "Use the grid values to set colors in the output image."); // 30
    menu_data.addAction("set-color-table-size",                 setColorTableSize,              "Change the number of slots in the color table."); // 31
    menu_data.addAction("set-color",                            setColor,                       "Set the RGB values for one slot in the color table."); // 32
    menu_data.addAction("set-random-color",                     setRandomColor,                 "Randomly set the RGB values for one slot in the color table."); // 33
    menu_data.addAction("set-color-gradient",                   setColorGradient,               "Smoothly set the RGB values for a range of slots in the color table."); // 34
    menu_data.addAction("grid-apply-color-table",               applyGridColorTable,            "Use the grid values to set colors in the output image using the color table."); // 35
    menu_data.addAction("fractal-plane-size",                   setFractalPlaneSize,            "Set the dimensions of the grid in the complex plane."); // 36
    menu_data.addAction("fractal-calculate",                    calculateFractal,               "Calculate the escape values for the fractal."); // 37
    menu_data.addAction("julia-parameters",                     setJuliaParameters,             "Set the parameters of the Julia Set function."); // 38
    menu_data.addAction("complex-fractal",                      setComplexFractal,              "Choose to make a complex plane."); // 39
    menu_data.addAction("julia",                                setJuliaFractal,                "Choose to make a Julia set."); // 40
    menu_data.addAction("mandelbrot",                           setMandelbrotFractal,           "Choose to make a Mandelbrot set."); // 41
    menu_data.addAction("mandelbrot-power",                     setMandelbrotPowerFractal,      "Choose to make a Mandelbrot set with the power function."); // 42
    menu_data.addAction("set-mandelbrot-power",                 setMandelbrotPower,             "Choose a power for the Mandelbrot power function."); // 43
    menu_data.addAction("manhattan",                            setManhattanNumbers,            "Choose to make a Manhattan distance grid."); // 44
    menu_data.addAction("fractal-calculate-single-thread",      calculateFractalSingleThread,   "Calculate the escape values for the fractal, single-thread."); // 45
    menu_data.addAction("size",                                 setSize,                        "Set the size of input image 1."); // 46
    menu_data.addAction("set-hsv-gradient",                     setHueSaturationValueGradient,  "Smoothly set colors for a range of slots in the color table, based on change of hue, saturation, and value."); // 47
    
    
}

int imageMenu(std::istream& is, std::ostream& os){
    ActionData action_data(is,os);
    MenuData menu_data;
    ComplexFractal *ptr= new ComplexFractal();
    action_data.setGrid(ptr);
    configureMenu(menu_data);
    while (!action_data.getDone()&& action_data.getIS().good()){
        std::string choice=getChoice(action_data);
        takeAction(choice,menu_data,action_data);

    }
    return 0;
}
void setComplexFractal( ActionData& action_data ){
    ComplexFractal *ptr= new ComplexFractal();
    action_data.setGrid(ptr);
}
void setJuliaFractal( ActionData& action_data ){
    JuliaSet *ptr= new JuliaSet();
    action_data.setGrid(ptr);
}
void setMandelbrotFractal( ActionData& action_data ){
    MandelbrotSet *ptr= new MandelbrotSet();
    action_data.setGrid(ptr);
}
void setMandelbrotPowerFractal(ActionData& action_data){
    MandelbrotPower *ptr= new MandelbrotPower();
    action_data.setGrid(ptr);
}
void setManhattanNumbers(ActionData& action_data){
    ManhattanNumbers *ptr= new ManhattanNumbers();
    action_data.setGrid(ptr);
}