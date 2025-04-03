# Interpolation Functions

This program acts as a template for creating programs that perform interpolation.
Simply write your interpolation functions in `main.c` and follow the given steps to get access to a csv reader.
A csv reader will allow you to input a large number of nodes in your program.

## Installation

### Windows

#### Cmake Setup

If you dont have CMake already setup, follow these steps:

- First download build tools from https://visualstudio.microsoft.com/visual-cpp-build-tools/ (click on `Download Build Tools`)
- Once that's done, download CMake from https://cmake.org/download/ , Select the `Windows x64 Installer` under `Binary Distributions`
- Once the installer is downloaded run it and make sure the option for adding cmake to path is selected.
- In the installer select only the 'Desktop Development with C++' workload and wait for it to download.

Cmake Should now be installed

#### Python Installation

Skip this step if python is installed and working on your system

- Download the python installer from https://www.python.org/ftp/python/3.13.2/python-3.13.2-amd64.exe
- Run the installer once downloaded. 
- On the setup page, select "Add python.exe to PATH" and click on "Install Now"

Once installation is complete, check if Python is installed by opening command prompt and typing `python --version` (you might have to restart your system for this to work).
If you get something similar to `Python 3.13.x`, congratulations Python is succesfully installed in your system. If not, uninstall Python using the previously downloaded installer and repeat the steps above.

Once python is installed, open command prompt again and type `pip install virtualenv`

#### Get a local copy of this repository

Now we need to clone this repository. To do that you can use two methods:

##### Download ZIP (Recommended)

- Tap on `Code` near the top-right and click on `Download ZIP`.
- Copy the ZIP file to your desired directory and unpack the file.

##### Command Prompt

- Open command prompt and type `winget install Microsoft.Git` (first time users might be asked to agree to a user policy)
- Once git is installed clone this repository in your system

```
git clone https://github.com/D0T-B0X/InterpolationFunctions.git
```

The repo will probably be saved in `C:\Users\{Your username}\InterpolationFunctions`

For the next steps I highly recommend using Visual Studio Code unless you know what you are doing

#### Setup Virtual Environment and Python Interpreter

To make sure our python scripts run as they're supposed to, we need to setup a virtual environment (venv) and an interpreter. 

- Open a command prompt and type `pip install virtualenv`
- Next, open VS Code and open the directory you just copied in your system `InterpolationFunctions`
- Press `Ctrl + ~` to open up a terminal, make sure you are using cmd and not powershell or another shell. If you are change it to cmd by pressing the down array button next to the '+' symbol.

![screenshot for shell location](<Screenshot From 2025-04-03 20-42-07.png>)

- Now create a venv by typing `python -m venv .venv`, this creates a virtual environment directory named `.venv` (you can choose to name this whatever you want).
- Activate the venv by typing: `.venv\Scripts\activate` and pressing enter. You should now have a `(.venv)` written at the left of your terminal prompt.
- Now, install the required packages by typing `pip install -r requirements.txt`.

You should now have python installed and the required packaged installed for this program.

### Linux

For Linux users, the basic steps are similar:
- Install Python and CMake using your distribution's package manager
- Use forward slashes (`/`) for paths instead of backslashes
- Follow the same structure for creating virtual environments and running the code

## Dataset generation

This program comes with a utility to generate test data for interpolation. Here's how to use it:

### Generating Custom Data

If you want to create your own dataset with different parameters:

- Open the file `valuegen.py` in any text editor
- Look for these lines at the top:

Modify these values to change:

```py
START_NODE # The lowest x-value
END_NODE # The highest x-value
NODE_COUNT_APPROX # Number of nodes for interpolation

# this is optional and I dont recommend interfering with this
NODE_COUNT_TRUE - Number of nodes for comparison
```

Save the file after making your changes

### Running the Generator

#### Windows

- Make sure your virtual environment is activated (you should see (.venv) at the beginning of your terminal line)
- Navigate to the utils folder by typing: `cd utils`
- Run the generator by typing: `python valuegen.py`
- The new datasets will be created in the data folder

#### Linux

- Activate your virtual environment
- Navigate to the utils folder: `cd utils`
- Run the generator: `python valuegen.py`
- After running the script, your new dataset will be ready to use with the main program. The program will read the data from `nodes_values.csv` when it runs.

### Understanding the Data

The default dataset uses the function `f(x) = 1/(1+25x²)` to generate values, which is a standard test function for interpolation. The data is stored in CSV format with two columns:

`x`: The node values
`y`: The function values at each node

### Changing the base function

You can edit the following code to change the generated values to any function you like.

```py
for node in nodes_approx:

    # Editing this function changed the values generated
    # ex: 
    #       fn: float = node ** 2
    # will generate values for the function x²
    fn: float = 1 / (1 + (25 * (node ** 2)))

    values_approx.append(fn)
```

## Compilation and Execution

### Windows

Now that everything is setup, you can begin writing your function in `main.c`. 
Once, you've written your function, all you need to do is use cmake to build the executable and run it.
To do that follow these steps:

- Make sure you're in the home directory (\\InterpolationFunctions\\)
- run `cmake -S . -B build` and wait while cmake builds your executable.
- run `cmake --build build`
- cd into `InterpolationFunctions\build\Debug\`.
- Execute your program by typing `InterpolationFunctions.exe` and hitting enter.

If you make any changes to main.c, you need to rebuild your code. To do that:

- Make sure you're in the home directory (\\InterpolationFunctions\\)
- Repeat the steps above

### Linux

Compilation on linux is pretty much the same

- Make sure you're in the home directory (InterpolationFunctions/)
- run `cmake -S . -B build`
- run cmake --build build
- cd into `InterpolationFunctions/build/`
- Execute your program by typing `./InterpolationFunctions` and hitting enter.

If you make changes to main.c, the executable needs to be rebuilt, which is easier on linux.

- While in the build directory type `make`

The executable should be rebuilt and ready for use