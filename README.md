# CVM
![GitHub commit activity](https://img.shields.io/github/commit-activity/m/lvntky/CVM)
![GitHub](https://img.shields.io/github/license/lvntky/cvm)
![GitHub issues](https://img.shields.io/github/issues/lvntky/cvm)

<p align="center">
  <img style="width: 350px; height: 350px;" src="https://github.com/lvntky/CVM/blob/master/docs/banner.jpg?raw=true" alt="Graphic design is my passion"/>
</p>

A toy Java Virtual Machine coded in C. CVM is a simple and lightweight JVM that aims to provide a basic understanding of JVM internals and bytecode execution. This project serves as an educational and fun resource for those interested in learning about JVM implementation details.

## Features

- Implementation of a minimalistic JVM in C
- Support for executing Java bytecode
- Basic class loading and method execution
- Instruction set interpretation

## Usage

To use CVM, follow these steps:

1. Clone the CVM repository:

   ```shell
   git clone https://github.com/lvntky/CVM.git
   ```
2. Build the CVM with provided Makefile 
  ```shell
  cd CVM
  cmake ./
  make
  ```
3. Compile a Java source file into bytecode using a Java compiler (e.g., javac).
   Execute the compiled bytecode using CVM:
   ```shell
   ./cvm /path/to/compiled/bytecode.class
   ```
   
## Live Demo

## Referances / Docs
* [Oracle's JVM Spec](https://docs.oracle.com/javase/specs/jvms/se14/html/)
* [Implementing a Simple JVM in Rust by Ben Evans](https://www.youtube.com/watch?v=7ECbwgkHdAE&ab_channel=Devoxx)
* [zserge - How to write a (toy) JVM](https://zserge.com/posts/jvm/)
