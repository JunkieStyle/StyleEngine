import sys
import subprocess

import globals

CONFIG = "debug"


if globals.is_windows():
    subprocess.run(
        ["cmd.exe", "/c", globals.VS_BUILD_PATH, f"{globals.ENGINE_NAME}.sln"],
        check=True,
    )

if globals.is_linux():
    subprocess.run(["make", f"config={CONFIG}"], check=True)

if globals.is_macos():
    subprocess.run(["make", f"config={CONFIG}"], check=True)

sys.exit(0)
