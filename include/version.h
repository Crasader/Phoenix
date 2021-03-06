/*********************************************************************************************************
* version.h
* Note: Phoenix version.h
* Date: @2015.04
* E-mail:<forcemz@outlook.com>
* Copyright (C) 2015 The ForceStudio All Rights Reserved.
**********************************************************************************************************/
#ifndef PHOENIX_VERSION_DEFINED
#define PHOENIX_VERSION_DEFINED 1

#define TOSTR_(a) L#a
#define TOSTR(a) TOSTR_(a)
#define TOSTRING(str) TOSTR(str)

#define NOW_YEAR 2015
#define PHOENIX_VERSION_MAJRO 1
#define PHOENIX_VERSION_MINRO 0
#define PHOENIX_VERSION_PATCH 0
#define PHOENIX_VERSION_BUILDS 10

#define VERSION_STRING   TOSTRING(PHOENIX_VERSION_MAJRO.PHOENIX_VERSION_MINRO.PHOENIX_VERSION_PATCH.PHOENIX_VERSION_BUILDS)
#define VERSION_WORDS  PHOENIX_VERSION_MAJRO,PHOENIX_VERSION_MINRO,PHOENIX_VERSION_PATCH,PHOENIX_VERSION_BUILDS

#define COPYRIGHT L"Copyright \x00A9 "
#define RESERVEDINFO " The Force Studio.All Rights Reserved."
#define YEARSTRING TOSTR(NOW_YEAR)


#endif

