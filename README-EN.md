# My-Map

## note

This version is for Windows only. Chinese output or comments may be garbled, so feedback or transcoding can be performed (code usage code: GB2312). You can also read README.md in [English](README-EN.md) or [Chinese](README.md). At present, the panel conversion has not been completed.

## instructions

The game adopts the form of displaying a two-dimensional map to the console. The player displays the character '#' and displays it. Players can use the 'WASD' button to move (those who have played the game know what I mean, or they can search for it themselves), and can create the following items in the forward direction (if they are already items, they will overwrite the original items):

- Wall, press the '2' key to create it. The wall displays as' - '. Players cannot move through walls. This means you can build a maze now!
- Portal, press the '3' key to create. The portal is displayed as' @ '. If players move through the portal, they will be teleported to a specific location (designated by themselves). Of course, ignore what item is on it (note, this is the key to egg coloring!)
- Ball, press the '4' key to create it. The ball is displayed as' o '. If a player wants to move onto a small ball, the ball will be pushed back one grid. Of course, the small ball behind it will also be pushed.

If you want to clear the items in the forward direction, you can press the '1' button, which is equivalent to creating a floor (not displayed).

Of course, you can also set modes, view help, and create archives. These parts are left for players to explore on their own.

## version

### V2.3

#### V2.3.5

Archive updated again! Added language options. In addition, if you do not want to use the default archive location, you can also open the archive file using 'main.exe'.

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