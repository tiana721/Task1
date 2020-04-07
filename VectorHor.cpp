#include"VectorHor.h"
#include<iostream>
#include <fstream>
void VectorHor::Output() const{
    std::ofstream fil;
    fil.open(this->get_file().c_str(), std::ios_base::out | std::ios::trunc);
    if (!fil.is_open()) {
      //throw std::invalid_argument("Error! Cannot open file " + this->get_filename() + "!\n");
      std::cout<<"Error! Cannot open output file"<<std::endl;
    }
    for (int i = 0; i < this->get_len(); i++) {
      fil << this->Geti(i) << ' ';
    }
    fil.close();
    return;
}

VectorHor::VectorHor(const Vector& other)
    : Vector(other)
{
}

VectorHor::VectorHor(const VectorHor& other)
    : Vector(other)
{
}

VectorHor::VectorHor()
 : Vector()
 {
 }

VectorHor::~VectorHor() {
}

VectorHor operator-(Vector& first, Vector& second) {
    if (first.get_len() != second.get_len()) {
      //throw std::invalid_argument("Different sizes");
      std::cout<<"Error: Different sizes"<<std::endl;
    }
    VectorHor res;
    //std::cout<<"Hor+"<<std::endl;
    //first.print();
    //std::cout<<"IN Hor+"<<first.get_file()<<std::endl;
    res.Set_fname(first.get_file());
    for (int i = 0; i < first.get_len(); i++) {
      //res[i] = first[i] + second[i];
      res.Set(first[i] - second[i]);
    }
    return res;
}

VectorHor operator+(VectorHor& first, VectorHor& second) {
    if (first.get_len() != second.get_len()) {
      //throw std::invalid_argument("Vectors have different lengths!");
      std::cout<<"Error: Different sizes"<<std::endl;
    }
    //VectorHor retVector( first.get_size(), first.get_filename() );
    VectorHor res;
    //std::cout<<"Hor+"<<std::endl;
    //first.print();
    //std::cout<<"IN Hor+"<<first.get_file()<<std::endl;
    res.Set_fname(first.get_file());
    for (int i = 0; i < first.get_len(); i++) {
      //res[i] = first[i] + second[i];
      res.Set(first[i] + second[i]);
    }
    return res;
}

double operator*(Vector& first, Vector& second) {
    if (first.get_len() != second.get_len()) {
      //throw std::invalid_argument("Different sizes");
      std::cout<<"Error: Different sizes"<<std::endl;
    }
    double res = 0;
    //std::cout<<"Hor+"<<std::endl;
    //first.print();
    //std::cout<<"IN Hor+"<<first.get_file()<<std::endl;
    for (int i = 0; i < first.get_len(); i++) {
      //res[i] = first[i] + second[i];
      res += first[i] * second[i];
    }
    return res;
}
