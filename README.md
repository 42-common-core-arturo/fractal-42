# Fractal

## Table of Contents
- [Introduction](#introduction)
- [Features](#features)
- [Skills learnt](#skillslearnt)
- [Requirements](#requirements)
- [Installation](#installation)

## Introduction
Fractal is a project developed for 42 School. It involves generating and displaying mandelbrot and julia fractals. Fractals are intricate geometric shapes that can be split into parts, each of which is a reduced-scale copy of the whole. This project aims to demonstrate the beauty of fractals through interactive visualizations.

## Features
* Generate and display Mandelbrot and Julia sets
* Interactive zooming and panning

## Skills learnt
* **Algorithm Design:** Developed skills in creating and optimizing algorithms for fractal generation.
* **Graphics Programming:** Gained experience in rendering techniques and graphical libraries.
* **Mathematical Applications:** Applied complex numbers and iterative functions in code.

## Requirements
This project is intended to be compiled and run on macOS. The following are required:

*1. macOS:* Ensure you are running on a macOS system.
*2. Xcode:* Install Xcode and the Xcode Command Line Tools.
  ```sh
  xcode-select --install
  ```
*3. OpenGL:* Ensure OpenGL is available on your system.


## Installation
To install and run the Fractal project, follow these steps:

1. Clone the repository:
   ```sh
   git clone https://github.com/yourusername/fractal.git
   cd fractal
   ```
2. Compile project:
   ```sh
   make
   ```
3. Available fractals:

   * Mandelbrot set
    ```sh
   ./fractal M
   ```
   * Julia set (4 different versions), for version 1 run
    ```sh
   ./fractal J 1
   ```
