#
# PROGRAM:    assignment3.cc
# PROGRAMMER: Margaret Higginbotham
# LOGON ID:   Z1793581
# DATE DUE:   
#

# Complier Variables
CCFLAGS = -ansi -Wall -std=c++11

# Rule to link object code files to create executable file
assignment3.exe: assignment3.cc
	g++ $(CCFLAGS) assignment3.cc -o assignment3.exe

# Pseudo-target to remove object code and executable files
clean:
	-rm assignment3.exe
