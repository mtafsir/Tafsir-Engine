#pragma once

#include "core.h"

namespace T_Engine{

	class T_Engine_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

	};


	//To be defined in CLIENT
	Application* CreateApplication();
}
