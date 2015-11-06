# McGill Robotics Electrical Version Control

## File Structure Template
```
├── auv
|   ├── motor-driver
|   |   ├── motor-driver_lay.dip
|   |   ├── motor-driver_lay_l1.jpg
|   |   ├── motor-driver_lay_l2.jpg
|   |   ├── motor-driver_sch.dch
|   |   ├── motor-driver_sch_s1.jpg
|   |   ├── motor-driver_sch_s2.jpg
|   |   └── README.md
|   └── power-board
|       ├── power-board_lay.dip
|       ├── power-board_lay_l1.jpg
|       ├── power-board_sch.dch
|       ├── power-board_sch_s1.jpg
|       └── README.md
├── drone
|   └── ...
├── rover
|   └── ...
└── components
        ├── iso3086
        |   ├── iso3086_com.eli
        |   ├── iso3086_pat.lib
        |   ├── iso3086.pdf
        |   └── README.md
        └── drv8842
            ├── drv8842_com.eli
            ├── drv8842_pat.lib
            ├── drv8842.pdf
            └── README.md
```

## Style Conventions
  * Commit messages must:
    * Begin with capital letters
    * Start with a verb in the present tense
    * Have no period at the end
    * Be less than 80 characters
  * File names must:
    * Be written in lowercase
    * Have words separated by dashes `-`
  * The following suffixes must be applied:
    * Schematic-related files: `_sch`
    * Layout-related files: `_lay`
    * Component-related files: `_com`
    * Pattern-related files: `_pat`
  * Board folders, schematic files, and layout files must share the same name
  * Reference images must share the same names as above, but the following must be
    appended _after_ the filetype suffixes:
    * Schematic images: sheet number `_s#`
    * Layout images: layer number `_l#`
  * Board and component READMEs must: 
    * Have the board/component's name as a title (i.e. have `# Board Name` on their first line)
    * Have the author's name in bold on the next line (`__Author: Name__`)
    * Contain a brief description of the boardboard/component's fuction
      (obviously in more detail for the board)
  * Part folders, component files, pattern files, and datasheets must be named
    after the part they are associated with

## General Workflow
1. Sync repository (or `git pull`)
2. Open file, do work, save file
3. For layouts and schematics:
   1. Open `File` > `Preview...`
   2. _Layout only:_ Select `Print in Black only`
   3. Set `Print scale` to 100%
   4. _Layout only:_ Click `Center board` (one of the magnifying glass icons)
   5. Click `Save`
   6. Set `Save As` to `Jpeg Image (*.jpg)`
   7. Set `Area` to `Sheet`
   8. Change `Resolution` to 500 dpi
   9. Click `OK`
   10. Repeat steps i. to ix. for each sheet
3. Select files using checkboxes (or `git add FILENAMES`)
4. Write message describing changes and press the commit button 
  (or `git commit -m "MESSAGE"`)
5. You may repeat steps 2-4 several times before pushing if you like
6. Sync repository (or `git pull` then `git push`)

## Merge Conflicts
* If someone has updated your board while you were working on it, 
  you will not be able to push to the Git repository
* __Do not resolve this by overwriting the other person's changes__
* You must get the other person's changes and re-apply yours manually:
    1. Save the conflicting file elsewhere if you wish
    2. Select the gear icon and press `Undo most recent commit`
    3. Repeat step 2 until all of your conflicting commits have been
       undone
    4. In the `Changes` view on the GitHub Desktop app, right-click
       on all the changed files and click `Discard changes`
    5. Sync the repository
    6. Based on the new version of the file, _manually_ 
       re-apply your changes
* On the command line, steps 2-4 correspond to running 
  `git reset --hard HEAD~1` until your conflicting commits
  have been removed (or run `git reset --hard SHA`, where SHA is the hash
  of the commit you want to revert to)

## Additional Rules
* __Changes to the auv, drone, rover, or components folders must go in 
  separate commits (i.e. only change one of these folders in a 
  single commit)__
* Commit your changes often
* Write meaningful commit messages
* If you run in to problems, contact a division leader instead of messing
  around blindly
