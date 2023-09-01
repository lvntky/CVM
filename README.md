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

## Getting Started

Follow these steps to get started with CVM:

1. **Clone the Repository:**

   ```bash
   git clone https://github.com/yourusername/cvm.git
   cd cvm
   ```
2. **Compile the Source Code:**
   
   ```bash
   mkdir build
   cd ./build
   cmake ../
   make all
   ```
3. **Run a Java Program:**
   
   ```bash
   ./cvm JavaProgram.class
   ```

## Usage

CVM accepts a Java class file as a command-line argument. It loads and executes the main method of the specified class.

Example:
```bash
./cvm HelloWorld.class
```

## Contributing

We welcome contributions to CVM. If you want to add new features, fix bugs, or improve documentation, please follow these steps:

1. Fork the repository.
2. Create a new branch for your feature or bug fix.
3. Make your changes and commit them.
4. Open a pull request explaining your changes.

## License

CVM is licensed under the MIT License. See the LICENSE file for details.

## Acknowledgments

CVM was inspired by a passion for JVM internals and bytecode execution. I would like to thank the Java community for providing valuable resources and documentation on JVM internals.

## Contact

If you have questions or need assistance with CVM, feel free to contact us at leventkayadev@gmail.com .

Happy coding! 🚀
