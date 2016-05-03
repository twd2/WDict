# 用户界面设计

控制台用户界面相比于图形用户界面更加新颖，系统资源占用更少，没有累赘操作，通用性更好，更吸引Geek们的眼球，所以，本项目采用控制台用户界面。

为了实现控制台用户界面，我们设计了一个简单的UI库来方便主程序的开发。

首先，UI库含有`UIImpl`类，`UIImpl`为抽象的接口类，包括一个返回`bool`类型的`Show`函数。`Show`的返回值指示是否需要继续显示，当`Show`返回false，UI显示便会终止。

`Console`类是`UIImpl`类的一个具体实现。为了介绍`Console`，需要先介绍`ConsoleComponent`的设计。

对于控制台用户界面的所有元件类，包括页面类，都从`ConsoleComponent`派生而来。元件和页面实际上不用做区分。

在构造`ConsoleComponent`时，需要传递一个`Console`的引用，以便`ConsoleComponent`内部调用`Console`的成员函数。

`ConsoleComponent`提供一个`Show`接口函数，子类重写它，就可以显示不同的内容。

这里，我们提供了按钮（`ButtonConsole`）、确认（`ConfirmConsole`）、文本输入（`TextInputConsole`）以及选择（`SelectConsole`）这些`ConsoleComponent`，方便进行UI设计。我们还提供了`WithTitleConsole`**装饰器**，可以用于为`ConsoleComponent`添加标题，它也可以独立使用，直接输出标题。

`Console`类内部有一个栈来存放活动页面（activity）的状态，用户代码可以通过调用`Goto`和`Back`来进入一个页面或者从某个页面返回。

特别指出，由于`Console`使用了`std::shared_ptr`在栈中存放活动页面的指针，调用`Back`之后，此页面很可能被析构、释放。所以，调用`Back`之后，不应该还有其他操作。

同时，`Console`类提供了一些实用的函数：

- `Clear` 清空屏幕。
- `IgnoreLeftNewline` 忽略剩余的换行符，防止之后调用`std::getline`读到空行。

另外，我们也计划提供`Graphic`类，它也是`UIImpl`类的一个具体实现，提供图形化界面输出，目前正在开发当中。

最后，UI库提供一个静态类`UI`，它有两个成员函数：

- `Init` 使用`UIImpl`类的对象来初始化UI系统。
- `Start` 开始UI循环并检测是否显示成功。

为了使用这个库，只需要编写一个`ConsoleComponent`的派生类，实例化一个`Console`，`Goto`这个派生类的实例，调用`UI::Init`以及`UI::Start`：

```
// init user interface
auto controller = make_shared<Console>(); // create a controller
controller->Goto(make_shared<MainConsole>(*controller)); // goto MainConsole activity
UI::Init(controller); // init UI
UI::Start(); // ui loop, blocked
```