#include<Windows.h>
#include<tchar.h>
LRESULT CALLBACK WinProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR strCmdLine, int nShowCmd)
{
	////등록과정

	WNDCLASSEX wcex;			//윈도우 정보 구조체
	memset(&wcex, 0, sizeof(wcex));

	wcex.cbSize			= sizeof(wcex);							//윈도우 구조체 크기
	wcex.style			= CS_HREDRAW | CS_VREDRAW;					//클래스 스타일
	wcex.hbrBackground	= (HBRUSH)GetStockObject(LTGRAY_BRUSH);		//클라이언트 배경색
	wcex.hCursor			= LoadCursor(NULL, IDC_ARROW);				//커서 모양
	wcex.hIcon			= LoadIcon(NULL, IDI_APPLICATION);			//아이콘 모양
	wcex.hInstance		= hInstance;								//프로그램 번호
	wcex.cbClsExtra		= 0;										//
	wcex.cbWndExtra		= 0;										//
	wcex.hIconSm			= NULL;									//
	wcex.lpszMenuName		= NULL;									//
	wcex.lpfnWndProc		= WinProc;								//메시지 처리 함수 (함수 포인터를 담는 장소)
	wcex.lpszClassName	= L"MyWindow";							//위 설정의 윈도우 클래스 이름
	RegisterClassEx(&wcex);
	///////


	//만들기
	HWND hWnd = CreateWindow(L"MyWindow", L"MyWindow", WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);

	if(hWnd == NULL)
	{
		MessageBox(NULL, L"윈도우 생성 실패", L"에러", MB_ICONERROR | MB_OK);
		return -1;
	}

	//출력
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
