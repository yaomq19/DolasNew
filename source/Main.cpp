#include "Dolas.h"

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE prevInstance,
    _In_ LPSTR cmdLine, _In_ int showCmd)
{
    if (g_dolas_context.Initialize(hInstance, 1280, 720, L"Dolas"))
    {
        g_dolas_context.Run();
    }

    g_dolas_context.Clear();
    return 0;
}




