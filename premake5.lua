workspace "style"
    startproject "styleeditor"
    architecture "x64"

    configurations {
        "Debug",
        "Release",
    }

tdir = "bin/%{cfg.buildcfg}/%{prj.name}"
odir = "obj/%{cfg.buildcfg}/%{prj.name}"

project "style"
    location "style"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"

    targetdir(tdir)
    objdir(odir)

    files {
        "%{prj.name}/include/**.h",
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    sysincludedirs {
        "%{prj.name}/include/style"
    }

    flags {
        "FatalWarnings"
    }


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
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    sysincludedirs {
        "style/include/"
    }

    flags {
        "FatalWarnings"
    }
