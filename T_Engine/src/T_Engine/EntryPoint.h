#pragma once

#ifdef TE_PLATFORM_WINDOWS

extern T_Engine::Application* T_Engine::CreateApplication();
int main(int argc, char** argv)
{
	T_Engine::Log::Init();
	TE_CORE_WARN("Initialized Log!");
	int a = 5;
	TE_INFO("Hello! Var={0}", a);

	printf("Test\n");
	auto app = T_Engine::CreateApplication();
	app->Run();
	delete app;

}

#endif