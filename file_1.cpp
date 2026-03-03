#include<iostream>
#include<fstream>

/*
    std::
    fstream
    ifstream
    ofstream
    istream cin
    ostream cout

    重载运算符 <<输出,>>输入 -> 根据参数类型自动重载匹配 -> 重载机制让格式化IO更加简单
    getline()
    seekp()
    seekg()
    tellp()
    tellg()
    eof()
    fail()/bad()
    clear()

    输出操纵符,头文件iomanip
    endl
    setw(n)
    setprecision(n)
    fixed
    left/right
    hex/dec/oct

    std::ios::
    in
    out
    binary
    app
    ate
    trunc
    beg
    end
    cur

    C++中文件流定义为fstream/ofstream/ifstream三类，通过对象去操作
    所以文件流通道其本质就是类的对象，并且各文件操作都被封装成了类方法

    fstream f1       文件读写流通道  -> 读写时注意，文件指针是共享的
    ifstream if1     文件输入流通道
    ofstream of1     文件输出流通道
    头文件fstream,命名空间std
    
    open()或者构造函数,close()或者析构函数,is_open() -> 打开成功返回true

    打开方式(命名空间ios) -> 可配合|组合使用，注意与文件流匹配
    函数库包含命名空间，命名空间中定义标识符或关键字
*/

int main(){
    std::fstream f1;
    const char* filename="test.txt";
    std::ifstream f2;

    f1.open(filename,std::ios::in | std::ios::out);
    std::string temp;
    std::string a;
    char temp2[10];
    std::cin.getline(temp2,10,'w');
    std::getline(std::cin,temp,'a');

    if(!f1.is_open())
    {
        perror("open");
        return 0;
    }

    f1<<"hello/jack!";
    char tmp[15];
    
    f1.seekg(0,std::ios::beg);    //重置文件指针

    f1>>tmp;
    std::cout<<tmp<<std::endl;

    
    f1.close();
    return 0;
}