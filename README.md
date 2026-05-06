# my_string+

A custom implementation of the standard `string.h` library in C, including advanced formatting functions (`sprintf`, `sscanf`) and additional string processing utilities.

## 📋 Overview
This project is a comprehensive re-implementation of the standard C string library. It is designed to demonstrate a deep understanding of memory management, pointer arithmetic, and variadic functions.

## 🛠 Features
The library is organized into several modules:
- **String Core**: Standard functions like `strlen`, `strcat`, `strcmp`, `memcpy`, etc.
- **Formatted I/O**: High-level implementation of `sprintf` and `sscanf`.
- **Special Functions**: Additional C#-style utilities (e.g., `trim`, `to_upper`, `to_lower`, `insert`).

## 💎 Sprintf & Sscanf Specifications
Our implementation supports a wide range of formatting options:
- **Specifiers:** `c`, `d`, `i`, `f`, `s`, `u`, `o`, `x`, `X`, `p`, `n`, `e`, `E`, `g`, `G`.
- **Flags:** `-`, `+`, `(space)`, `#`, `0`.
- **Width & Precision:** Full support, including dynamic values via `*`.
- **Length Modifiers:** `h`, `l`, `L`.

## 🚀 Build & Usage
The project uses a `Makefile` for automated building.

1. **Build the library:**
   ```bash
   make all
   ```
   Generates the static library `string.a`.

2. **Run Unit Tests:**
   ```bash
   make test
   ```
   Uses the `Check` library for rigorous testing.

3. **GCOV Report:**
   ```bash
   make gcov_report
   ```
   Generates an HTML coverage report in the `report/` directory.

## 🧪 Quality Assurance
- **Error Handling:** Robust processing via return values and `errno` integration.
- **Memory Safety:** Zero memory leaks, verified with **Valgrind** and **Leaks**.
- **Static Analysis:** Code verified using **Cppcheck** for potential bugs and style issues.
- **Style Guide:** Adheres to Google C Style.

## 📂 Project Structure
- `src/` — Implementation of core functions.
- `sprintf/` — Formatted output logic.
- `sscanf/` — Formatted input logic.
- `special_functions/` — Additional string processing.
- `tests/` — Unit tests using the Check.h framework.

## 💻 Requirements
- Compiler: `gcc`
- Libraries: `Check.h`
- Tools: `gcov`, `lcov`, `cppcheck`
