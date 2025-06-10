# 👨🏼‍💻 Advanced C Programming: Format Specifiers & Execution Insights 

## 📖 Introduction
This repository focuses on deepening the understanding of **advanced concepts in C programming**, especially mastering **format specifiers** for precise control over input and output operations. Whether you're fine-tuning your debugging output or building console applications, mastering format specifiers is crucial.

---

## 🎯 Objectives
- ✅ Strengthen C programming fundamentals with real-world examples  
- ✅ Dive deeper into format specifiers, precision, and memory representation  
- ✅ Explore nuances of data representation across architectures  

---

## 📌 Topics Covered
- 🔹 How C Programs Execute (from source to binary)  
- 🔹 Prototype and Internals of `printf` and `scanf`  
- 🔹 Printing and Formatting: Int, Float, Char, Hex, Octal, Unsigned  
- 🔹 Controlling Precision with `%.nf`  
- 🔹 Handling Data Sizes with Length Modifiers (`%ld`, `%lld`, etc.)

---

## 🧠 Advanced Notes on Format Specifiers

Format specifiers in C let you control **how data is displayed or read** in the `printf` and `scanf` family of functions. They're a bridge between **raw binary data and human-readable output**.

| Specifier | Meaning | Example |
|-----------|---------|---------|
| `%d` | Signed int | `-42` |
| `%u` | Unsigned int | `42` |
| `%f` | Float (6 decimal by default) | `3.141593` |
| `%.2f` | Float with 2 decimal precision | `3.14` |
| `%c` | Character | `'A'` |
| `%s` | String | `"Hello"` |
| `%x` | Hexadecimal | `2a` |
| `%o` | Octal | `052` |
| `%lf` | Double | `3.1415926535` |
| `%lld` | Long Long int | `9223372036854775807` |
| `%%` | Prints `%` | `%` |

---

## 💻 Example: Format Specifiers in Action

```c
#include <stdio.h>

int main() {
    char ch = 'A';
    int i = -42;
    unsigned int u = 42;
    float f = 3.14159f;
    double d = 2.7182818284;

    printf("Character        : %c\n", ch);
    printf("Signed Integer   : %d\n", i);
    printf("Unsigned Integer : %u\n", u);
    printf("Hexadecimal      : %x\n", u);
    printf("Octal            : %o\n", u);
    printf("Float            : %f\n", f);
    printf("Float (2 dp)     : %.2f\n", f);
    printf("Double           : %lf\n", d);
    printf("Percent Symbol   : %%\n");

    return 0;
}
```

🧑‍💻 Author
Vikash Gupta
Learning C by building, debugging, and sharing.
📫 GitHub: @vikashgupta16

