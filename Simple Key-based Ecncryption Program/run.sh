#!/bin/bash
#In the official documemtation the line above always has to be the first line of any script file.

# Author: Spencer DeMera
# Email: spencer.demera@csu.fullerton.edu
# Course ID: CPSC 362-09
# Assignment Number: 1
# Due Date: 3/3/2021
# Purpose: Homework

#This is a bash shell script to be used for compiling, linking, and executing the C, C++, & x86 NASM files of this assignment.
#Execute this file by navigating the terminal window to the folder where this file resides, and then enter either of the commands below:
#  sh run.sh   OR   ./build.sh

#System requirements:
#  A Linux system with BASH shell (in a terminal window).
#  The mono compiler must be installed.  If not installed run the command "sudo apt install mono-complete" without quotes.
#  The source files and this script file must be in the same folder.
#  This file, run.sh, must have execute permission.  Go to the properties window of build.sh and put a check in the
#  permission to execute box.

# Compile main.cpp
g++ main.cpp -o Crypto.out

# ----- Run the program -----
./Crypto.out

# ----- Program finished -----