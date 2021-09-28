import subprocess
import sys


if sys.platform.startswith('win32'):
    subprocess.call(["cmd.exe", "/c", "premake\\premake5", "vs2019"])
else:
    print(f"Not supported for {sys.platform}, please extend CLI tool 'premake.py'")