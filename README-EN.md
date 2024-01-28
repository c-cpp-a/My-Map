# My-Map

## Table of contents

- [Precautions](#Precautions)

- [game instructions](#game-instructions)

- [Version](#Version)

- [discussion channel](#discussion-channel)

## Precautions

This version is only available for Windows. Chinese output or comments may be garbled and can be fed back or transcoded (code usage encoding: GB2312). You can also choose the reading language: [English](README-EN.md), [中文](README.md). The plate conversion has not yet been completed.

## game instructions

### Game rules and items

The game takes the form of a two-dimensional map displayed to the console. The player is shown as the character `#`, and displayed. Players can use the `WASD` keys to move up, down, left, and right (anyone who has played the game will know what I am referring to, or you can search for it yourself), and can create the following items in the forward direction (if the item has been, the original item will be overwritten; editing will be invalid in read-only mode `MapReader`):

- Walls, created by pressing the `2` key. The wall appears as `-`. Players cannot move through walls. This means you can build a maze!
- Portal, created by pressing `3` key. The portal appears as `@`. If the player passes through the portal by moving, you will be teleported to a certain location (specified by yourself). Of course, regardless of what item is on it (note, this is the key to the Easter egg!)
- Small ball, press `4` key to create. The ball appears as `o`. If the player wants to move to a small ball, the small ball will be pushed back one space. Of course, the little ball behind it will also be pushed.

If you want to clear the items in the forward direction, you can press the `1` key, which is equivalent to creating a floor (not displayed).

### Command line parameters

Here is the default command line (or its equivalent, files considered below for these operations are `main.exe` or `MapReader.exe`):

```
main.exe
```
There are three optional parameter items `save`, `music` and `title`. The method of passing parameter items is `-<key>=<value>`, where `<key>` is the parameter item name, and `<value>` is the parameter item value. Note that the parameter value cannot contain spaces.

-  `save` : Set the archive access and save location to this parameter value.

-  `music` : No music will be played when the parameter value is `off`.

-  `title` : Set the title. Your title will be prefixed with `[My-Map]` or `[MapReader]`.

## Version

### V2.4

#### V2.4.2

1. Fixed command line issues, see command line parameters for details.

2. This and subsequent releases are available starting from this release.

#### V2.4.1

1. Fixed the issue of not being able to read through uppercase `Y` when reading into archives. Thanks [peizekai](https://github.com/peizekai).

2. Fixed the issue of read-only corruption in `MapReader`.

3. Add a command line parameter that allows you to modify the title by specifying '-title=' on the command line (provided an archive file is passed in first), such as `main.exe data.mymap -title=FirstMap`. When displaying the title, your title will be attached, in the form of `我的地图(My-Map)FirstMap'. Please note that the title cannot have spaces. (Not actually installed)

#### V2.4.0

1. A new folder 'example' has been added, where you can view examples of the 'mymap' file. We strongly recommend trying to pass the 'maze. mymap' level. This file utilizes some bugs, but I will make it a setting in future technical adjustments. You can wait for it!

2. 'init. h' has been deprecated and its functionality has been decomposed into 'Screen. h' and 'help'_ func.h`。 If there are no issues in the future, I will remove them.

### V2.3

#### V2.3.8

You can play the music now.

#### V2.3.7

1. Fixed some minor bugs.

2. You can see that I have added a new file called 'MapReader.cpp' and the corresponding 'exe' file. This can be used for just manipulating games (without editing). That is to say, you can create a decryption game and share the saved file for others to use to operate the game. You don't have to worry about others cheating by modifying levels. The titles of the two files are not the same, so you can easily distinguish between edit mode and read-only mode.

#### V2.3.6

1. Add two new achievements (extremely difficult to obtain)!

2. Added a directory for 'README.md'.

#### V2.3.5

Archive updated again! Added language options. In addition, if you do not want to use the default archive location, you can also open the archive file with using 'main.exe'.

#### V2.3.4

Updated game instructions and added gameplay related introductions. I will update again later.

#### V2.3.3

Slightly changed the game description to make the expression more concise.

#### V2.3.2

The map storage mode has been changed, and the position of the ball can also be stored.

#### V2.3.1

Update the archive and add the game mode and direction.

#### V2.3.0

An archiving system has been introduced, which will store the player's map, location and eggs in a file named `data.mymap` under the same directory of the game. Later, after entering the game and choosing to refuse to import and archive, the program will automatically overwrite this file. At present, it has not been archived: the movement of the ball (only the location where it was originally created will be archived) and the portal (only display, not transfer).

### V2.2

#### V2.2.4

Slightly revised RENAME.md.

#### V2.2.3

1. Expand comments.

2. Change the structure slightly.

3. New mode: All in one mode.

--snip--

## discussion channel

[github链接](https://github.com/c-cpp-a/My-Map/discussions) (github.com)

[洛谷链接](https://www.luogu.com.cn/blog/somebody66xyyd/my-map) (luogu.com.cn）

[discord链接](https://discord.gg/Sm7MktGB4u)
