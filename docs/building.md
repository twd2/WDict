# 依赖

- make
- 支持C++11的C++编译器套件
- C++运行时

# 生成

运行`make`命令即可。

## 对于Windows的特别说明

您可能需要创建一个名为`make.exe`, 到`mingw32-make.exe`的符号链接:

```
mklink make.exe mingw32-make.exe
```