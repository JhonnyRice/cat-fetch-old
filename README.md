![ScreenShot of the fetch](cat-fetch.png)
![ScreenShot of the fetch, but now with colors](cat-fetch-color.png)
# cat-fetch
A cute, minimal fetch made in C [as my first C program]
Also Victor Mono is the recomened font for the cat art.

# Building
To build, you can  use `clang` (GCC doesnt work, idk why) (make sure you are in the same folder as the file!):
```
clang cat_fetch.c config.c -o cat-fetch
```
after that, you can run catfetch with `cat-fetch` or whatever your compiled binary name was.

# Config

to config it, just modify and rebuild the program. Use the `install.sh` script to make things faster.



# Colors

these are the colors you can use in the config file
```
default
black
red
green
yellow
blue
magenta
cyan
light_gray
dark_gray
light_red
light_green
light_yellow
light_blue
light_magenta
light_cyan
white
```

### NOTE: YOU SHOULD NOT USE UPPERCASE 



# TODO

- [x] add color support
- [ ] merge with watts version
- [ ] fix DWM bug
- [ ] Add more cats with a `--random` flag option
