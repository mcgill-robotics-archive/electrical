# McGill Robotics Electrical Version Control

## File Structure Template:
```
├── auv
|   ├── board-1
|   |   ├── board-1_lay.dip
|   |   ├── board-1_lay.jpg
|   |   ├── board-1_sch.dch
|   |   ├── board-1_sch.jpg
|   |   └── board-1.txt
|   └── board-2
|       ├── board-2_lay.dip
|       ├── board-2_lay.jpg
|       ├── board-2_sch.dch
|       ├── board-2_sch.jpg
|       └── board-2.txt
├── drone
|   └── ...
├── rover
|   └── ...
└── components
        ├── part-1
        |   ├── part-1_com.eli
        |   ├── part-1_pat.lib
        |   └── part-1.pdf
        └── part-2
            ├── part-2_com.eli
            ├── part-2_pat.lib
            └── part-2.pdf
```

## Naming Conventions:
  * Commit messages must:
    * Begin with capital letters
    * Start with a verb in the present tense
    * Have no period at the end
  * File names must:
    * Be written in lowercase
    * Have words separated by dashes
  * The following suffixes must be applied:
    * Schematic-related file names must end with `_sch`
    * Layout-related file names must end with `_lay`
    * Component-related file names must end with `_com`
    * Pattern-related file names must end with `_pat`
  * Board folders, schematic files, layout files, descriptions, and reference
    images must share the same name.
  * Part folders, component files, pattern files, and datasheets must be named
    after the part they are associated with.

## Workflow:
1. Sync repository (or `git pull`)
2. Open file, do work, save file
3. For layouts and schematics:
   File > Preview... > Save > Save As: Jpeg Image (*.jpg), Area: Sheet > OK
4. Sync repository (or `git pull` then `git push`)
