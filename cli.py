import os
import argparse
import subprocess

parser = argparse.ArgumentParser(description="Style Engine CLI tools launcher")
parser.add_argument("commands", nargs="+", help="command name")
args = parser.parse_args()


def run_command(command, command_executable="python3"):
    command_path = os.path.join(os.getcwd(), "tools", f"{command}.py")
    if not os.path.exists(command_path):
        print(f"Invalid command: {command}")
        return -1

    return subprocess.run([command_executable, command_path]).returncode


for command in args.commands:
    print("\n" + "-" * 80)
    print(f"Executing command: {command}")
    if run_command(command.strip()) != 0:
        break
