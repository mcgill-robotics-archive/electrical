# McGill Robotics Electrical Version Control

## File Structure Template
```
├── auv
|   ├── archive
|   |   └── io
|   |       └── motor-driver-old
|   |           └── ...
|   ├── io
|   |   ├── motor-driver
|   |   |   ├── motor-driver-v1.dip
|   |   |   ├── motor-driver-v2.dip
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
|   ├── <part_number>-<company>-<short_description>.eli
|   ├── <part_number>-<company>-<short_description>.lib
|   ├── rover-board-name.eli
|   └── rover-board-name.lib
└── schematic-template.dch
```

## General Notes
* __Changes to the auv, drone, rover, or components folders must go in
  separate commits (i.e. only change one of these folders in a
  single commit)__
* If you run in to problems, contact a division leader instead of messing
  around

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
    * Have a `-v1`, `-v2`, etc suffix to indicate the reversion (if there are
      several)
    * Each board that is printed must have a revision stored
  * Schematic files must:
    * Share the same name as their folder
    * Be based on the `schematic-template.sch` file in the root directory
    * Have all the info in the title block filled out
  * Component and pattern files must:
    * Be placed in the `components` folder, do not put component or pattern
    files alongside board and schematic files
    * Be named as `<part_number>-<company>-<description>`
    * Use lowercase for all letters
    * Replace all non-alphanumerical characters in the part number, company and
    description with underscores `_`
    * Separate part number, company, and description with dash `-`
    * The library name must be the same as the part number
      * The library name can be in different casing that the file name
    * If the library is a footprint for a board use the following for file name
    and library name:
      * `<company>-<board_name>-<version>`
        * `rover`, `drone` `auv` for `<company>` if the board is made by McGill
        Robotics
        * The library name must be `<Company> <Board Name> <Version>`, note that
        uppercases and spaces are allowed here.
  * Board READMEs must follow the template above
  * **DO NOT** add DipTrace image file to the git repository (.dip0, .dip1, etc.)

## General Workflow
1. Sync repository (or `git pull`)
2. Create a new branch with sensible name and checkout to that branch.
    * Branch name examples:
        * component/part_number
        * rover/science/ph_sensor
        * auv/power/current_sensor
3. Make modificitons you want to make.
4. Select files using checkboxes (or `git add FILENAMES`)
5. Write message describing changes and press the commit button
  (or `git commit -m "MESSAGE"`)
6. You may repeat steps 2.-4. several times before pushing if you want
7. Sync repository (or `git pull` then `git push`)
8. Once your branch is in a state ready to be released, open a pull request.
9. Your pull request will be reviewed by Division leads.
  * Division Lead may request modifications, you can push more modification to
  that branch.
  * Division Lead may approve your changes and you work will be merged back to
  `master` branch.
**Note**: you may work on multiple branches, and you can switch back and forth.

## Extra Notes:
If you wish to add an equation to your README file, you can take advantage of
[this latex equation edditor](http://www.sciweavers.org/free-online-latex-equation-editor).

Example:
<img src="http://www.sciweavers.org/tex2img.php?eq=R_%7BENT%7D%20%3D%20%20%5Cfrac%7BV_%7Bstart%7D-V_%7Bstop%7D%7D%7BI_%7BHYS%7D%7D%20%3D%20%20%5Cfrac%7B21.54-21%7D%7B3.6%20%5Ctimes%2010%5E%7B-6%7D%7D%20%20&bc=White&fc=Black&im=jpg&fs=12&ff=arev&edit=0" align="center" border="0" alt="R_{ENT} =  \frac{V_{start}-V_{stop}}{I_{HYS}} =  \frac{21.54-21}{3.6 \times 10^{-6}}  " width="287" height="46" />
