# Long Arithmetic
Implementation of long arithmetic in C++. Build via make or visual studio.

### 1 variant
```powershell
>>> make
>>> longa.exe <value1> <value2>
```

### 2 variant
```powershell
>>> make
>>> longa.exe
>>> <value1>
>>> <value2>
```
### 3 variant
Visual studio and compile via development environment.

### Input data parameters
* Numbers of any dimension with a sign (and more than 10^100)
* Example: -57898765432123456789087654321234567898765432123456789765432345

### Set of methods
```c++
> Value* abs_sum(const Value* val_1,const Value* val_2);
```
```c++
> Value* abs_sub(const Value* val_1,const Value* val_2);
```
```c++
> Value* summ(const Value* val_1,const Value* val_2);
```
```c++
> Value* subb(const Value* val_1,const Value* val_2);
```
