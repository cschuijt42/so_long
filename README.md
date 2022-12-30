# so_long
The objective for so_long is to create a small 2D game where the player moves through a maze read from a file, grabbing collectibles and making it to the exit.

## Checklist of doom:
- [x] File handling and ingress
- [x] Map validation
  - [x] Ensure map meets subject criteria
  - [x] Ensure map is solvable
- [x] Set up sprite intake
- [x] Determine what to draw where
- [x] Pick sprites based on surroundings and categories
  - [x] Walls
  - [x] Lava
  - [x] Pillars
  - [x] Floors
  - [x] Shadows
  - [x] Additional walls
- [x] Set up rendering
- [x] Animate stuff
  - [x] Characters
  - [x] Movement
  - [x] Candles
  - [x] Lava
- [x] Set up gameplay loop
- [x] Set up win condition
- [x] Add GUI
- [x] Add patrols
- [x] Make sure there are no memory leaks :)

### The Home Stretch
- [x] Add a function on exiting the render loop which detaches all images from their spritesheet pixel buffers, to avoid double frees
- [x] Free the entire map struct on ending the game
- [x] Do not immediately exit the game when winning or losing, stick around for a death animation or a victory screen
- [x] Rework animations to be on a get_time clock instead of a frame clock
- [x] Add an indicator of where each patrol is moving next
- [x] Add a validation for patrols that are "stuck" between two walls or start next to a player
- [x] Rework the GUI to not re-render everything each time and use layered string images instead

## Asset Credits
- The dungeon sprites are [dungeonOld_](https://analogstudios.itch.io/dungeonold) and the character sprites are [dungeonSprites_](https://analogstudios.itch.io/dungeonsprites), both by [analogstudios](https://analogstudios.itch.io/).
- The GUI font is [monogram](https://datagoblin.itch.io/monogram) by [datagoblin](https://datagoblin.itch.io/). To get the font in a good bitmap layout, I used [Codehead's Bitmap Font Generator](https://github.com/CodeheadUK/CBFG).
- The paper backdrop for the GUI comes from [Crusenho's GUI Essential pack](https://crusenho.itch.io/complete-gui-essential-pack) with a small coloring update, which is distributed under a CC-BY-ND license.
