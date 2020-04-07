#include"VectorVert.h"
#include<iostream>
#include <fstream>
void VectorVert::Output() const{
    std::ofstream fil;
    //fil.open(this->get_filename().c_str(), std::ios_base::app);
    fil.open(this->get_file().c_str(), std::ios_base::out | std::ios::trunc);
    if (!fil.is_open()) {
      //throw std::invalid_argument("Error! Cannot open file " + this->get_filename() + "!\n");
      //throw std::invalid_argument("Error! Cannot open output file");
      std::cout<<"Error! Cannot open output file"<<std::endl;
    }
    for (int i = 0; i < this->get_len(); i++) {
      fil << this->Geti(i) << '\n';
    }
    //fil << this->i << '\n';
    //fil << std::endl;
    fil.close();
    //std::cout<<"in vert"<<std::endl;
    return;
}

VectorVert::VectorVert()
 : Vector()
 {
 }

 VectorVert::VectorVert(const Vector& other)
    : Vector(other)
  {
  }

VectorVert::~VectorVert() {
}

/*VectorVert operator+(Vector& first, Vector& second) {
    if (first.get_len() != second.get_len()) {
      std::cout<<"Vectors have different lengths!"<<std::endl;
    }
    //VectorHor retVector( first.get_size(), first.get_filename() );
    VectorVert res;
    res.Set_fname(first.get_file());
    std::cout<<"Vert+"<<std::endl;
    for (int i = 0; i < first.get_len(); i++) {
      //res[i] = first[i] + second[i];
      res.Set(first[i] + second[i]);
    }
    return res;
}*/
VectorVert operator+(Vector& first, Vector& second) {
    if (first.get_len() != second.get_len()) {
      //throw std::invalid_argument("Different sizes");
      std::cout<<"Error: Different sizes"<<std::endl;
    }
    //VectorHor retVector( first.get_size(), first.get_filename() );
    VectorVert res;
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
