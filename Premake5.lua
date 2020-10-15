workspace "T_Engine"
	architecture "x64"


	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}


outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"


project "T_Engine"
	location "T_Engine"
	kind "SharedLib"
	language "C++"
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}


	includedirs
	{
		"%{prj.name}/vendor/spdlog/include"
	}


	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0.18362.0"
		defines
		{
			"TE_PLATFORM_WINDOWS",
			"TE_BUILD_DLL"
		}
		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}


	filter "configurations:Debug"
		defines "TE_DEBUG"
		symbols "On"
	filter "configurations:Release"
		defines "TE_RELEASE"
		optimize "On"
	filter "configurations:Dist"
		defines "TE_DIST"
		optimize "On"


project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")


	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}


	includedirs
	{
		"T_Engine/vendor/spdlog/include",
		"T_Engine/src"
	}


	links
	{
		"T_Engine"
	}


	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0.18362.0"
		defines
		{
			"TE_PLATFORM_WINDOWS"
		}


	filter "configurations:Debug"
		defines "TE_DEBUG"
		symbols "On"


	filter "configurations:Release"
		defines "TE_RELEASE"
		optimize "On"


	filter "configurations:Dist"
		defines "TE_DIST"
		optimize "On"