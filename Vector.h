#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED
#include<iostream>
class Vector
{
    int len, rlen;
    double *arr;
    std::string file;
    public:
           std::string get_file() const;
           Vector(int len_, const std::string& fname);
           //Vector(int n){ len = n; };
           void Set(double num);
           void Set_fname(const std::string& fname);
           double Geti(int ind) const;
           Vector(){len = 0; rlen = 0; arr = NULL; file = "empty";};
           virtual void Output() const = 0;
           //Vector(double num){ };
           virtual void fun(){ std::cout<<"Fun in vect"<<std::endl;};
           Vector(const Vector& other);
           Vector& operator=(const Vector& other);
           double& operator[](int i);
           int get_len() const;
           virtual ~Vector();
           void print();

};
#endif // VECTOR_H_INCLUDED
