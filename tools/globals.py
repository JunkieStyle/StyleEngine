import os
import sys
import platform

ENGINE_NAME = "style"
PROJECT_NAME = "styleeditor"

V_MAJOR = 0
V_MINOR = 0

VS_BUILD_PATH = os.environ.get(
    "VS_BUILD_PATH",
    "C:\\\\Program Files (x86)\\Microsoft Visual Studio\\2019\\Community\\MSBuild\\Current\\Bin\\MSBuild.exe",  # noqa E501
)

PLATFORM = sys.platform

for x in platform.uname():
    if "microsoft" in x.lower():
        PLATFORM = "windows"


def is_windows():
    return PLATFORM == "windows"


def is_linux():
    return PLATFORM == "linux"


def is_macos():
    return PLATFORM == "darwin"
