workspace "style"
    startproject "styleeditor"
    architecture "x64"

    configurations {
        "Debug",
        "Release",
    }

project "styleeditor"
    location "styleeditor"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"

    files {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    flags {
        "FatalWarnings"
    }
