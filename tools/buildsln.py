import subprocess

import globals

if globals.is_windows():
    subprocess.call(["cmd.exe", "/c", globals.VS_BUILD_PATH, f"{globals.ENGINE_NAME}.sln"])
