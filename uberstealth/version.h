#pragma once

#define UBERSTEALTH_MAJOR 1
#define UBERSTEALTH_MINOR 0
#define UBERSTEALTH_PATCH 0
#define UBERSTEALTH_PRODUCT_NAME L"uberstealth"
#define REMOTESTEALTH_PRODUCT_NAME L"uberstealth remote server"

#ifdef _DEBUG
	#define UBERSTEALTH_BUILD L" debug build"
#else
	#define UBERSTEALTH_BUILD L""
#endif
#define UBERSTEALTH_SPECIAL_BUILD L"ALPHA 2"

#define UBERSTEALTH_COPYRIGHT L"Copyright (C) 2011-2012 Jan Newger"

#define VSTRING(s) L#s
#define VERSION_STRING(a,b,c) VSTRING(a) L"." VSTRING(b) L"." VSTRING(c)
#define FILE_VERSION_STRING(a,b,c,d) VSTRING(a) L"," VSTRING(b) L"," VSTRING(c) L"," VSTRING(d)

#define UBERSTEALTH_PRODUCT_VERSION_STRING L"v" VERSION_STRING(UBERSTEALTH_MAJOR,UBERSTEALTH_MINOR,UBERSTEALTH_PATCH)
#define UBERSTEALTH_FILE_VERSION_STRING FILE_VERSION_STRING(UBERSTEALTH_MAJOR,UBERSTEALTH_MINOR,UBERSTEALTH_PATCH,0)
#define ILDASTEALTH_FILE_VERSION_NUM UBERSTEALTH_MAJOR,UBERSTEALTH_MINOR,UBERSTEALTH_PATCH,0

#ifdef UBERSTEALTH_SPECIAL_BUILD
	#define UBERSTEALTH_NAME UBERSTEALTH_PRODUCT_NAME L" " UBERSTEALTH_PRODUCT_VERSION_STRING L" (" UBERSTEALTH_SPECIAL_BUILD L")"
	#define REMOTESTEALTH_NAME REMOTESTEALTH_PRODUCT_NAME L" " UBERSTEALTH_PRODUCT_VERSION_STRING L" (" UBERSTEALTH_SPECIAL_BUILD L")"
	#define UBERSTEALTH_INFO_STRING UBERSTEALTH_NAME UBERSTEALTH_BUILD L", " UBERSTEALTH_COPYRIGHT
	#define REMOTESTEALTH_INFO_STRING REMOTESTEALTH_NAME UBERSTEALTH_BUILD L"\n" UBERSTEALTH_COPYRIGHT
#else
	#define UBERSTEALTH_NAME UBERSTEALTH_PRODUCT_NAME L" " UBERSTEALTH_PRODUCT_VERSION_STRING
	#define REMOTESTEALTH_NAME REMOTESTEALTH_PRODUCT_NAME L" " UBERSTEALTH_PRODUCT_VERSION_STRING
	#define UBERSTEALTH_INFO_STRING UBERSTEALTH_NAME UBERSTEALTH_BUILD L", " UBERSTEALTH_COPYRIGHT
	#define REMOTESTEALTH_INFO_STRING REMOTESTEALTH_NAME UBERSTEALTH_BUILD L"\n" UBERSTEALTH_COPYRIGHT
#endif
