# Custom Virtual Machine (VM) — Documentation

This project implements a register-based virtual machine with:

- 16 general-purpose 16-bit registers  
- 256 × 16-bit RAM cells  
- A basic instruction set (`MOVE`, `LOAD`, `STORE`, `ADD`, etc.)  
- A parser that interprets semi-assembler user input  

The virtual machine executes programs directly from the command line and can later execute programs written in a custom high-level language that compiles down to VM instructions.

---

## Architecture

### Components

| Component | Description |
|------------|--------------|
| `VM` | Core of the virtual machine. Manages registers, RAM, and instruction execution. |
| `Instruction` | Defines the supported operations (e.g., `MOVE`, `ADD`, `STORE`, `LOAD`). |
| `Parser` | Tokenizes and interprets user input (semi-assembler or custom syntax). |
| `CodeGenerator` *(planned)* | Translates the Abstract Syntax Tree (AST) into VM instructions. |
| `Builtins` *(planned)* | Higher-level functions that expand to multiple low-level instructions (e.g., `print`, `set`, `add`). |

---

## Register and Memory Model

| Resource | Size | Description |
|-----------|------|--------------|
| Registers | 16 × 16-bit | General purpose registers (`R0`–`R15`) for computation and temporary storage. |
| RAM | 256 × 16-bit | Linear memory accessible through `STORE` and `LOAD` instructions. |
---


## Planned Language Layer


| Statement | Description | Example |
|------------|--------------|----------|
| `set <var> <value>` | Assign a value to a variable (creates it if not existing). | `set a 5` |
| `move <dst> <src>` | Copy the value of one variable to another. | `move b a` |
| `add <a> <b> <c>` | Compute `c = a + b`. | `add a b sum` |
| `print <var>` | Print the value of a variable. | `print total` |

### Example Syntax (high-level language)


### Data types
variables and methods = string of characters aphabetical and numbers
string = string of characters in "" double quotes
number = digit only characters -> think about floats
bool = true/false
char = '' one 8bit# Custom Virtual Machine (VM) — Documentation

This project implements a register-based virtual machine with:

- 16 general-purpose 16-bit registers  
- 256 × 16-bit RAM cells  
- A basic instruction set (`MOVE`, `LOAD`, `STORE`, `ADD`, etc.)  
- A parser that interprets semi-assembler user input  

The virtual machine executes programs directly from the command line and can later execute programs written in a custom high-level language that compiles down to VM instructions.

---

## Architecture

### Components

| Component | Description |
|------------|--------------|
| `VM` | Core of the virtual machine. Manages registers, RAM, and instruction execution. |
| `Instruction` | Defines the supported operations (e.g., `MOVE`, `ADD`, `STORE`, `LOAD`). |
| `Parser` | Tokenizes and interprets user input (semi-assembler or custom syntax). |
| `CodeGenerator` *(planned)* | Translates the Abstract Syntax Tree (AST) into VM instructions. |
| `Builtins` *(planned)* | Higher-level functions that expand to multiple low-level instructions (e.g., `print`, `set`, `add`). |

---

## Register and Memory Model

| Resource | Size | Description |
|-----------|------|--------------|
| Registers | 16 × 16-bit | General purpose registers (`R0`–`R15`) for computation and temporary storage. |
| RAM | 256 × 16-bit | Linear memory accessible through `STORE` and `LOAD` instructions. |
---


## Planned Language Layer


| Statement | Description | Example |
|------------|--------------|----------|
| `set <var> <value>` | Assign a value to a variable (creates it if not existing). | `set a 5` |
| `move <dst> <src>` | Copy the value of one variable to another. | `move b a` |
| `add <a> <b> <c>` | Compute `c = a + b`. | `add a b sum` |
| `print <var>` | Print the value of a variable. | `print total` |

### Example Syntax (high-level language)


### Data types
variables and methods = string of characters aphabetical and numbers
string = string of characters in "" double quotes
number = digit only characters -> think about floats
bool = true/false
char = '' one 8bit