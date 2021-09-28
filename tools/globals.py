import sys
import platform

V_MAJOR = 0
V_MINOR = 0

PLATFORM = sys.platform

for x in platform.uname():
    if "microsoft" in x:
        PLATFORM = "windows"


def is_windows():
    return PLATFORM == "windows"


def is_linux():
    return PLATFORM == "linux"


def is_macos():
    return PLATFORM == "darwin"


COMMANDS = [
    "gensln",
    "version",
]
