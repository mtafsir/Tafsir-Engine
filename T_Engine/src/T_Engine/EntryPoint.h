#pragma once

#ifdef TE_PLATFORM_WINDOWS

extern T_Engine::Application* T_Engine::CreateApplication();
int main(int argc, char** argv)
{
	printf("Test\n");
	auto app = T_Engine::CreateApplication();
	app->Run();
	delete app;

}

#endif