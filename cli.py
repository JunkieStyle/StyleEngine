import os
import argparse
import subprocess

parser = argparse.ArgumentParser(description="Style Engine CLI tools launcher")
parser.add_argument("commands", nargs="+", help="command name")
args = parser.parse_args()

print("\n" + "-" * 80)


def run_command(command, command_executable="python3"):
    command_path = os.path.join(os.getcwd(), "tools", f"{command}.py")
    if not os.path.exists(command_path):
        print(f"Invalid command: {command}")
        return

    print(f"Executing command: {command}")
    subprocess.call([command_executable, command_path])


for command in args.commands:
    run_command(command)
