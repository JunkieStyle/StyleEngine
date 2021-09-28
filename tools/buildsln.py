import subprocess

import globals

CONFIG = "debug"


if globals.is_windows():
    subprocess.call(["cmd.exe", "/c", globals.VS_BUILD_PATH, f"{globals.ENGINE_NAME}.sln"])

if globals.is_linux():
    subprocess.call(["make", f"config={CONFIG}"])

if globals.is_macos():
    subprocess.call(["make", f"config={CONFIG}"])
