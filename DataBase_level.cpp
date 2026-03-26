#include "../include/DataBase.h"

DataBase b1;
bool LoadSuccess=false;

void level_wait()
{
    int choose;
    while(b1.state==BaseState::wait)
    {
        std::cout<<"请选择>";
        std::cin>>choose;

        if(b1.CheckInputError()||choose<=0||choose>=8)
       {
            std::cout<<"输入错误!请重新输入"<<std::endl;
            b1.ClearBuffer();
        }
        else
            b1.state=(BaseState)choose;
    }
    b1.ClearBuffer();                         //输入后清理缓冲区残留的错误数据，防止下次读取错误
}                                             //先清理再输入可能会因缓冲区无数据从而导致程序阻塞

void level_add()
{   
    b1.FlushScreen();                         //输入前先清除上一帧画面  
    Node temp;
    
    while(b1.state==add)
    {
        b1.Input(&temp);
        b1.AddNode(&temp);
        std::cout<<"添加成功!"<<std::endl;
        b1.state=wait;
    }
    b1.ClearBuffer();
}

void level_display()
{
    b1.FlushScreen();
    b1.DisplayInformation();
    b1.state=wait;
}

void level_delete()
{
    b1.FlushScreen();
    if(b1.CheckEmpty())
    {
        std::cout<<"数据库为空!"<<std::endl;
        b1.state=wait;
        return;
    }
    b1.DeleteNode();
    b1.state=wait;
    b1.ClearBuffer();
}

void level_find()
{
    b1.FlushScreen();
    if(b1.CheckEmpty())
    {
        std::cout<<"数据库为空!"<<std::endl;
        b1.state=wait;
        return;
    }
    b1.FindNode();
    b1.state=wait;
    b1.ClearBuffer();
}

void level_change()
{
    b1.FlushScreen();
    if(b1.CheckEmpty())
    {
        std::cout<<"数据库为空！"<<std::endl;
        b1.state=wait;
        return;
    }
    b1.ChangeNode();
    b1.state=wait;
    b1.ClearBuffer();
}

void level_sort()
{
    b1.FlushScreen();
    if(b1.CheckEmpty())
    {
        std::cout<<"数据库为空！"<<std::endl;
        b1.state=wait;
        return;
    }

    char key1_buffer[10];
    char key2_buffer[6];
    CmpOrder sys;

    while(b1.state==sort)
    {
        std::cout<<"请输入排序的关键字[ID|姓名|性别|年龄 升序|降序]>";
        std::cin>>key1_buffer>>key2_buffer;
        
        if(!strcmp(key2_buffer,"升序"))
            sys=Up;
        else if(!strcmp(key2_buffer,"降序"))
            sys=Down;
        else
        {
            std::cout<<"输入无效，请重新输入!"<<std::endl;
            b1.ClearBuffer();
            continue;
        }

        if(!strcmp(key1_buffer,"ID"))
            b1.SortNode(sys,CmpById);
        else if(!strcmp(key1_buffer,"姓名"))
            b1.SortNode(sys,CmpByName);
        else if(!strcmp(key1_buffer,"性别"))
            b1.SortNode(sys,CmpBySex);
        else if(!strcmp(key1_buffer,"年龄"))
            b1.SortNode(sys,CmpByAge);
        else
        {
            std::cout<<"输入无效，请重新输入!"<<std::endl;
            b1.ClearBuffer();
            continue;
        }
        std::cout<<"排序成功!"<<std::endl;
        b1.state=wait;
    }
    b1.ClearBuffer();
}

void init(const char* filename)
{
    bool result=b1.LoadFile(filename);
    if(result==false)
    {
        std::cout<<"文件加载失败!"<<std::endl;
        LoadSuccess=false;
        return;
    }
    std::cout<<"文件加载成功!"<<std::endl;
    LoadSuccess=true;
}

void loop()
{
    b1.DisplayMenu();
    while(b1.state!=BaseState::exit_s)
    {    
        switch(b1.state)
        {
            case wait:
                level_wait();
                break;
            case add:
                level_add();
                break;
            case del:
                level_delete();
                break;
            case find:
                level_find();
                break;
            case change:
                level_change();
                break;
            case sort:
                level_sort();
                break;
            case display:
                level_display();
                break;
            default:
                break;
        }
    }
}

void destroy(const char* filename)
{
   b1.SaveFile(filename);
}

void level_database(const char* filename)
{
    init(filename);
    if(LoadSuccess)
    {
        loop();
        destroy(filename);
    }
}