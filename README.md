# Need for Speed: Carbon reverse engineering
 
This is mostly just for me to write these down somewhere.
I hope it may prove useful to someone.

If you don't know where to start looking, check the `documentation` folder.

Primary reverse engineering target is the Wii, for two reasons:
 - Every retail build includes a Release mode elf with symbol names (no structures).
 - And, more importantly, the Japanese build includes Milestone and Debug mode dol files. These don't contain any symbol names, but they contain interesting information, namely, the Debug build has assertations and debug prints everywhere.
 
As such, structure information is fetched from the following sources:
  - ProStreet debug symbols (PlayStation 2 (Retail Russian release) and Xbox 360 (various prototype builds))
  - Most Wanted debug symbols (PlayStation 2 (Alpha 121) and GameCube (various retail builds))
  - Nitro debug symbols (Japanese Wii build, under `oldelf` folder, has structures and asserts!)
  - Undercover (Xbox 360) debug symbols, mostly useful because it's another Debug mode build.


And, finally, I leave you with an image of the Debug build running under Dolphin.
Milestone does not boot properly.

![ScreenPrintf](https://i.imgur.com/pioRIIV.png)
![Debug Menu (Nunchuk C + Z)](https://i.imgur.com/CAV2VJW.png)
![Debug World Camera](https://i.imgur.com/oifC9a6.png)

Oh, and here's [a link](https://drive.google.com/file/d/1MK16JSJ6VkKlJhtcZrITi12Y3W90R0it/view?usp=sharing).