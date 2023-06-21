#ifndef _ACTIONDATA_
#define _ACTIONDATA_
#include "PPM.h"
#include "NumberGrid.h"
#include "ColorTable.h"
class ActionData{
    public:
        ActionData(std::istream& is, std::ostream& os);
        std::istream& getIS();
        std::ostream& getOS();
        PPM& getInputImage1();
        PPM& getInputImage2();
        PPM& getOutputImage();
        ColorTable& getTable();
        bool getDone() const;
        void setDone();
        ~ActionData();
        NumberGrid& getGrid();
        void setGrid(NumberGrid *grid);


    protected:
        std::istream& input_s;
        std::ostream& output_s;

        PPM input_image1;
        PPM input_image2;
        PPM output_image;
        NumberGrid *mGrid;
        ColorTable Color_Table;
        bool done;


};
#endif