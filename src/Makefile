CXXFLAGS:=-Wall -Wextra -Werror -std=c++11

all: hello questions_3 ascii_image image_file simple_squares_ascii hero ppm_menu

ActionData.o:ActionData.cpp ActionData.h ColorTable.h
	g++ $(CXXFLAGS) -c -o ActionData.o ActionData.cpp 

ascii_image:ascii_image.o controllers.o user_io.o image_drawing.o image_output.o Image.o PPM.o ActionData.o MenuData.o image_filters.o NumberGrid.o ColorTable.o ComplexFractal.o JuliaSet.o MandelbrotSet.o ThreadedGrid.o 
	g++ $(CXXFLAGS) -o ascii_image ascii_image.o controllers.o user_io.o image_drawing.o image_output.o Image.o PPM.o ActionData.o MenuData.o image_filters.o NumberGrid.o ColorTable.o ComplexFractal.o JuliaSet.o MandelbrotSet.o ThreadedGrid.o -lpthread

ascii_image.o:ascii_image.cpp image_menu.h
	g++ $(CXXFLAGS) -c -o ascii_image.o ascii_image.cpp

controllers.o:controllers.cpp image_menu.h
	g++ $(CXXFLAGS) -c -o controllers.o controllers.cpp

ColorTable.o: ColorTable.cpp ColorTable.h
	g++ $(CXXFLAGS) -c -o ColorTable.o ColorTable.cpp

ComplexFractal.o:ComplexFractal.cpp ComplexFractal.h ThreadedGrid.h
	g++ $(CXXFLAGS) -c -o ComplexFractal.o ComplexFractal.cpp

hero: hero.o  controllers.o user_io.o image_drawing.o image_output.o Image.o PPM.o ActionData.o MenuData.o image_filters.o NumberGrid.o ColorTable.o ComplexFractal.o JuliaSet.o MandelbrotSet.o ThreadedGrid.o
	g++ $(CXXFLAGS) -o hero hero.o  controllers.o user_io.o image_drawing.o image_output.o Image.o PPM.o ActionData.o MenuData.o image_filters.o NumberGrid.o ColorTable.o ComplexFractal.o JuliaSet.o MandelbrotSet.o ThreadedGrid.o -lpthread
	
hero.o: hero.cpp image_menu.h
	g++ $(CXXFLAGS) -c -o  hero.o hero.cpp

hello: hello.o 
	g++ $(CXXFLAGS) -o hello hello.o 

hello.o: hello.cpp
	g++ $(CXXFLAGS) -c -o hello.o hello.cpp

image_filters.o:image_filters.cpp image_menu.h
	g++ $(CXXFLAGS) -c -o image_filters.o image_filters.cpp

image_drawing.o:image_drawing.cpp image_menu.h
	g++ $(CXXFLAGS) -c -o image_drawing.o image_drawing.cpp 

image_output.o:image_output.cpp Image.h
	g++ $(CXXFLAGS) -c -o image_output.o image_output.cpp

Image.o:Image.cpp Image.h
	g++ $(CXXFLAGS) -c -o Image.o Image.cpp

image_file: image_file.o controllers.o PPM.o image_drawing.o image_output.o user_io.o Image.o ActionData.o MenuData.o image_filters.o NumberGrid.o ColorTable.o ComplexFractal.o JuliaSet.o MandelbrotSet.o ThreadedGrid.o 
	g++ $(CXXFLAGS) -o  image_file image_file.o controllers.o PPM.o image_drawing.o image_output.o user_io.o Image.o ActionData.o MenuData.o image_filters.o NumberGrid.o ColorTable.o ComplexFractal.o JuliaSet.o MandelbrotSet.o ThreadedGrid.o -lpthread

image_file.o:image_file.cpp image_menu.h
	g++ $(CXXFLAGS) -c -o image_file.o image_file.cpp

JuliaSet.o:JuliaSet.cpp JuliaSet.h
	g++ $(CXXFLAGS) -c -o  JuliaSet.o JuliaSet.cpp

MandelbrotSet.o: MandelbrotSet.cpp MandelbrotSet.h
	g++ $(CXXFLAGS) -c -o MandelbrotSet.o MandelbrotSet.cpp
MenuData.o:MenuData.cpp MenuData.h
	g++ $(CXXFLAGS) -c -o MenuData.o MenuData.cpp

NumberGrid.o:NumberGrid.cpp PPM.h ColorTable.h
	g++ $(CXXFLAGS) -c -o  NumberGrid.o NumberGrid.cpp

ppm_menu:ppm_menu.o controllers.o PPM.o image_drawing.o image_output.o user_io.o Image.o ActionData.o MenuData.o image_filters.o NumberGrid.o ColorTable.o ComplexFractal.o JuliaSet.o MandelbrotSet.o ThreadedGrid.o
	g++ $(CXXFLAGS) -o ppm_menu ppm_menu.o controllers.o PPM.o image_drawing.o image_output.o user_io.o Image.o ActionData.o MenuData.o image_filters.o NumberGrid.o ColorTable.o ComplexFractal.o JuliaSet.o MandelbrotSet.o ThreadedGrid.o -lpthread

ppm_menu.o:ppm_menu.cpp image_menu.h
	g++ $(CXXFLAGS) -c -o ppm_menu.o ppm_menu.cpp

PPM.o:PPM.cpp PPM.h
	g++ $(CXXFLAGS) -c -o PPM.o PPM.cpp

questions_3: questions_3.o controllers.o user_io.o Image.o image_drawing.o image_output.o PPM.o ActionData.o MenuData.o image_filters.o NumberGrid.o ColorTable.o ComplexFractal.o JuliaSet.o MandelbrotSet.o ThreadedGrid.o
	g++ $(CXXFLAGS) -o questions_3 questions_3.o controllers.o user_io.o Image.o image_drawing.o image_output.o PPM.o ActionData.o MenuData.o image_filters.o NumberGrid.o ColorTable.o ComplexFractal.o JuliaSet.o MandelbrotSet.o ThreadedGrid.o -lpthread

questions_3.o:questions_3.cpp image_menu.h 
	g++ $(CXXFLAGS) -c  -o questions_3.o questions_3.cpp

simple_squares_ascii:simple_squares_ascii.o controllers.o user_io.o image_drawing.o image_output.o Image.o PPM.o ActionData.o MenuData.o image_filters.o NumberGrid.o ColorTable.o ComplexFractal.o JuliaSet.o MandelbrotSet.o ThreadedGrid.o
	g++ $(CXXFLAGS) -o simple_squares_ascii simple_squares_ascii.o controllers.o user_io.o image_drawing.o image_output.o Image.o PPM.o ActionData.o MenuData.o image_filters.o NumberGrid.o ColorTable.o ComplexFractal.o JuliaSet.o MandelbrotSet.o ThreadedGrid.o -lpthread

simple_squares_ascii.o:simple_squares_ascii.cpp image_menu.h 
	g++ $(CXXFLAGS) -c  -o simple_squares_ascii.o simple_squares_ascii.cpp

ThreadedGrid.o:ThreadedGrid.cpp ThreadedGrid.h
	g++ $(CXXFLAGS) -c -o ThreadedGrid.o ThreadedGrid.cpp
user_io.o:user_io.cpp 
	g++ $(CXXFLAGS) -c -o user_io.o user_io.cpp

clean:
	-rm -f *.o