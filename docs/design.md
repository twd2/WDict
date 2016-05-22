# WDict设计

WDict基于`libui`、`libtextdb`以及最核心的`libdict`库设计开发，实际上是`libdict`用于开发词典软件的一个demo。具体设计在这三个库的设计中已详细说明了。

WDict主要采用了MVC（模型-视图-控制器）的架构模式。其中，模型是`libtextdb`以及`libdict`；视图是`libui`和WDict中`ConsoleComponent`的派生类；控制器是所有的WDict中`ConsoleComponent`的派生类。

另外，WDict主程序中，还提供了一个实现`libdict`库`IQuestionBuilder`接口的示例，可以生成HTML文档。

## 可能的改进之处

- i18n，提示信息多语言化
- 可选的图形用户界面

