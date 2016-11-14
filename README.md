# McGill Robotics Electrical Version Control

## File Structure Template
```
├── auv
|   ├── io
|   |   ├── motor-driver
|   |   |   ├── motor-driver_v1.dip
|   |   |   ├── motor-driver_v2.dip
|   |   |   ├── motor-driver.dch
|   |   |   └── README.md
|   |   └── depth-sensor
|   |       ├── depth-sensor.dip
|   |       ├── depth-sensor.dch
|   |       └── README.md
|   └── power
|       └── power-board
|           ├── power-board.dip
|           ├── power-board.dch
|           └── README.md
├── drone
|   └── ...
├── general
|   └── ...
├── rover
|   └── ...
├── components
|   ├── ti_drv8842_brushed-motor-driver.eli
|   ├── ti_drv8842_brushed-motor-driver.lib
|   ├── ti_iso3086_isolated-rs485-transceiver.eli
|   └── ti_iso3086_isolated-rs485-transceiver.lib
└── schematic-template.dch
```

## README Template
```
# Motor Driver

__Author:__ John Doe

__Description:__ Motor driver board with 30A current rating
```

## Style Conventions
  * Commit messages must:
    * Refer to the board that has changed
    * Begin with a capital letter
    * Start with a verb in the present tense
    * Have no period at the end
    * Be less than 80 characters
    * Be informative and meaningful
  * File/folder names must:
    * Be written in lowercase
    * Have words separated by dashes `-`
  *  Board files must:
    * Share the same name as their folder
    * Have a `_v1`, `_v2`, etc suffix to indicate the version (if there are several)
  * Schematic files must:
    * Be based on the `schematic-template.sch` file in the root directory
    * Have all the info in the title block filled out
  * Component and pattern files must follow the format: `manufacturer_part-number_part-function`
  * Board READMEs must follow the template above

## General Workflow
1. Sync repository (or `git pull`)
2. Open file, do work, save file
3. Select files using checkboxes (or `git add FILENAMES`)
4. Write message describing changes and press the commit button 
  (or `git commit -m "MESSAGE"`)
5. You may repeat steps 2.-4. several times before pushing if you want
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
* On the command line, steps 2.-4. correspond to running 
  `git reset --hard HEAD~1` until your conflicting commits
  have been removed (or run `git reset --hard SHA`, where SHA is the hash
  of the commit you want to revert to)

## Additional Notes
* __Changes to the auv, drone, rover, or components folders must go in 
  separate commits (i.e. only change one of these folders in a 
  single commit)__
* If you run in to problems, contact a division leader instead of messing
  around blindly
