// dllmain.cpp : Define o ponto de entrada para o aplicativo DLL.
#include "pch.h"

#include "hooks.h"
#include "unreal.h"
#include <iostream>

static const std::string LOG_FILE_NAME = "HotfixInjector.log";

static HMODULE t_module;

static int32_t startup_thread(void*) {
    try {
        SetThreadDescription(GetCurrentThread(), L"OpenHotfixLoader");

        ohl::args::init(this_module);

        static plog::ConsoleAppender<plog::MessageOnlyFormatter> consoleAppender;
        plog::init(ohl::args::debug() ? plog::debug : plog::info,
            ohl::args::dll_path().replace_filename(LOG_FILE_NAME).c_str())
            .addAppender(&consoleAppender);

        LOGI << "[OHL] Launched " VERSION_STRING;
#ifdef DEBUG
        LOGD << "[OHL] Running debug build";
#endif

        ohl::hooks::init();
        ohl::loader::init();

#ifdef DEBUG
        ohl::loader::reload();
#endif
    }
    catch (std::exception ex) {
        LOGF << "[OHL] Exception occured during initalization: " << ex.what();
    }

    return 1;
}



BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        t_module = hModule;


    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

