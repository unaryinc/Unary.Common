#include <Unary.Shear/Core/App.hpp>

#ifdef _WIN32
#include <Windows.h>
extern "C" __declspec(dllexport) DWORD NvOptimusEnablement = 0x00000001;
extern "C" __declspec(dllexport) int AmdPowerXpressRequestHighPerformance = 1;
int wmain(int argc, wchar_t* argv[])
#else
int main(int argc, char* argv[])
#endif
{
	Unary::Shear::Core::App* AppPtr = Unary::Shear::Core::App::Get();
	AppPtr->Init(argc, argv);

	//Place to add systems from

	AppPtr->Run();

	return AppPtr->ReturnCode;
}