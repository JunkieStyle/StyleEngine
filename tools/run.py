import os
import subprocess

import globals

CONFIG = "Debug"
exepath = os.path.join(os.getcwd(), "bin", CONFIG, globals.PROJECT_NAME)

if globals.is_windows():
    subprocess.call([os.path.join(exepath, f"{globals.PROJECT_NAME}.exe")], cwd=exepath)
else:
    subprocess.call([os.path.join(exepath, f"{globals.PROJECT_NAME}")], cwd=exepath)
