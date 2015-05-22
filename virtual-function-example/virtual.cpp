#include <iostream>

class A
{
public:
    virtual const char* fetchClassName() { return "A"; }
};

class B: public A
{
public:
    virtual const char* fetchClassName() { return "B"; }
};

int main(void)
{
   B obj_b;
   A &obj_a = obj_b;
   std::cout << obj_a.fetchClassName() << "\n";
}