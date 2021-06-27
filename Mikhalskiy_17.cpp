#include "MyForm.h"
#include <Windows.h>
#include "pch.h"
using namespace Mikhalskiy17;


int main()
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Application::Run(gcnew MyForm);
    return 0;
}