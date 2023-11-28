#pragma once
#include "Module.h"

class ModuleProgram : public Module
{
public:
	ModuleProgram();
	~ModuleProgram();

	unsigned int CreateProgram(const char* vertexPath, const char* fragmentPath);

private:
	unsigned int program;
};

