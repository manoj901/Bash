ash: main.c lsh_loop.c cwdStr.c lsh_read_line.c lsh_split_line.c lsh_execute.c builtins.c ls.c pinfo.c lsh_launch.c
		gcc -o bash main.c lsh_loop.c cwdStr.c lsh_read_line.c lsh_split_line.c lsh_execute.c builtins.c ls.c pinfo.c lsh_launch.c -I .
