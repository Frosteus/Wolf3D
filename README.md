# Wolf3D
This project is a part of a learning process in UNIT Factory - School 42.
This project includes realization of ray-casting technic and also as bonuses realize some sort of game-engine features.

Use "make" command to compile project. Makefile contains make, clean, fclean commands.
This project using SDL2 as a window and texture manager (SDL2 library, SDL2 image library, SDL2 TTF library. Makefile contains command to work on Mac os x and Linux platforms, but for Linux platform used SDL2 libraries have to be already installed. Also its working on Windows 10 system, still you need visual studio  project with linked SDL2 libraries.

As a base task this project realize a ray-casting map drawing in pseudo 3D and movement in that labyrinth. 
As bonuses this project have realization of:
 - buttons;
 - some sort of panel;
 - menu;
 - states of program (menu, game);
 - states of game levels (start, start dialog-event, gameplay, end dialog-event, end of level);
 - sprites;
 - sprite animations support with linear timeline;
 - DOOM fully graphical font implementation, you can implement any other font;
 - DOOM weapons (Credits - DOOM Weapon Sprites v2.0 by Neccronixis - https://forum.zdoom.org/viewtopic.php?t=51919);
 - weapon inventory (num keys), shooting system and damaging tiles;
 - player stats (HP and ST, you can implement any other using modifiers), also damage model;
 - map tile textures;
 - gui;
 - additional mouse and keyboard controls;
 - customizing tiles and map;
 - dialog showing system;
 - maps loading;
 - some kind of events and triggers, in-game level progress if you find teleport tile and did not destroy it;
 - end game and win game screen;
 - dynamic map change event;
 - etc... 
 However, this project is lack of:
 - enough gameplay to be interesting :(
 - enemy sprites and system;
 - interesting level design;
 - floor and sky was removed due to my bad optimisation of ray-casting on them :(
 Hope i will return to this project and will improve it to upper lvl.
