# compiler_proj3

A little compiler which can generate java bytecode from a unexisting programming language, which is called Rust-.

A simple version of true Rust, which is a open-source language of Mozilla.

Now, it can only recognize integer-type variable. In this project, no floating-point number, no string variable, etc.

To sum up, it is just a very simple compiler, and it has not finished yet.

# Execution steps

In a linux environment and the folder where it exists and key in the following steps to get result:

$ make

$ ./gen *.rust

$ ./javaa *.jasm

$ java *

In this project, I used a java assembler called "javaa", and I had ziped it which is now a file called "javaa.zip".

You can unzip it and get the javaa executable file. Before you use javaa, you'd better make file again to ensure it execute correctly.
