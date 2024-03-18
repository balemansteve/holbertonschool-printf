# holbertonschool-printf 🖨️
**Collaborative project "C - printf" for Holberton**

1) **Description.** 📋
   
In this project we create a function that emulates part of the behavior of the `printf` function in the C programming language.
The function must be able to interpret and display text in the console based on the provided arguments.

	Our `printf` function:

`int _printf(const char *format, ...);`

`format`: It is a string of characters that specifies the output format.

`...`: Represents the variable arguments to be printed according to the placeholder.

2) **Format.** 🧮
   
 Our printf can Handle the following formats:
- `%c`: to print a character.
- `%s`: to print character strings.
- `%i`: to print signed integers.
- `%d`: to print an integer.
- `%%`: to print character %.
  
Support string formats and additional arguments.
When compiled and executed correctly, the function should return the number of characters printed.


3) **References.** 📩
   
This README.md provides a description of the `_printf` function, its implementation, usage, and supported format.
The following link includes documentation for write function in Unix for more information on its use.
[Unix write function documentation](https://man7.org/linux/man-pages/man2/write.2.html).

4) **Authors.** 👥
   
This project was created by **Elián González** and **Bryan Alemán**.
