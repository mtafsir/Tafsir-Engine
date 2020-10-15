#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"

namespace T_Engine {

	class T_Engine_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

// Core log macros
#define TE_CORE_TRACE(...)    ::T_Engine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define TE_CORE_INFO(...)     ::T_Engine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define TE_CORE_WARN(...)     ::T_Engine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define TE_CORE_ERROR(...)    ::T_Engine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define TE_CORE_FATAL(...)    ::T_Engine::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define TE_TRACE(...)	      ::T_Engine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define TE_INFO(...)	      ::T_Engine::Log::GetClientLogger()->info(__VA_ARGS__)
#define TE_WARN(...)	      ::T_Engine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define TE_ERROR(...)	      ::T_Engine::Log::GetClientLogger()->error(__VA_ARGS__)
#define TE_FATAL(...)	      ::T_Engine::Log::GetClientLogger()->fatal(__VA_ARGS__) 