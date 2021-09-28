import os
import argparse
import subprocess


parser = argparse.ArgumentParser(description="Style Engine CLI tools launcher")

parser.add_argument("cmd", help="command name", choices=["version"], metavar="command")
parser.add_argument('rest', nargs=argparse.REMAINDER, help="command arguments", metavar="args")

args = parser.parse_args()

print("\n" + "-"*80)
print(f"Executing: {args.cmd}")

subprocess.call(["python3", os.path.join(os.getcwd(), "tools", f"{args.cmd}.py")] + args.rest)