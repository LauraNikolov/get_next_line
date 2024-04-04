# GET_NEXT_LINE 

Successive calls to your get_next_line() function should enable you to read the entire text file referenced by the file descriptor, one line at a time.
- Your function should return the line just read.
If there's nothing left to read, or if there's an error, the function should return NULL.

The bonus part: 
- get_next_line() contains just one static variable.
- get_next_line() can handle several fd.
For example, if fd's 3, 4 and 5 are readable, then it's possible to
read them in turn without ever losing the contents read on each fd, and without
without returning the wrong line.
You should be able to call get_next_line() once with fd 3, then 4, then
5, then 3 again, 4 again, etc.

/home/lnicolof/Downloads/success.png

