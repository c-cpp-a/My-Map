# My-Map

## 注意事项

This version is for Windows only. Chinese output or comments may be garbled, so feedback or transcoding can be performed (code usage code: GB2312).

此版本只适用于Windows。中文的输出或注释可能出现乱码，可以进行反馈或转码（代码使用编码：GB2312）。

## 游戏说明

The game adopts the form of displaying a two-dimensional map to the console. The player displays the character '#' and displays it. Players can use the 'WASD' button to move (those who have played the game know what I mean, or they can search for it themselves), and can create the following items in the forward direction (if they are already items, they will overwrite the original items):

- Wall, press the '2' key to create it. The wall displays as' - '. Players cannot move through walls. This means you can build a maze now!
- Portal, press the '3' key to create. The portal is displayed as' @ '. If players move through the portal, they will be teleported to a specific location (designated by themselves). Of course, ignore what item is on it (note, this is the key to egg coloring!)
- Ball, press the '4' key to create it. The ball is displayed as' o '. If a player wants to move onto a small ball, the ball will be pushed back one grid. Of course, the small ball behind it will also be pushed.

If you want to clear the items in the forward direction, you can press the '1' button, which is equivalent to creating a floor (not displayed).

Of course, you can also set modes, view help, and create archives. These parts are left for players to explore on their own.

游戏采用向控制台显示二维地图的形式。玩家显示为字符 `#`，并展示。玩家可以使用 `WASD` 键进行移动（玩过游戏的都知道我指的是什么，或者可以自行搜索），并可以在前进方向上创建以下物品（若已由物品，则会覆盖原有物品）：

- 墙壁，按 `2` 键创建。墙壁显示为 `-`。玩家并不能通过移动来通过墙壁。这意味着你可以构筑一个迷宫了！
- 传送门，按 `3` 键创建。传送门显示为 `@`。玩家如果通过移动来通过传送门的话，你会被传送到某一地点（自己指定）。当然无视上面是什么物品（注意，这是彩蛋的关键！）
- 小球，按 `4` 键创建。小球显示为 `o`。玩家如果要移动到一个小球上，小球会被推动，后退一格。当然，它后面的小球也会被推动。

如果你想清空前进方向上的物品，可以按 `1` 键，相当于创建了一个地板（不显示）。

当然，你也可以设定模式、查看帮助、创建存档。这些部分留给玩家自己探索。

## 版本

### V2.3

#### V2.3.4

Updated game instructions and added gameplay related introductions. I will update again later.

更新游戏说明，添加了玩法相关的介绍。稍后我会再次更新的。

#### V2.3.3

Slightly changed the game description to make the expression more concise.

稍微更改了游戏说明，让表达更简洁。

#### V2.3.2

The map storage mode has been changed, and the position of the ball can also be stored.

更换了地图的存储方式，小球的位置也可以存储了。

#### V2.3.1

Update the archive and add the game mode and direction.

更新存档，加入存储了：游戏模式、方向。

#### V2.3.0

An archiving system has been introduced, which will store the player's map, location and eggs in a file named `data.mymap` under the same directory of the game. Later, after entering the game and choosing to refuse to import and archive, the program will automatically overwrite this file. At present, it has not been archived: the movement of the ball (only the location where it was originally created will be archived) and the portal (only display, not transfer).

推出了存档系统，会把玩家的地图、位置、彩蛋存进游戏同一目录下名为`data.mymap`的文件，后续进入游戏选择拒绝导入存档后，程序会自动覆盖这一文件。目前还未做到存档：小球的移动（只会存档初始被创建的位置）和传送门（只会显示，无法传送）。

### V2.2

#### V2.2.4

Slightly revised RENAME.md.

略微改版RENAME.md。

#### V2.2.3

1. Expand comments.

2. Change the structure slightly.

3. New mode: All in one mode.

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

# 讨论频道

[discord链接 discord link](https://discord.gg/hK3P8YaJ) (discord.gg)
[洛谷链接 luogu link](https://www.luogu.com.cn/blog/somebody66xyyd/my-map) （luogu.com.cn）
