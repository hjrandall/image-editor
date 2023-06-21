#include "GlutApp.h"
#include "glut_app.h"
#include "image_menu.h"

GlutApp::GlutApp(int height, int width)
  : mHeight(height), mWidth(width), mActionData(mInputStream, mOutputStream),mMinX(-2),mMaxX(2),mMinY(-2),mMaxY(2),mInteractionMode(IM_FRACTAL),mFractalMode(M_MANDELBROT),mMaxNumber(200),mColor1(54,117,136),mColor2(63,67,84),mNumColor(32),mHSVColor(false) {

  configureMenu(mMenuData);
  mActionData.setGrid(new ComplexFractal);
  setColorTable();
  createFractal();
}
void GlutApp::toggleHSVColor(){
  if (mHSVColor==true){
    mHSVColor=false;
  }
  else{
    mHSVColor=true;
  }
  setColorTable();
  gridApplyColorTable();
}

void GlutApp::setSize(int height, int width) {
  mHeight = height;
  mWidth = width;
}

int GlutApp::getHeight() const {
  return mHeight;
}
int GlutApp::getWidth() const {
  return mWidth;
}

void GlutApp::display() {
  if(mInteractionMode == IM_FRACTAL){
    PPM& p = mActionData.getOutputImage();
    double max = static_cast<double>(p.getMaxColorValue());
    double r, g, b;
    int row, column;
    glBegin( GL_POINTS );
    for(row = 0; row < p.getHeight(); row++) {
      for(column = 0; column < p.getWidth(); column++) {
        r = p.getChannel(row, column, 0) / max;
        g = p.getChannel(row, column, 1) / max;
        b = p.getChannel(row, column, 2) / max;
        glColor3d(r, g, b);
        glVertex2i(column, p.getHeight()-row-1);
      }
    }
    glEnd( );
  }
  else if(mInteractionMode == IM_COLORTABLE){
    displayColorTable();
  }
}


void GlutApp::createJulia() {

  selectJulia();
  configureGrid(200);
  juliaParameters(0.45,-.32);
  fractalPlaneSize(-2,2,-2,2);
  fractalCalculate();
  gridApplyColorTable();


}


