//
// Created by prawi on 27-05-2021.
//

/*
 * Why factory design pattern ?
 *
 *  1. To hide the object creation
 *  2. Is there any requirement to create objects on run time based on some requirement
 */

#include<iostream>
using namespace std;

class BaseMsg
{
public:
    virtual void display()=0;
};

class UpdateLocationMsg:public BaseMsg
{
public:
    void display()
    {
        cout<<"This is UpdateLocation message"<<endl;
    }
};

class CancelLocationMsg:public BaseMsg
{
public:
    void display()
    {
        cout<<"This is CancelLocation message"<<endl;
    }
};

class MsgFactory
{
public:
    BaseMsg* getObject(string s)
    {
        if( s.compare("update") == 0  )
        {
            return new UpdateLocationMsg();
        }
        else if( s.compare( "cancel") == 0 )
        {
            return new CancelLocationMsg();
        }
    }
};

int main()
{
    MsgFactory factoryObj = MsgFactory();

    BaseMsg* updateObj = factoryObj.getObject("update");

    updateObj->display();

    BaseMsg* cancelObj = factoryObj.getObject("cancel");

    cancelObj->display();
}

/*
 * Output :
 * --------
 * This is UpdateLocation message
 * This is CancelLocation message
 *
 */