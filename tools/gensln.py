import subprocess

import globals

if globals.is_windows():
    subprocess.call(["cmd.exe", "/c", "premake\\premake5", "vs2019"])

elif globals.is_linux():
    subprocess.call(["premake/premake.linux", "gmake2"])

elif globals.is_macos():
    subprocess.call(["premake/premake.macos", "gmake2"])
    subprocess.call(["premake/premake.macos", "xcode4"])

else:
    print(f"Not supported for {globals.PLATFORM}, please extend CLI tool 'premake.py'")
