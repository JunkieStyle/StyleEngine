import os
import argparse
import subprocess

from tools.globals import COMMANDS

parser = argparse.ArgumentParser(description="Style Engine CLI tools launcher")
parser.add_argument("cmd", choices=COMMANDS, help="command name")
parser.add_argument("rest", metavar="args", nargs=argparse.REMAINDER, help="command args")

args = parser.parse_args()

print("\n" + "-" * 80)
print(f"Executing: {args.cmd}")

subprocess.call(["python3", os.path.join(os.getcwd(), "tools", f"{args.cmd}.py")] + args.rest)
