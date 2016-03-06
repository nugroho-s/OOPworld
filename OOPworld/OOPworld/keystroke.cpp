#include <Windows.h>
#include <iostream>

using namespace std;

int main() {
	while (true) {
		if (GetAsyncKeyState(VK_UP))
		{
			cout << "up" << endl;
		}
		if (GetAsyncKeyState(VK_ESCAPE))
			break;
		Sleep(100);
	}
}