#include<Windows.h>
#include<tchar.h>
LRESULT CALLBACK WinProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR strCmdLine, int nShowCmd)
{
	WNDCLASSEX wcex;			//Windows information structure
	memset(&wcex, 0, sizeof(wcex));

	wcex.cbSize			= sizeof(wcex);						//size of Windows structure
	wcex.style			= CS_HREDRAW | CS_VREDRAW;				//class style
	wcex.hbrBackground	= (HBRUSH)GetStockObject(LTGRAY_BRUSH);				//client background color
	wcex.hCursor			= LoadCursor(NULL, IDC_ARROW);				//cursor shape
	wcex.hIcon			= LoadIcon(NULL, IDI_APPLICATION);			//icon shape
	wcex.hInstance		= hInstance;							//program number
	wcex.cbClsExtra		= 0;								//
	wcex.cbWndExtra		= 0;								//
	wcex.hIconSm			= NULL;							//
	wcex.lpszMenuName		= NULL;							//
	wcex.lpfnWndProc		= WinProc;						//Function that manage Message (place to put function pointer)메시지 처리 함수 (함수 포인터를 담는 장소)
	wcex.lpszClassName	= L"MyWindow";							//Windows class name of the above setting
	RegisterClassEx(&wcex);
	///////


	//Making
	HWND hWnd = CreateWindow(L"MyWindow", L"MyWindow", WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);

	if(hWnd == NULL)
	{
		MessageBox(NULL, L"failed to creat Windows", L"errors", MB_ICONERROR | MB_OK);
		return -1;
	}

	//output
	ShowWindow(hWnd, SW_SHOW);


	MSG msg;
	memset(&msg, 0, sizeof(msg));
	while(GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return 0;
}

LRESULT CALLBACK WinProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch(uMsg)
	{
	case WM_DESTROY:
		{
			PostQuitMessage(0);
			break;
		}
	}
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}
