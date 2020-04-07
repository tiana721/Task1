#ifndef VECTORVERT_H_INCLUDED
#define VECTORVERT_H_INCLUDED
#include"Vector.h"
#include<iostream>
class VectorVert: public Vector{
    public:
           VectorVert();
           virtual void Output() const;
           void fun(){std::cout<<"Fun in veRt"<<std::endl;};
           VectorVert(const Vector& other);
           using Vector::operator=;
           friend VectorVert operator+(Vector& first, Vector& second);
           //friend VectorVert operator+(Vector& first, Vector& second);
           ~VectorVert();
};

#endif // VECTORVERT_H_INCLUDED