void GlutApp::selectJulia(){
  mOutputStream.clear();
  mOutputStream.str("");
  mInputStream.clear();
  mInputStream.str("");
  takeAction("julia", mMenuData, mActionData);
}
void GlutApp::selectMandelbrot(){
  mOutputStream.clear();
  mOutputStream.str("");
  mInputStream.clear();
  mInputStream.str("");
  takeAction("mandelbrot", mMenuData, mActionData);
}
void GlutApp::selectComplexFractal(){
  mOutputStream.clear();
  mOutputStream.str("");
  mInputStream.clear();
  mInputStream.str("");
  takeAction("complex-fractal", mMenuData, mActionData);
}
void GlutApp::configureGrid(int max){
  mOutputStream.clear();
  mInputStream.clear();
  mOutputStream.str("");
  mInputStream.str("");
  {
    std::stringstream tmp;
    tmp << mHeight << " " << mWidth << " " << max;
    mInputStream.str(tmp.str());
  }
  takeAction("grid", mMenuData, mActionData);
  
}
void GlutApp::juliaParameters(double a, double b){
  mOutputStream.clear();
  mInputStream.clear();
  mOutputStream.str("");
  mInputStream.str("");
  {
    std::stringstream tmp;
    tmp << a << " " << b;
    mInputStream.str(tmp.str());
  }
  takeAction("julia-parameters", mMenuData, mActionData);
}
void GlutApp::fractalPlaneSize(double x_min, double x_max, double y_min, double y_max){
  mOutputStream.clear();
  mInputStream.clear();
  mOutputStream.str("");
  mInputStream.str("");
  {
    std::stringstream tmp;
    tmp << x_min << " " << x_max << " "<< y_min<< " " << y_max;
    mInputStream.str(tmp.str());
  }
  takeAction("fractal-plane-size", mMenuData, mActionData);
}
void GlutApp::fractalCalculate(){
  mOutputStream.clear();
  mInputStream.clear();
  mOutputStream.str("");
  mInputStream.str("");
  takeAction("fractal-calculate", mMenuData, mActionData);
}
void GlutApp::gridApplyColorTable(){
  mOutputStream.clear();
  mInputStream.clear();
  mOutputStream.str("");
  mInputStream.str("");
  takeAction("grid-apply-color-table", mMenuData, mActionData);
}
void GlutApp::createJulia2(){
  selectJulia();
  configureGrid(200);
  juliaParameters(0.52,-.38);
  fractalPlaneSize(-2,2,-2,2);
  fractalCalculate();
  gridApplyColorTable();

}
void GlutApp::createMandelbrot(){
  selectMandelbrot();
  configureGrid(200);
  
  fractalPlaneSize(-2,2,-2,2);
  fractalCalculate();
  gridApplyColorTable();
}
void GlutApp::createMandelbrot2(){
  selectMandelbrot();
  configureGrid(200);
  fractalPlaneSize(-.5,.5,-.5,.5);
  fractalCalculate();
  gridApplyColorTable();
}
void GlutApp::createComplexFractal(){
  selectComplexFractal();
  configureGrid(200);
  
  fractalPlaneSize(-2,2,-2,2);
  fractalCalculate();
  gridApplyColorTable();
}
void GlutApp::createComplexFractal2(){
  selectComplexFractal();
  configureGrid(200);
  
  fractalPlaneSize(-.5,.5,-.5,.5);
  fractalCalculate();
  gridApplyColorTable();
}
void GlutApp::displayColorTable(){
  double r, g, b;
  int row, column;
  Color c;
  glBegin( GL_POINTS );
  for(row = 0; row < getHeight(); row++) {
    for(column = 0; column < getWidth(); column++) {
      
      double i = column * mActionData.getTable().getNumberOfColors() / mWidth;
      c=mActionData.getTable()[i];

      r = c.getRed() / 255.0;
      g = c.getGreen() / 255.0;
      b = c.getBlue() / 255.0;
      glColor3d(r, g, b);
      glVertex2i(column, row);
    }
  }
  glEnd( );
}
void GlutApp::setInteractionMode(InteractionMode mode){
  mInteractionMode=mode;
}
void GlutApp::setColorTable(){
  mOutputStream.clear();
  mInputStream.clear();
  mOutputStream.str("");
  mInputStream.str("");
  {
    std::stringstream tmp;
    tmp << mNumColor;
    mInputStream.str(tmp.str());
  }
  takeAction("set-color-table-size", mMenuData, mActionData);

  mOutputStream.clear();
  mInputStream.clear();
  mOutputStream.str("");
  mInputStream.str("");
  

  if (mHSVColor==true){
    double hue1,saturation1,value1,hue2,saturation2,value2;
    mColor1.getHSV(hue1,saturation1,value1);
    mColor2.getHSV(hue2,saturation2,value2);
    {
     std::stringstream tmp;
      tmp << 0 << " " << hue1 << " " << saturation1 << " "<< value1<< " " << mNumColor-1 << " " << hue2 << " " << saturation2 << " " << value2 ;
      mInputStream.str(tmp.str());
    }
    takeAction("set-hsv-gradient", mMenuData, mActionData);

  }
  else{
    {
      std::stringstream tmp;
      tmp << 0 << " " << mColor1.getRed() << " " << mColor1.getGreen() << " " << mColor1.getBlue() << " " << mNumColor-1 << " " << mColor2.getRed() << " " << mColor2.getGreen() << " " << mColor2.getBlue() ;
      mInputStream.str(tmp.str());
    }
    takeAction("set-color-gradient", mMenuData, mActionData);
  }
}
void GlutApp::decreaseColorTableSize(){
  if (mNumColor >10){

    mNumColor/=1.1;

  }
  setColorTable();
  gridApplyColorTable();
}
void GlutApp::increaseColorTableSize(){
  if (mNumColor< 1024){
    mNumColor*=1.1;

  }
  setColorTable();
  gridApplyColorTable();
}
void GlutApp::zoomIn(){
  double dx=(1.0 - 0.9)*(mMaxX - mMinX) / 2.0;
  double dy=(1.0 - 0.9)*(mMaxY - mMinY) / 2.0;
  mMinX+=dx;
  mMaxX-=dx;
  mMinY+=dy;
  mMaxY-=dy;

}
void GlutApp::zoomOut(){
double dx=(1.0 - 0.9)*(mMaxX - mMinX) / 2.0;
double dy=(1.0 - 0.9)*(mMaxY - mMinY) / 2.0;
double a=mMinX-dx;
double b=mMaxX+dx;
double c=mMinY-dy;
double d=mMaxY+dy;
if (a>=-2.0 && b<=2.0 && c>=-2.0 && d<=2.0){
  mMinX=a;
  mMaxX=b;
  mMinY=c;
  mMaxY=d;
}
}
void GlutApp::moveLeft(){
double dx=(1.0 - 0.9)*(mMaxX - mMinX) / 2.0;
if ((mMinX -dx)>=-2){
  mMinX-=dx;
  mMaxX-=dx;
}
}
void GlutApp::moveRight(){
  double dx=(1.0 - 0.9)*(mMaxX - mMinX) / 2.0;
  if ((mMaxX -dx)<=2){
    mMinX+=dx;
    mMaxX+=dx;
  }
}
void GlutApp::moveDown(){
double dx=(1.0 - 0.9)*(mMaxY - mMinY) / 2.0;
if ((mMinY -dx)>=-2){
  mMinY-=dx;
  mMaxY-=dx;
}
}
void GlutApp::moveUp(){
  double dx=(1.0 - 0.9)*(mMaxY - mMinY) / 2.0;
  if ((mMaxY -dx)<=2){
    mMinY+=dx;
    mMaxY+=dx;
  }
}
void GlutApp::setFractalMode(FractalMode mode){
  mFractalMode=mode;
}
void GlutApp::increaseMaxNumber(){
  if(mMaxNumber<2048){
    mMaxNumber*=1.1;
  }
}
void GlutApp::decreaseMaxNumber(){
  if(mMaxNumber>11){
    mMaxNumber/=1.1;
  }
}
void GlutApp::setAB(int x, int y){
ComplexFractal *ptr=dynamic_cast<ComplexFractal*>(&mActionData.getGrid());
if (mFractalMode == M_MANDELBROT && ptr !=0){
  mA=mMinX + x * ptr->getDeltaX();
  mB=mMinY + y * ptr->getDeltaY();
}
}
void GlutApp::resetPlane(){
  mMinX=-2.0;
  mMinY=-2.0;
  mMaxX=2.0;
  mMaxY=2.0;
}
void GlutApp::createFractal(){
  if (mFractalMode == M_MANDELBROT){
    selectMandelbrot();
    configureGrid(mMaxNumber);
    fractalPlaneSize(mMinX,mMaxX,mMinY,mMaxY);
    fractalCalculate();
    gridApplyColorTable();

  }
  else if(mFractalMode == M_JULIA){
    selectJulia();
    configureGrid(mMaxNumber);
    juliaParameters(mA,mB);
    fractalPlaneSize(mMinX,mMaxX,mMinY,mMaxY);
    fractalCalculate();
    gridApplyColorTable();
  }
  else if (mFractalMode == M_COMPLEX){
    selectComplexFractal();
    configureGrid(mMaxNumber);
    fractalPlaneSize(mMinX,mMaxX,mMinY,mMaxY);
    fractalCalculate();
    gridApplyColorTable();
  }
}
