#include "StdAfx.h"
#include "OtherAction.h"
#include <string.h>
#include <basetsd.h>
#include <iostream>
#include <map>
#include <windows.h>
using namespace std;

extern wstring g_ExtReleaseVersion;

void COtherAction::Initialize()
{
	// g_HookManager.WriteCall(0x64418E, COtherAction::CreateWindowExWHook, 1);
}

HWND COtherAction::CreateWindowExWHook(DWORD dwExStyle,LPCWSTR lpClassName,LPCWSTR lpWindowName,DWORD dwStyle,int X,int Y,int nWidth,int nHeight,HWND hWndParent,HMENU hMenu,HINSTANCE hInstance,LPVOID lpParam)
{
	DWORD dwSize;
	TCHAR File[256];
	
	GetModuleFileName( GetModuleHandle(_T("extensor.dll")), File, 256 );
	dwSize = GetFileVersionInfoSize(File, NULL);
	LPVOID pData = new char[dwSize];
	memset(pData, 0, dwSize);
	
	GetFileVersionInfo(File, NULL, dwSize, pData);
	LPVOID pVersion = NULL;
	UINT dwVersionLen;
	
	VerQueryValue(pData, _T("\\StringFileInfo\\041504b0\\ProductVersion"), &pVersion, &dwVersionLen);

	// delete [] pData;
	wstring wTitle = L"L2Server - IlExt ";

	g_ExtReleaseVersion = wTitle;
	wTitle += L" - Vanganth@hotmail.com";
	//Custom title
	//wTitle = "My Custom Title";

	// g_SplashScreen.Hide();
	return CreateWindowExW(dwExStyle, lpClassName, wTitle.c_str(), dwStyle, X, Y, nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam);
}