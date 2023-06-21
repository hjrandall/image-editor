#ifndef   _THREAD_GRID_
#define   _THREAD_GRID_
#include "NumberGrid.h"
#include "ThreadedVector.h"
#
class ThreadedGrid: public NumberGrid{
    public:
        ThreadedGrid();
        ThreadedGrid(const int& height, const int& width);
        virtual ~ThreadedGrid();
        virtual void calculateAllNumbers();
        virtual void worker();
    protected:
        ThreadedVector<int> jobs_list;

};
#endif