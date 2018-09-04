# Shell in C

# DEVELOPER
				SAI MANOJ ATTANTI

# RUNNING THE SHELL
			* Open this directory on a terminal
			* type 'make' in the command line
			* type './bash' in the command line
			* The shell is now runing

# FEATURES
			* Display requirements of a basic shell are met
			* The Shell treats the shell directory as home (~)
			* Builtins like cd, pwd ,echo have been coded
			* It is able to handle ls [al] commands , which have been implemented
			* It is able to create background processess
			* A command 'pinfo' , which provides information about a process when its pid is passed as an argument to it
			```
			Ex: <Name@UBUNTU:~>pinfo 7777
				pid -- 7777
				Process Status -- {R/S/S+/Z} memory
				- 123123 {Virtual Memory}
				- Executable Path — /usr/bin/gcc
			```
			* Notifies user when a background process terminates