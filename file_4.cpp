#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

void test1(){
	ifstream ifs("test.txt",ios::in);
	
	char a;
	while(ifs>>a)
        cout<<a;
    cout<<endl;
}

void test2(){
	ifstream ifs("test.txt",ios::in);
	
	char a[10];
	while(ifs.getline(a,10))
	    cout<<a;
    cout<<endl;
	
    ifs.clear();
    ifs.seekg(0,ios::beg);

	string b;
	while(getline(ifs,b))
	    cout<<b;
    cout<<endl;
}

void test3(){
	ifstream ifs("test.txt",ios::in);
	
	char a;
	while(ifs.read((char*)&a,sizeof(a)))
	    cout<<a;
    cout<<endl;
}

int main(){
    test1();
    test2();
    test3();

    return 0;
}