#include "main.h"

void SAMPGDK_CALL PrintTickCountTimer(int timerid, void *params) {
    sampgdk_logprintf("Tick count: %d", GetTickCount());
}

PLUGIN_EXPORT bool PLUGIN_CALL OnPublicCall(AMX *amx, const char *name, cell *params, cell *retval) {
    sampgdk_logprintf("OnPublicCall: %s", name);
    return true;
}

PLUGIN_EXPORT bool PLUGIN_CALL OnGameModeInit() {
    SetGameModeText("Hello, World!");
    AddPlayerClass(0, 1958.3783f, 1343.1572f, 15.3746f, 269.1425f,
                    0, 0, 0, 0, 0, 0);
    SetTimer(1000, true, PrintTickCountTimer, 0);
    return true;
}

PLUGIN_EXPORT unsigned int PLUGIN_CALL Supports() {
    return sampgdk_Supports() | SUPPORTS_PROCESS_TICK;
}

PLUGIN_EXPORT bool PLUGIN_CALL Load(void **ppData) {
    return sampgdk_Load(ppData);
}

PLUGIN_EXPORT void PLUGIN_CALL Unload() {
    sampgdk_Unload();
}

PLUGIN_EXPORT void PLUGIN_CALL ProcessTick() {
    sampgdk_ProcessTick();
}