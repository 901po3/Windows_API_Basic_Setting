#include<Windows.h>
#include<tchar.h>
LRESULT CALLBACK WinProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR strCmdLine, int nShowCmd)
{
	////��ϰ���

	WNDCLASSEX wcex;			//������ ���� ����ü
	memset(&wcex, 0, sizeof(wcex));

	wcex.cbSize			= sizeof(wcex);							//������ ����ü ũ��
	wcex.style			= CS_HREDRAW | CS_VREDRAW;					//Ŭ���� ��Ÿ��
	wcex.hbrBackground	= (HBRUSH)GetStockObject(LTGRAY_BRUSH);		//Ŭ���̾�Ʈ ����
	wcex.hCursor			= LoadCursor(NULL, IDC_ARROW);				//Ŀ�� ���
	wcex.hIcon			= LoadIcon(NULL, IDI_APPLICATION);			//������ ���
	wcex.hInstance		= hInstance;								//���α׷� ��ȣ
	wcex.cbClsExtra		= 0;										//
	wcex.cbWndExtra		= 0;										//
	wcex.hIconSm			= NULL;									//
	wcex.lpszMenuName		= NULL;									//
	wcex.lpfnWndProc		= WinProc;								//�޽��� ó�� �Լ� (�Լ� �����͸� ��� ���)
	wcex.lpszClassName	= L"MyWindow";							//�� ������ ������ Ŭ���� �̸�
	RegisterClassEx(&wcex);
	///////


	//�����
	HWND hWnd = CreateWindow(L"MyWindow", L"MyWindow", WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);

	if(hWnd == NULL)
	{
		MessageBox(NULL, L"������ ���� ����", L"����", MB_ICONERROR | MB_OK);
		return -1;
	}

	//���
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
