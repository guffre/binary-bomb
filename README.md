# binary-bomb
This is binary bomb source code, but with a twist!

I enjoy reverse-engineering, and have run across the binary bomb challenge in a few different courses. I decided to write my own take on it, with a focus on Windows RE.

Just wanted to create a binary bomb and throw some source code for it up there.
This bomb will only work on Windows, but if you get rid of the secret stage it should compile just fine for \*nix.

If you want to compile it yourself from source, make sure to strip the executable.

The compiled executable was compiled with this command: `i686-w64-mingw32-gcc.exe -s bomb.c -o bomb.exe`
