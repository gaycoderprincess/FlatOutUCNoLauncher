#include <windows.h>
#include "nya_commonhooklib.h"
#include "fo2versioncheck.h"

BOOL WINAPI DllMain(HINSTANCE, DWORD fdwReason, LPVOID) {
	switch( fdwReason ) {
		case DLL_PROCESS_ATTACH: {
			DoFlatOutVersionCheck(FO2Version::FOUC_GFWL);
			NyaHookLib::PatchRelative(NyaHookLib::JMP, 0x55B49A, 0x55B4BC);
			NyaHookLib::PatchRelative(NyaHookLib::JMP, 0x55B4DF, 0x55B538);
			NyaHookLib::Fill(0x55B53D, 0x90, 5);
			NyaHookLib::Fill(0x55B55B, 0x90, 2);
			NyaHookLib::Patch<uint8_t>(0x55B6D2, 0xEB);
		} break;
		default:
			break;
	}
	return TRUE;
}