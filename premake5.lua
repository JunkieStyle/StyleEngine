workspace "style"
    startproject "styleeditor"
    architecture "x64"

    configurations {
        "Debug",
        "Release",
    }

tdir = "bin/%{cfg.buildcfg}/%{prj.name}"
odir = "obj/%{cfg.buildcfg}/%{prj.name}"

-- External dependancies
externals = {}
externals["sdl2"] = "external/sdl2/"
externals["maclibs"] = "external/maclibs/"
externals["spdlog"] = "external/spdlog/"
externals["glad"] = "external/glad/"

-- Processing glad before anything else
include "external/glad"

project "style"
    location "style"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"

    targetdir(tdir)
    objdir(odir)

    files {
        "%{prj.name}/include/**.hpp",
        "%{prj.name}/src/**.hpp",
        "%{prj.name}/src/**.cpp"
    }

    sysincludedirs {
        "%{prj.name}/include/style",
        "%{externals.sdl2}/include",
        "%{externals.spdlog}/include",
        "%{externals.glad}/include"
    }

    flags {
        "FatalWarnings"
    }
    defines {
        "GLFW_INCLUDE_NONE"
    }

    filter { "system:windows", "configurations:*" }
        systemversion "latest"
        defines {
            "STYLE_PLATFORM_WINDOWS"
        }
        libdirs {
            "%{externals.sdl2}/lib"
        }
        links {
            "SDL2",
            "glad"
        }


    filter { "system:macosx", "configurations:*" }
        xcodebuildsettings {
            ["MACOSX_DEPLOYMENT_SETTINGS"] = "10.15",
            ["UseModernBuildSystem"] = "No"
        }
        defines {
            "STYLE_PLATFORN_MACOS"
        }
        abspath = path.getabsolute("%{externals.maclibs}")
        linkoptions {"-F " .. abspath}
        links {
            "SDL2.framework",
            "glad"
        }

    filter { "system:linux", "configurations:*" }
        defines {
            "STYLE_PLATFORM_LINUX"
        }
        links {
            "SDL2",
            "glad"
        }

    filter "configurations:Debug"
        defines {
            "STYLE_CONFIG_DEBUG"
        }
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        defines {
            "STYLE_CONFIG_RELEASE"
        }
        runtime "Release"
        symbols "off"
        optimize "on"

project "styleeditor"
    location "styleeditor"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"
    links "style"

    targetdir(tdir)
    objdir(odir)

    files {
        "%{prj.name}/src/**.hpp",
        "%{prj.name}/src/**.cpp"
    }

    sysincludedirs {
        "style/include/"
    }

    flags {
        "FatalWarnings"
    }

    filter { "system:windows", "configurations:*" }
        systemversion "latest"
        defines {
            "STYLE_PLATFORM_WINDOWS"
        }

    filter { "system:macosx", "configurations:*" }
        xcodebuildsettings {
            ["MACOSX_DEPLOYMENT_SETTINGS"] = "10.15",
            ["UseModernBuildSystem"] = "No"
        }
        defines {
            "STYLE_PLATFORN_MACOS"
        }

    filter { "system:linux", "configurations:*" }
        defines {
            "STYLE_PLATFORM_LINUX"
        }

    filter "configurations:Debug"
        defines {
            "STYLE_CONFIG_DEBUG"
        }
        runtime "Debug"
        symbols "on"


        filter "configurations:Release"
        defines {
            "STYLE_CONFIG_RELEASE"
        }
        runtime "Release"
        symbols "off"
        optimize "on"
