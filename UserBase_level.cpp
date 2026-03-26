#include "../include/UserBase.h"

UserBase u1;
char g_filename[64];
bool g_LoginSuccess;

void level_wait_user()
{
    int choose;
    while(u1.state==Wait)
    {   
        std::cout<<"ÇëÑ¡Ôñ>";
        std::cin>>choose;

        if(u1.CheckInputError()||choose<1||choose>3)
        {
            std::cout<<"ÊäÈë´íÎó!"<<std::endl;
            u1.ClearBuffer();
        }
        else
            u1.state=(UserState)choose;
    }
    u1.ClearBuffer();
}

void level_login()
{
    u1.FlushScreen();
    u1.Login(g_filename);
    u1.ClearBuffer();

    if(u1.state==Success)
        g_LoginSuccess=true;
}

void level_regisiter()
{
    u1.FlushScreen();
    u1.Regisiter();
    u1.ClearBuffer();
}

void init_user()
{
    strcpy(g_filename,"NULL");
    g_LoginSuccess=false;
}

void loop_user()
{
    u1.PrintMenu();
    while(u1.state!=Exit&&u1.state!=Success)
    {
        switch(u1.state)
        {
            case Wait:
                level_wait_user();
                break;
            case Login:
                level_login();
                break;
            case Regisiter:
                level_regisiter();
                break;
            default:
                break;
        }
    }
}

void destroy_user()
{
    ;
}

void level_userbase()
{
    init_user();
    loop_user();
    destroy_user();
}