#ifndef VECTORHOR_H_INCLUDED
#define VECTORHOR_H_INCLUDED
#include"Vector.h"
#include<iostream>
class VectorHor: public Vector{
    public:
           VectorHor();
           //virtual void Output() const override final;
           virtual void Output() const;
           void fun(){std::cout<<"Fun in hor"<<std::endl;};
           using Vector::operator=;
           VectorHor(const VectorHor& other);
           VectorHor(const Vector& other);
           friend VectorHor operator-(Vector& first, Vector& second);
           friend VectorHor operator+(VectorHor& first, VectorHor& second);
           friend double operator*(Vector& first, Vector& second);
           ~VectorHor();
};

#endif // VECTORHOR_H_INCLUDED
