# My-Map

## 目录

- [注意事项](#注意事项)

- [游戏说明](#游戏说明)

- [版本](#版本)

- [讨论频道](#讨论频道)

## 注意事项

此版本只适用于Windows。中文的输出或注释可能出现乱码，可以进行反馈或转码（代码使用编码：GB2312）。你也可以选择阅读语言：[English](README-EN.md)，[中文](README.md)。目前板式转换尚未完工。

## 游戏说明

游戏采用向控制台显示二维地图的形式。玩家显示为字符 `#`，并展示。玩家可以使用 `WASD` 键进行移动（玩过游戏的都知道我指的是什么，或者可以自行搜索），并可以在前进方向上创建以下物品（若已由物品，则会覆盖原有物品）：

- 墙壁，按 `2` 键创建。墙壁显示为 `-`。玩家并不能通过移动来通过墙壁。这意味着你可以构筑一个迷宫了！
- 传送门，按 `3` 键创建。传送门显示为 `@`。玩家如果通过移动来通过传送门的话，你会被传送到某一地点（自己指定）。当然无视上面是什么物品（注意，这是彩蛋的关键！）
- 小球，按 `4` 键创建。小球显示为 `o`。玩家如果要移动到一个小球上，小球会被推动，后退一格。当然，它后面的小球也会被推动。

如果你想清空前进方向上的物品，可以按 `1` 键，相当于创建了一个地板（不显示）。

当然，你也可以设定模式、查看帮助、创建存档。这些部分留给玩家自己探索。

## 版本

### V2.3

#### V2.3.6

1. 新增两个成就（极难获得）！

2. 为`README.md`新增了目录。

#### V2.3.5

存档再次更新！添加了语言选项。此外，如果你不想使用默认的存档位置的话，也可以将存档文件拖入`main.exe`中打开。

#### V2.3.4

更新游戏说明，添加了玩法相关的介绍。稍后我会再次更新的。

#### V2.3.3

稍微更改了游戏说明，让表达更简洁。

#### V2.3.2

更换了地图的存储方式，小球的位置也可以存储了。

#### V2.3.1

更新存档，加入存储了：游戏模式、方向。

#### V2.3.0

推出了存档系统，会把玩家的地图、位置、彩蛋存进游戏同一目录下名为`data.mymap`的文件，后续进入游戏选择拒绝导入存档后，程序会自动覆盖这一文件。目前还未做到存档：小球的移动（只会存档初始被创建的位置）和传送门（只会显示，无法传送）。

### V2.2

#### V2.2.4

略微改版RENAME.md。

#### V2.2.3

1、扩充注释。

2、稍微更改结构。

3、新增模式：清一色模式。

#### V2.2.2

Modification of some details.

一些细节的修改。

#### V2.2.1

1. New mode setting: Hell mode.

2. Functional comments are provided for part of the code.

1、新增模式设置：地狱模式。

2、为部分代码提供了功能注释。

#### V2.2.0

New mode settings: normal mode and developer mode.

新增模式设置：普通模式和开发者模式。

### V2.1

#### V2.1.3:

Merge pop-window-version into main branch.

合并pop-window-version为main分支。

#### V2.1.2

Optimization of some details.

一些细节的优化。

#### V2.1.1

Optimization of some details.

一些细节的优化。

#### V2.1.0

Expand the egg of the previous version and add new achievements. Add language menu option.

对上一版本的彩蛋进行扩充，新增成就。新增语言菜单选项。

### V2.0

#### V2.0.0

New eggs. Please explore or consult the code yourself.

新增彩蛋。请自行探索或查阅代码。

### V1.3

#### V1.3.1

Add small balls; Discard the archive function and stop providing it until the bug is fixed.

新增小球；弃用存档功能，在修复好bug之前不再提供。

#### V1.3.0

Fix the bug that the ball does not update, and make changes to the screen related help.

修复小球不更新的bug，并对屏幕相关帮助作出更改。

### V1.2

#### V1.2.0
Added the function of importing and exporting documents.

新增导入导出文档功能。

### V1.1

#### V1.1.0
The new portal function can easily reach remote places.

新增传送门功能，可以方便地到达遥远之地。

### V1.0

#### V1.0.0
This is a new Sandbox game. You can create or destroy rocks here, and you can walk freely. More functions are under development.

这是一个新的沙盒游戏。你在这里可以创建或销毁岩石，也可以自由行走。更多功能开发中。

## 讨论频道

[github链接](https://github.com/c-cpp-a/My-Map/discussions) (github.com)

[洛谷链接](https://www.luogu.com.cn/blog/somebody66xyyd/my-map) (luogu.com.cn）
