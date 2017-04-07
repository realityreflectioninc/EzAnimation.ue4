#pragma once

#include "ModuleManager.h"


class EzAnimPluginModuleImpl : public IModuleInterface
{
public:
	void StartupModule();
	void ShutdownModule();
};