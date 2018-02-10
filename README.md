# binary-bomb
Reverse engineering, binary bomb, windows RE, challenge, re all the things

Just wanted to create a binary bomb and throw some source code for it up there.
This bomb will only work on Windows, but if you get rid of the secret stage it should compile just fine for \*nix.

If you want to compile it yourself from source, make sure to strip the executable.

The compiled executable was compiled with this command: `i686-w64-mingw32-gcc.exe -s bomb.c -o bomb.exe`
