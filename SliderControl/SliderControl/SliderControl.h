
// SliderControl.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CSliderControlApp:
// �� Ŭ������ ������ ���ؼ��� SliderControl.cpp�� �����Ͻʽÿ�.
//

class CSliderControlApp : public CWinApp
{
public:
	CSliderControlApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CSliderControlApp theApp;