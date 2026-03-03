#include<fstream>
#include<iostream>
#include<cstring>

void test1(){
    using namespace std;

    fstream f1;
    f1.open("test.txt",ios::in|ios::out);
    char temp[10];
    string t2;

    f1.getline(temp,10);
    f1.seekg(0,ios::beg);
    getline(f1,t2);

    cout<<temp<<endl;
    cout<<t2<<endl;
}

struct student{
	int age;
	char name[10];
};

void test2()
{
    using namespace std;
	fstream fs;
	fs.open("test.txt",ios::in|ios::out|ios::binary);
	
	student s1={3,"张三"};
	student s2={0,"NULL"};
	fs.write((char*)&s1,sizeof(s1));
    fs.seekg(0,ios::beg);
	fs.read((char*)&s2,sizeof(s2));
	cout<<s2.name<<" "<<s2.age<<endl;
}

void test3(){
    std::fstream f1;
    f1.open("test.txt",std::ios::in|std::ios::ate);
    if(!f1.is_open())
    {
        std::cerr<<"f1.open()打开失败"<<std::endl;
        std::clog<<"time:2026-3-2 acthor:lyy"<<std::endl;
        return;
    }   

    std::string name;
    f1.close();
}

int main(){
    test1();
    test2();
    test3();

    return 0;
}