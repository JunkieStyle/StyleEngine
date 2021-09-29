import sys
import subprocess

import globals

if globals.is_windows():
    subprocess.run(["cmd.exe", "/c", "premake\\premake5", "vs2019"], check=True)

elif globals.is_linux():
    subprocess.run(["premake/premake5.linux", "gmake2"], check=True)

elif globals.is_macos():
    subprocess.run(["premake/premake5.macos", "gmake2"], check=True)
    subprocess.run(["premake/premake5.macos", "xcode4"], check=True)

else:
    print(f"Not supported for {globals.PLATFORM}, please extend CLI tool 'premake.py'")

sys.exit(0)
