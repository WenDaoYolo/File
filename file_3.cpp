#include<iostream>
#include<fstream>
#include<iomanip>

void test(){
	using namespace std;

	fstream fs;
	fs.open("test.txt",ios::in|ios::out);

	char ch;
	fs<<"abcdef"<<endl;
	fs<<"check";
	fs.seekp(-2,ios::cur);
	fs>>ch;
	cout<<ch;
    cout<<fs.tellg();
	cout<<setw(10)<<right<<fixed<<3.14<<endl;
	fs.ignore();
}

void test2(){
	using namespace std;
	cin.good();
	cin.goodbit;
}

bool CheckAndClear(){
	if(std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore();
		std::cout<<"Êý¾Ý´íÎó"<<std::endl;
		return true;
	}
	return false;
}

void test3(){
	using namespace std;
	int temp1,temp2,a,b;
	
	while(true){
		cin>>temp1>>temp2;
		if(CheckAndClear())
			continue;
			
		a=temp1,b=temp2;
		cout<<a<<" "<<b<<endl;
	}
}

int main(){
    test();
	test3();

    return 0;
}