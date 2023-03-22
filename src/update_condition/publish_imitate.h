#ifndef PUBLISHIMITATE_H
#define PUBLISHIMITATE_H

#include <thread>
#include <iostream>


template<class CallBackType>
class PublishImitate
{
public:
    PublishImitate(){
        std::cout<<"construct PublishImitate "<<std::endl;
    };
    CallBackType cb_ = nullptr;
    void setCallback(CallBackType cb,std::string name)
    {

        cb_ = cb;

        std::thread thread_([this,name](){
            int count=0;
            while(count <50)
            {
                std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                if(cb_)
                cb_(name+ " pub: "+std::to_string(count) );
                else
                {
                   std::cout<<"PublishImitate cb_ nullptr"<<std::endl;
                }
                count++;
            }
        });
        thread_.detach();

    }


};

#endif // PUBLISHIMITATE_H
