/*********************************************************************************************************
* AppContainer.hpp
* Note: Phoenix Container AppContainer
* E-mail:<forcemz@outlook.com>
* Data: @2015.03
* Copyright (C) 2015 The ForceStudio All Rights Reserved.
**********************************************************************************************************/
#ifndef CONTAINER_APPCONTAINER_HPP
#define CONTAINER_APPCONTAINER_HPP

#ifndef _WINDOWS_
#include <Windows.h>
#endif
#include <functional>

class AppContainer{
private:
    std::wstring m_app;
    std::wstring m_Args;
    unsigned m_dwFlags;
protected:
    static wchar_t appContainerName[64];
public:
    static bool AppContainerInitialize();
    ///responseTask when Delete Profile failed, execute responseTask callback function ,close container handle
    static bool AppContainerDelete(std::function<bool(unsigned)> responseTask);
    AppContainer(std::wstring app,std::wstring Args,unsigned dwFlags);
    bool Exectue();
};

#endif