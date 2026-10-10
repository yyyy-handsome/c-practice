# C 语言练习项目

大一开始的 C 语言练习代码，一天一题，记录自己的学习轨迹。

**目标：本科毕业直接就业（不把考研当主线）**

## 怎么编译运行

在 VS Code 的终端里（PowerShell）：

    gcc 文件名.c -o 文件名 ; .\文件名.exe

一行搞定"编译 + 运行"。

> 注意：改完代码必须**重新编译**，否则跑的还是旧程序。

## 练习目录

| 文件 | 内容 | 知识点 |
| --- | --- | --- |
| hello.c | 第一个程序 | 程序骨架、printf |
| practice01.c | 打印个人信息 | printf、转义字符 \n |
| practice02.c | 三种三角形图案 | 空格排版 |
| practice03.c | 变量与类型 | int / double / char、占位符铁律 |
| practice04.c | 两数四则运算 | scanf、整数除法、强制类型转换 |
| practice05.c | 成绩等级判断 | if / else if / else |
| practice06.c | 英尺英寸转米 | 浮点除法 |
| practice07.c | 三数求最大值 | 打擂台法 |
| practice08.c | 判断闰年 | && 、|| 、复合条件括号 |
| practice09.c | for 打印 1~10 | for 循环三件套 |
| practice10.c | for 累加 1~100 | 累加器、变量作用域 |
| practice11.c | while 打印 1~10 | while 循环 |
| practice12.c | 哨兵值求和 | 输入 0 结束 |
| practice13.c | 教材第三章练习 | 三目运算符 ? : |
| practice14.c | 先读 n 再读 n 个数求和 | 计数法 |
| practice15.c | 直角三角形 | 嵌套循环 |
| practice16.c | 九九乘法表 | 嵌套循环、%2d 对齐、\t |
| practice17.c | 判断素数 | 标志变量、break |
| practice18.c | 输出 1~100 所有素数 | 嵌套循环 + 标志变量 |
| practice19.c | 最大公约数（笨办法） | 倒序 for、&& |
| practice20.c | 最大公约数（辗转相除法） | while、临时变量 |
| **guess.c** | **猜数字游戏** | 随机数、while、综合应用 |

## 小项目

### guess.c —— 猜数字游戏

电脑随机想一个 1~100 的数字，玩家来猜。程序会提示"猜大了 / 猜小了"，猜对后告诉玩家一共猜了几次。

    gcc guess.c -o guess ; .\guess.exe

涉及的知识点：随机数（rand / srand / time）、while 循环、if / else if 分支、计数器、变量作用域。

## 学习进度

- [x] 环境搭建（VS Code + GCC + Git + SSH）
- [x] printf / 变量 / 占位符
- [x] scanf / 运算符 / 类型转换
- [x] 分支（if / else if / 三目运算符）
- [x] 循环（for / while / 嵌套 / break）
- [x] 第一个小项目（猜数字游戏）
- [ ] 函数
- [ ] 数组
- [ ] 指针（基础）
- [ ] 字符串
- [ ] 结构体

## 环境

- Windows 11 + VS Code
- GCC 16.2.0（MSYS2 UCRT64）
- Git + GitHub（SSH 免密）

详细的学习规划见 `学习规划与进度.md`。