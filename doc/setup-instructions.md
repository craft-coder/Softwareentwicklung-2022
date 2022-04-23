# Setup Instructions

This document provides information of how to setup the programming environment.
The following possible setups are described in detail:

* **Windows**-based setup
* **Windows Subsystem for Linux**-based setup (WSL)
* **Linux** based setup

To follow the lecture only **1** setup is required.

## **Windows**-based setup

This development setup uses Windows as the operating system.
You can use this setup if you are working within the Windows operating system.
Please install the following 4 tools to setup the development environment:

* **Visual Studio Code**  
  Visual Studio Code is the *text editor* we are using to write our C++ source code.  
  Install Visual Studio Code for windows on your windows machine: https://code.visualstudio.com/  
  The application Visual Studio Code is now available on your machine. Open the application and get familiar with it (e.g. create a new text file, write something, install some extensions).

* **Visual Studio**  
  To compile C++ source code we need a compiler. On windows we use the `msvc` compiler. The `msvc` compiler comes as a part of the Visual Studio tool.  
  Install Visual Studio on your windows machine: https://visualstudio.microsoft.com/de/  
  During the installation of Visual Studio make sure to install the C++ Compiler (e.g. by enabling *Desktopentwicklung mit C++*).  

* **CMake**  
  To write the information of *how to compile* our source code, we are using the CMake tool.
  Install the *latest release* via the *Windows x64 Installer* on your windows machine: https://cmake.org/download/
  The application CMake and *CMake (cmake-gui)* is now available on your machine.

* **Git**  
  Git is the tool we are using as a version control system.  
  Install git for windows on your windows machine: https://git-scm.com/download/win  
  To check its functionality open the windows command prompt (*Eingabeaufforderung*) and type the command `git --version` into the command prompt.
  If it is installed successfully you should get the version information printed, e.g.:
  
  ```cmd
  > git --version
  git version 2.24.1.windows.2
  ```

## **Windows Subsystem for Linux**-based setup (WSL)

This development setup uses the Windows Subsystem for Linux (WSL). By installing WSL you get a Linux environment as part of your Windows operating system.
You can use this setup if you are working within the Windows operating system but want to get familiar with Linux.

Please install the following tools to setup the development environment:

* **Visual Studio Code**  
  Visual Studio Code is the *text editor* we are using to write our C++ source code.  
  Install Visual Studio Code for windows on your windows machine: https://code.visualstudio.com/  
  The application Visual Studio Code is now available on your machine. Open the application and get familiar with it (e.g. create a new text file, write something, install some extensions).

* **Windows Subsystem for Linux**
  Windows Subsystem for Linux (WSL) lets you run a Linux environment directly on Windows, without the overhead of a traditional virtual machine or dual-boot setup.  
  Install WSL on your windows machine by following the installation instructions: https://docs.microsoft.com/de-de/windows/wsl/install  
  After successful installation please start the **Ubuntu 20.04 on Windows** applications. 
  This opens a new console window and you can setup your virtual linux environment (e.g. provide a username and a password).  
  The following steps need to be executed on the command prompt of Ubuntu (inside of WSL).
  
* **g++** compiler  
  To compile C++ source code we need a compiler. On linux we use the `g++` compiler.
  Install g++ via the `apt` package manager on your linux system as described here: https://wiki.ubuntuusers.de/GCC/. It comes as a part of the `build-essential` package.
  
  ```bash
  > sudo apt-get install build-essential
  ```

  To check its successful installation open a terminal and type the command `g++ --version`.
  If it is installed successfully you should get the version information printed, e.g.:

  ```bash
  > g++ --version
  g++ (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0
  Copyright (C) 2019 Free Software Foundation, Inc.
  This is free software; see the source for copying conditions.  There is NO warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  ```

* **CMake**  
  To write the information of *how to compile* our source code, we are using the CMake tool.
  Install cmake via the `apt` package manager on your linux system:

  ```bash
  sudo apt install cmake
  ```

  To check its successful installation open a terminal and type the command `cmake --version`.
  If it is installed successfully you should get the version information printed, e.g.:

  ```bash
  > cmake --version
  cmake version 3.19.7

  CMake suite maintained and supported by Kitware (kitware.com/cmake).
  ```

* **Git**  
  Git is the tool we are using as a version control system.  
  Install git via the `apt` package manager on your linux system:

  ```bash
  sudo apt install git
  ```

  To check its successful installation open a terminal and type the command `git --version`.
  If it is installed successfully you should get the version information printed, e.g.:
  
  ```bash
  > git --version
  git version 2.25.1
  ```

## **Linux** based setup

This development setup uses linux (either a real linux machine or within WSL).
It assumes that Ubuntu (or a similar linux distribution) is used:

* **Visual Studio Code**  
  Visual Studio Code is the *text editor* we are using to write our C++ source code.  
  Install Visual Studio Code for windows on your windows machine: https://code.visualstudio.com/  
  The application Visual Studio Code is now available on your machine. Open the application and get familiar with it (e.g. create a new text file, write something, install some extensions).

* **g++** compiler  
  To compile C++ source code we need a compiler. On linux we use the `g++` compiler.
  Install g++ via the `apt` package manager on your linux system as described here: https://wiki.ubuntuusers.de/GCC/. It comes as a part of the `build-essential` package.
  
  ```bash
  > sudo apt-get install build-essential
  ``` 

  To check its successful installation open a terminal and type the command `g++ --version`.
  If it is installed successfully you should get the version information printed, e.g.:

  ```bash
  > g++ --version
  g++ (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0
  Copyright (C) 2019 Free Software Foundation, Inc.
  This is free software; see the source for copying conditions.  There is NO warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  ```

* **CMake**  
  To write the information of *how to compile* our source code, we are using the CMake tool.
  Install cmake via the `apt` package manager on your linux system:

  ```bash
  sudo apt install cmake
  ```

  To check its successful installation open a terminal and type the command `cmake --version`.
  If it is installed successfully you should get the version information printed, e.g.:

  ```bash
  > cmake --version
  cmake version 3.19.7

  CMake suite maintained and supported by Kitware (kitware.com/cmake).
  ```

* **Git**  
  Git is the tool we are using as a version control system.  
  Install git via the `apt` package manager on your linux system:

  ```bash
  sudo apt install git
  ```

  To check its successful installation open a terminal and type the command `git --version`.
  If it is installed successfully you should get the version information printed, e.g.:
  
  ```bash
  > git --version
  git version 2.25.1
  ```