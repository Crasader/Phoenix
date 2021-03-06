/*********************************************************************************************************
* PhoenixThread.cpp
* Note: Phoenix Thread
* Date: 2014.08
* E-mail:<forcemz@outlook.com>
* Copyright (C) 2015 The ForceStudio All Rights Reserved.
**********************************************************************************************************/
#include <Phoenix.h>
#include "PhoenixThread.hpp"

/*
Syntax

HWND WINAPI GetSendMessageReceiver ( 
    DWORD threadId 
)

URL: http://undoc.airesoft.co.uk/user32.dll/GetSendMessageReceiver.php
*/

PhoenixThread::PhoenixThread(ThreadCallBack efunc,LPVOID param):m_param(param),hThread(nullptr),
m_eFunc(efunc),
IdOfThread(0)
{

}
//Create a Thread
bool PhoenixThread::Run()
{
    hThread =static_cast<HANDLE>(CreateThread(NULL, 0, m_eFunc, m_param, 0, &IdOfThread));
    if(!hThread){
        return false;
    }
    IsRunOnce=true;
    return true;
}

bool PhoenixThread::Suspend()
{
    if(!hThread)
        return false;
    if(SuspendThread(hThread)==-1)
        return false;
    return true;
}

bool PhoenixThread::Resume()
{
    if(!hThread)
        return false;
    if(ResumeThread(hThread)==-1)
        return false;
    return true;
}

//Kill this Thread,do not it will hunk
bool PhoenixThread::Exit()
{
    ///HANDLE hThread = OpenThread(THREAD_ALL_ACCESS, FALSE, IdOfThread);
    if (hThread)
    {
        TerminateThread(hThread, 13);
        CloseHandle(hThread);
        return true;
    }
    hThread=nullptr;
    return false;
}

