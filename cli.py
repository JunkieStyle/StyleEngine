import os
import argparse
import subprocess

TOOLS_DIR = os.path.join(os.getcwd(), "tools")
parser = argparse.ArgumentParser(description="Style Engine CLI tools launcher")

parser.add_argument(
    "cmd", choices=[f[:-3] for f in os.listdir(TOOLS_DIR)], help="command name"
)
parser.add_argument(
    "rest", metavar="args", nargs=argparse.REMAINDER, help="command arguments"
)

args = parser.parse_args()

print("\n" + "-" * 80)
print(f"Executing: {args.cmd}")

subprocess.call(["python3", os.path.join(TOOLS_DIR, f"{args.cmd}.py")] + args.rest)
