#ifndef _NUMBER_GRID_
#define _NUMBER_GRID_
#include <vector>
#include "PPM.h"
#include "ColorTable.h"
class NumberGrid{
    public:
        NumberGrid( );
        NumberGrid( const int& height, const int& width );
        virtual ~NumberGrid();
        int getHeight( ) const;
        int getWidth( ) const;
        int getMaxNumber( ) const;
        virtual void setGridSize( const int& height, const int& width );
        virtual int calculateNumber(const int& row, const int& column) const = 0;
        virtual void calculateAllNumbers();
        void setMaxNumber( const int& number );
        const std::vector< int >& getNumbers( ) const;
        int index( const int& row, const int& column ) const;
        bool indexValid( const int& row, const int& column ) const;
        bool numberValid( const int& number ) const;
        int getNumber( const int& row, const int& column ) const;
        void setNumber( const int& row, const int& column, const int& number );
        void setPPM( PPM& ppm ) const;
        void setPPM( PPM& ppm, const ColorTable& colors ) const;
    protected:
        int mHeight;
        int mWidth;
        int mMax_color_value;
        std::vector<int> mGrid;

};

class ManhattanNumbers: public NumberGrid{
    public:
        ManhattanNumbers();
        ManhattanNumbers(const int& height, const int& width);
        virtual ~ManhattanNumbers();
        int calculateNumber(const int& row, const int& column) const;
};
#endif 
