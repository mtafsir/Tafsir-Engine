#include <T_Engine.h>

class Sandbox : public T_Engine::Application
{

public:
	Sandbox()
	{
	}

	~Sandbox()
	{
	}


};

T_Engine::Application* T_Engine::CreateApplication()
{
	return new Sandbox();
}