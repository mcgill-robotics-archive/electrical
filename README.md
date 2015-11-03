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

## General Workflow:
1. Sync repository (or `git pull`)
2. Open file, do work, save file
3. For layouts and schematics: `File` > `Preview...` > `Save` > 
  `Save As: Jpeg Image (*.jpg)`, `Area: Sheet` > `OK`
3. Select files using checkboxes (or `git add FILENAME`)
4. Write message describing changes and press the commit button 
  (or `git commit -m "MESSAGE"`).
5. You may repeat steps 2-4 several times before pushing if you like.
6. Sync repository (or `git pull` then `git push`)

## Merge Conflicts:
* If someone has updated your board while you were working on it, 
  you will not be able to push to the Git repository.
* __Do not resolve this by overwriting the other person's changes.__
* You must get the other person's changes and re-apply yours manually:
    1. Save the conflicting file elsewhere if you wish.
    2. Select the gear icon and press `Undo most recent commit`
    3. Repeat step 2 until all of your conflicting commits have been
       undone
    4. In the `Changes` view on the GitHub Desktop app, right-click
       on all the changed files and click `Discard changes`
    5. Sync the repository.
    6. Based on the new version of the file, re-apply your changes
       (__manually__)
* On the command line, steps 2-4 correspond to running 
  `git reset --hard HEAD~1` until your conflicting commits
  have been removed

## Additional Rules:
* __Changes to the auv, drone, rover, or components folders must go in 
  separate commits (i.e. only change one of these folders in a 
  single commit).__
* Commit your changes often
* Write meaningful commit messages
* If you run in to problems, contact a division leader instead of messing
  around blindly.
