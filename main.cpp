#include <iostream>
#include <fstream>
#include "Vector.h"
#include "VectorVert.h"
#include "VectorHor.h"
#include <list>
#include <algorithm>
#include <functional>
#include <iterator>
#include <string>
#include <sstream>
#include <cstdlib>
#include "test.h"
using namespace std;
int main(void){
    test1();
    test2();
    test3();
    test4();
    test5();
    cout<<endl<<endl;
    Vector **arr;
    int cnt = 0, i = 0;
    string name, line, out = "a.txt";
    name = "in.txt";
    //Vector Qv(5, name);
    /*p = &a;
    p->fun();
    p = &v;
    p->fun();
    std::cout<<"OK";*/
    ifstream fin("in.txt");
    if(!fin){
       cout<<"Error"<<endl;
       return 0;
    }
    while(getline(fin, line)){cnt++;}
    arr = new Vector*[sizeof(Vector*)*cnt];
    //cout<<"cnt="<<cnt<<endl;
    fin.clear();
    fin.seekg(0, ios_base::beg);
    ///
    i = 0;
    cout<<endl<<"ARRAY OF VECTORS"<<endl;
    while(i<cnt){
        getline(fin, line);
        std::list<std::string> words;
        cout << line << endl;
        istringstream ist(line);
        string tmp;
        while (ist >> tmp)
            words.push_back(tmp);
        //std::copy(words.begin(), words.end(), std::ostream_iterator<std::string>(std::cout, "\n"));
        if(*words.begin() == "0"){arr[i] = new VectorVert();}
        else if(*words.begin() == "1"){arr[i] = new VectorHor();}
        //arr[i] = check(*words.begin());
        std::list<std::string> :: iterator it = words.begin(), last = words.end();
        //auto it = words.begin();
        //cout<<*it<<endl;
        ++it;
        //cout<<*it<<endl;
        arr[i]->Set_fname(*it);
        ++it;
        while(it!=last){
            arr[i]->Set(atof((*it).c_str()));
            ++it;
        }
        ///arr[i] = check(line);
        arr[i]->Output();
        cout<<endl;
        arr[i]->print(); //print array of vectors
        cout<<endl;
        i++;
    }
    cout<<"END"<<endl<<endl<<endl;
    VectorHor v1;
    v1.Set(1);
    v1.Set(2);
    v1.Set_fname("b.txt");
    v1.print();
    VectorVert v3, v2;
    v2.Set_fname("str");
    v2.Set(3);
    v2.Set(4);
    v2.print();
    v3.Set(3);
    v3.Set(3);
    v3.print();
    VectorVert res(v3 + v2);
    res.Output();
    cout<<"res"<<endl;
    res.print();
    v1 = v2;
    v1.print();
    fin.close();
    for(int i = 0; i < cnt; i++) delete arr[i];
    delete[] arr;
    return 0;
}
