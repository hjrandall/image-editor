#include "ThreadedGrid.h"
#include <thread>
#include <exception>

ThreadedGrid::ThreadedGrid(): NumberGrid(){

}
ThreadedGrid::ThreadedGrid(const int& height, const int& width):NumberGrid(height,width){

}
ThreadedGrid::~ThreadedGrid(){

}
void ThreadedGrid::calculateAllNumbers(){
    unsigned int max_cores=std::thread::hardware_concurrency();
    std::vector<std::thread> threads;
    for (int row =0; row <getHeight(); row++){
        jobs_list.push_back(row);
    }

    for(unsigned int i = 0; i < max_cores; i++) {
        try{
            threads.push_back(std::thread(&ThreadedGrid::worker, this));
        }
        catch(std::exception &e){
            std::cerr << "there was a thread error" << std::endl;
        }
    }

    for(unsigned int i = 0; i < threads.size(); i++) {
        threads[i].join();
    }

}
void ThreadedGrid::worker(){
    std::vector<int> this_workers_tasks;
    unsigned int i;

    while(jobs_list.size() > 0) {
    this_workers_tasks.resize(0);
    jobs_list.pop_back(this_workers_tasks, 1);
    
    for(i = 0; i < this_workers_tasks.size(); i++) {
      int n = this_workers_tasks[i];
      for (int column  =0; column <getWidth(); column++){
        int num = calculateNumber(n,column);
        setNumber(n,column,num);
      }
    }
    
  }
}
