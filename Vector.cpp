#include<iostream>
#include"Vector.h"
#include <stdexcept>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <sstream>
using namespace std;

void Vector::print(){
    cout<<"len= "<<len<<"  rlen= "<<rlen<<endl;
    cout<<"file= "<<file<<endl;
    for(int i=0; i<rlen; i++) cout<<arr[i]<<" ";
    cout<<endl;
}

void Vector::Set(double num){
    if(rlen + 1 >= len){
       double *buff = new double[(rlen + 1) * 2];
       memset(buff,0, sizeof(double)*(rlen + 1) * 2);
       memcpy(buff, arr, len*sizeof(double));
       delete[] arr;
       arr = buff;
       len = (rlen + 1) * 2;
    }
    arr[rlen] = num;
    rlen++;

}

Vector::Vector(const Vector& other) {
    //filename_ = other.filename_;
    len = other.len;
    rlen = other.rlen;
    file = other.file;
    arr = new double[rlen];
    for (int i = 0; i < rlen; i++) {
      arr[i] = other.arr[i];
    }
}

void Vector::Set_fname(const string& fname){
    file = fname;
    return;
}

Vector::Vector(const int len_, const string& fname) {
    file = fname;

    // output file cleanup
    ofstream fil(file.c_str());
    //fil.open(file);
    if (!fil) {
      cout<<"Error! Cannot open file "<<endl;
      exit(1);
    }
    fil.close();
    len = len_;
    arr = new double[len];
    memset(arr,0, sizeof(double)*len);
}

Vector& Vector::operator=(const Vector& other) {
    //filename_ = other.filename_;
    len = other.len;
    rlen = other.rlen;
    file = other.file;
    if (arr) {
      delete[] arr;
    }
    arr = new double[rlen];
    for (int i = 0; i < rlen; i++) {
      arr[i] = other.arr[i];
    }
    return *this;
}

double& Vector::operator[](int i) {
    if (i >= rlen) {
      cout<<"Error: Index is out of range!\n"<<endl;
    }
    return arr[i];
}

int Vector::get_len() const{
    return this->rlen;
}

Vector::~Vector() {
    len = 0;
    rlen = 0;
    delete[] arr;
}

string Vector::get_file() const{
    return file;
}

double Vector::Geti(int ind) const{
    if(ind < rlen)
       return arr[ind];
    cout<<"List ind out of range"<<endl;
    return 0;
}

/*Vector::Vector(int len_, const std::string& fname) {
    file = fname;

    // output file cleanup
    std::ofstream fil;
    fil.open(fname.c_str(), std::ios_base::out | std::ios::trunc);
    if (!fil.is_open()) {
      throw std::invalid_argument("Error! Cannot open file " + fname + "!\n");
    }
    fil.close();
    r
    len = len_;
    arr = new double[len];
    for (int i = 0; i < len; i++) {
      arr[i] = 0;
    }
}*/
