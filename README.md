# CMake Project Template (Basic)

### Golden quote - "It works on my machine"

My custom simple CMake Template (rather for Linux because of .sh scripts). I'm lazy, so this template is for me (and others if they want) to download.
This template is fairly simple and very basic, as I mentioned I use it when I want to fast and easly make new project.
I use `cmake` and `make` to generate and build project.
Clone this repo:
```
gh repo clone Cashtann/CMake-Template
```

**First of all, you may need to make those bash scripts executable, so in the project directory paste in these commands:**
```
chmod +x setupCMake.sh compile.sh run.sh
```


### Commands to use in project directory (bash scripts):
**CreateCMake files**

This creates CMake files in `build` directory.
 ```
 ./setupCmake.sh
```
This script is just bash `cmake -B build`.

**Build (compile) project**

Compiles project. Output files (executable and libs) should be somewhere inside `./bin` folder.
 ```
 ./compile.sh
```
This script is just bash `cd build && make && cd ..`.

**Run project**

Runs the executable file. File location may differ depending on *Build mode (Debug/Release*) -> set in the CMakeLists.txt file.
May not work if file if generated in different directory. Executable file should be somewhere in `./bin` directory.
 ```
 ./run.sh
```
This script is bash `cd bin/Linux/Debug && ./run && cd ..`.

