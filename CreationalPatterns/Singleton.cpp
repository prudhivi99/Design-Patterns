#include<iostream>
using namespace std;

class Singleton
{
    static Singleton* instance;
    //Private constructor
    Singleton() { }

    public:

    static Singleton* getInstance();
};

Singleton* Singleton::instance = nullptr;

Singleton* Singleton::getInstance()
{
    if( instance == nullptr )
    {
        cout<<"object is creating for first time"<<endl;
        instance = new Singleton();
    }
    return instance;
}

int main()
{
    Singleton* obj  = Singleton::getInstance();
    Singleton* obj1 = Singleton::getInstance();
    Singleton* obj2 = Singleton::getInstance();
}
