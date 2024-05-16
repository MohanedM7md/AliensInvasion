# Earth vs. Aliens: War Simulation Game 
![Earth vs. Aliens]
## Table of Contents
  - [Introduction](#introduction)
  - [Features](#features) 
  - [Installation](#installation)
  - [Input File Format](#Input-File-Format)
  - [Output File Format](#Output-File-Format) 
  - [contributing](#Contributors) 
  - [Contact](#Contact)  

## Introduction
###  This C++ project is a war simulation game that pits Earth against Aliens. It utilizes various data structures to manage units for both sides and features a custom console GUI using the Windows library. The game provides options for interactive mode, allowing users to watch each simulation step by clicking any key, as well as a silent mode for generating output files only.  

## Features  
- Simulates a war between Earth and Aliens. 
- Utilizes the following data structures:   
    - Earth: FIFO soldier, LIFO tank, FIFO healer, priorityQueue gunnery.   
    - Aliens: FIFO soldiers, random array picker monsters, doublelinkedQueue Drones. 
- Custom console GUI featuring:   
    - Loading screen.   
    - Menu items.   
    - Printing screen. 
- Game Manager featuring:
    - Handles input files perfectly and generates output files showing battle results and statistics. 
    - Interactive mode enables users to watch each simulation step by clicking any key. 
    - Silent mode generates output files without displaying simulation steps.  

## Installation 
### To run this project locally:
 Clone the repository:  
```bash 
git clone https://github.com/MohanedM7md/AliensInvasion.git 
```
## Input File Format
### The input file should adhere to the specified format, providing details about Earth and Alien forces, their formations, and strategies.
```YML 
    #probablity of Genration in percentage
    Probablity: 100
    #number of Genrated Unit per Genrations
    N: 7
    #Units probablities in percentage
    ES%,ET%,EG%,%HU: 40 50 5 5
    AS%,AM%,AD%: 30 25 45
    #      Ranges of Armies     # 
    #! Warning! don't change in the order of the paramters[Power health AttackCapacity] or in thier fomrat.[min-max] !#
    #?instead you can change the numbers values

    #Eearth Ranges
    power,health,attack_capacity: 3-50 30-90 2-5
    #Alien Ranges
    power,health,attack_capacity: 1-20 40-80 1-4
    #Allied Range
    power,health,attack_capacity: 1-20 40-80 1-4
    #Extra inputs
    #Treshold percentage for calling the ally , The percentag of creating this army
    Treshold%, Allied%: 30 20
    Infection%: 20
```
## Output File Format
### The simulation generates an output file containing comprehensive battle results, statistics, and any other relevant information.
```Python
Td	ID	    Tj	DF	Dd	Db	Ta


2	2014	1	1	0	1	2


3	2007	0	1	2	3	1

3	2003	0	1	2	3	1

3	5	0	1	2	3	1

6	2017	3	1	2	3	4

6	23	2	1	3	4	3

7	2008	1	1	5	6	2
Earth Won the Battle



============================== Earth Statistcs  ===============================

ES #: 63
Percentage of destructed ES: 55.5556%
Percentage of Infected:4.761905%
ET #: 319
Percentage of destructed ET: 25.3918%
EG #: 45
Percentage of destructed EG: 93.3333%
Percentage of total destructed units: 37.0023%
percantage of Healed Units: 15.9251%


============================== Aliens Statistcs  ===============================

AS #: 108
Percentage of destructed AS: 90.7407%
AM #: 68
Percentage of destructed AM: 97.0588%
AD #: 288
Percentage of destructed AD: 58.3333%
Percentage of total destructed units: 71.5517%

```
## Contributors
- Mohaned Mohammed Fathy (Leader)
- Seif Mohammed
- Amr Ashrf
- Nada Omar
## License

This project is solely owned and maintained by Mohaned Mohamemed, Seif Mohamed, Nada Omar and Amr Ashrf. All rights reserved.

Unauthorized copying, modification, or distribution of this software, or any portion thereof, is strictly prohibited. Usage of this software is permitted only for non-commercial purposes and must include proper attribution to the author.

When using or distributing this software, please provide appropriate attribution to Mohaned Mohamemed.

For inquiries regarding licensing or usage permissions, please contact me.

## Contact
### Mohandmohamed104@gmail.com
