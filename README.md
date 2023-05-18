# binary-bomb
I have run across "Dr. Evil's Binary Bomb" a few times in beginner malware courses.

This project is inspired by that one, I wanted to include some binary bomb source code.
I decided to write my own take on it. Originally this was for windows, but I am updating it to work with linux as well.

If you want to compile it yourself from source, make sure to strip the executable!

The compiled executable was compiled with this command: `i686-w64-mingw32-gcc.exe -s bomb.c -o bomb.exe`
