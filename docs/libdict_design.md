# 单词程序库设计

单词程序库，最基本的功能是存储和检索单词。

这里，我们统一使用`std::map<std::string, std::vector<std::string> >`作为数据库接口。

`std::map<std::string, std::vector<std::string> >`中每一个`std::pair<std::string, std::vector<std::string> >`是一条记录，它的`first`是第一项，`second`中存放下面几项。

这个接口和`TextDB`吻合，所以我们可以使用`TextDB`作为单词程序库的数据库。

## 词库数据

### 单词释义数据

数据库文件名为`dict.txt`，每条记录第一项为单词，之后的项均为释义。

### 例句数据

数据库文件名为`sentences.txt`，每条记录第一项为单词，之后依次为例句1、释义1、例句2、释义2……

### 单词级别数据

数据库文件名为`level.txt`，每条记录第一项为单词，第二项为级别，0~5，5表示最常见（最重要）。

## 用户数据

用户数据包括：用户名、用户配置、查词历史以及单词学习情况。

### 用户配置

数据库文件名为`用户名_config`，存放了：

- 学习单词的方案(NewWordStrategy)
- 考试的方案(TestWordStrategy)

### 学习情况

数据库文件名为`用户名_learn`，每行一个单词，之后为各项计数器：

- 检索次数
- 学习次数
- 测试次数
- 回答正确次数
- 用户评级（暂未用到）

### 查词历史

文件名为`用户名_history`，每行一个单词，没有其他数据项。

### 用户词库与例句

同词库数据，数据库文件名分别为`用户名_dict`和`用户名_sentences`。

## 单词程序库设计

### 单词数据

`WordInfo`用于存放单词数据，包括：

- 单词
- 一个或多个释义
- 一个或多个例句

### 字典接口

字典接口`IDictionary`是单词程序库最基本的接口，它提供了如下功能：

- 检索单词的释义以及例句（返回一个`WordInfo`实例）
- 增加/删除单词的释义
- 增加/删除单词的例句

特别指出，`Dictionary`是`IDictionary`的一个派生类，它相比
`IDictionary`，增加了获取单词常见度等级的功能。

### 用户信息

用户信息`UserInfo`实现了`IDictionary`接口，它相比
`IDictionary`增加了用户相关的操作：

- 获取/增加/设定用户计数器（目前就是学习情况）
- 获取/追加用户查词历史
- 获取/设定用户配置

另外`UserInfo`存放了一个`EvaluateStrategy`的智能指针`WordEvaluator`，用于评估某个单词相对于该用户的状态（见下）。

### 单词状态评估

单词状态，例如是否常见，是否易忘，是否熟悉，是否学过，使用`EvaluateStrategy`接口来评估。

通常情况下，`EvaluateStrategy`的实现需要关联一个`UserInfo`，根据用户实际情况，智能地评估一个单词的状态。

`DefaultEvaluateStrategy`是`EvaluateStrategy`的默认实现，使用了最简单的办法——通过用户计数器来评估单词。

进一步，可以实现自己的更好的`EvaluateStrategy`来获得更佳、更精准的评估结果。

### 单词迭代器

为了实现学习新单词、单词测验等功能，都需要从单词库中抽取一定数量的单词。单词**迭代器**`WordIterator`就是用来做这个的。

`WordIterator`提供如下功能：

- 判断是否还有下一个单词
- 获取下一个单词

这里，我们内置提供了一些`WordIterator`的实现。

`RandomWordIterator`可以从给定的`IDictionary`实例中*随机*抽取满足特定“条件”（`std::function<bool (const std::string&)>`的实例，调用它返回`true`则称为满足条件）的单词。

`DiscreteWordIterator`可以从给定的`IDictionary`实例中*随机*抽取一个“条件”（同上），并*随机*抽取满足这个“条件”的单词。其中，“条件”的概率分布可配置。

`WithLimitIterator`类似于`WordIterator`的一个**装饰器**，控制了抽取单词的个数。

### 单词迭代器创建器

有的时候，一些函数需要多次创建完全同类型同参数的`WordIterator`。这些时候，为了提高这些函数的通用性，不应该每次都传入创建`WordIterator`的具体参数，而是应该传入一个单词**迭代器创建器**`WordIteratorCreator`的实例。

函数每次需要创建`WordIterator`时，只需要调用`WordIteratorCreator`的实例的`Create`成员函数即可。

此外，`RandomWordIterator`和`DiscreteWordIterator`等某些`WordIteratorz`在创建时或者创建之后需要配置（“条件”等），于是配置等操作就可以封装在特定`WordIteratorCreator`中。

同时，提供一个统一的创建`WordIterator`实例的接口是有好处的，这使得在运行时动态创建不同类型的`WordIterator`实例变得简单。

特别地，`UserWordIteratorCreator`实例能够创建用户数据相关的`WordIterator`，比如某些应用场景下创建`RandomWordIterator`或`DiscreteWordIterator`在配置“条件”的时候需要使用用户数据。

同时，`UserWordIteratorCreator`也是一个简单的创建`UserWordIteratorCreator`实例的**工厂**。利用`ByName`静态成员函数，可以通过名称以及用户数据，获取相应的`UserWordIteratorCreator`实例。重复利用这个实例，就可以重复创建完全同类型同参数的`WordIterator`。

`DefaultNewWordIteratorCreator`是一个`WordIteratorCreator`的实现，它可利用用户数据创建能够生成标准难度的新单词的`WordIterator`。

`HardNewWordIteratorCreator`是一个`WordIteratorCreator`的实现，它可利用用户数据创建能够生成难的新单词的`WordIterator`。

`DefaultTestWordIteratorCreator`是一个`WordIteratorCreator`的实现，它可利用用户数据创建能够生成标准难度的测验用单词的`WordIterator`。

`HardTestWordIteratorCreator`是一个`WordIteratorCreator`的实现，它可利用用户数据创建能够生成难的测验用单词的`WordIterator`。

### 测验问题生成器

测验问题生成器`QuestionGenerator`，利用`WordIterator`抽取的单词和从`IDictionary`中抽取的干扰答案生成新题目，并通过测验问题构建器将整套题目集输出。

### 测验问题构建器

此处的构建，是指把题目信息组成字符串或其他对象并输出到屏幕、打印机或其他类型的文件。

单词程序库只提供测验问题构建器`IQuestionBuilder`的接口定义，不提供具体实现。

为实现`IQuestionBuilder`，可以实现以下功能：

- `Begin` 在整个题目集（文档）开始的时候被调用
- `End` 在整个题目集（文档）结束的时候被调用
- `BeginTitle` 设定标题
- `EndTitle` 结束设定标题
- `BeginBody` 开始主要内容
- `EndBody` 主要内容结束
- `BeginQuestion` 问题开始
- `EndQuestion` 问题结束
- `BeginSelect` 开始选择题选项
- `Option` 一个选择题选项
- `EndSelect` 结束选择题选项
- `BeginTextInput` 开始简答题输入框
- `EndTextInput` 结束简答题输入框

其中，必须要实现的有：

- `BeginQuestion`
- `EndQuestion`
- `BeginSelect`
- `Option`
- `EndSelect`
- `BeginTextInput`
- `EndTextInput`

否则无法生成完整的题目集（文档）。

