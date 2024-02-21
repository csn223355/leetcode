
/**
 * @file virtue_function.cpp
 * @author chenshining
 * @brief 
 * @version 0.1
 * @date 2024-01-15
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <iostream>
#include <vector>
#include <string>

class A{
private:
    std::string m_data1 {"A::m_data1"};
    std::string m_data2 {"A::m_data2"};

public:
    virtual void v_funA(){
        std::cout << "A::v_funA() 被调用。" << std::endl;
    }
    virtual void v_funB(){
        std::cout << "A::v_funB() 被调用。" << std::endl;
    }
    void funA(){
        std::cout << "A::funA() 被调用。" << std::endl;
    }
    void funB(){
        std::cout << "A::funB() 被调用。" << std::endl;
    }
};

class B : public A{

private:
    std::string m_data3 {"B::m_data3"};
    std::string m_data4 {"B::m_data4"};

public:
    virtual void v_funA(){
        std::cout << "B::v_funA() 被调用。" << std::endl; 
    }
    void funA(){
        std::cout << "B::funA() 被调用。" << std::endl;
    }

};

class C : public B{

private:
    std::string m_data5 {"C::m_data5"};
    std::string m_data6 {"C::m_data6"};

public:
    virtual void v_funA(){
        std::cout << "C::v_funA() 被调用。" << std::endl; 
    }
    void funA(){
        std::cout << "C::funA() 被调用。" << std::endl;
    }

};




int main(){

    A a;
    B b;
    C c;
    A *p = &a;
    p->v_funA();
    p->v_funB();
    p->funA();
    p->funB();
    

    p = &b;
    p->v_funA();
    p->funA();
    // p->funB();

    p = &c;
    p->v_funA();
    p->funA();
    return 0;
}
