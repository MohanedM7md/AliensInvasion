<h1 id="Main Heading" style="text-align: center;">AlienInvasion Game 👽🌏</h1>


<div class="Game-Story" align="left">
    <p>The year is 2047. Humanity thrives amidst technological advancements and global cooperation. But the whispers have become shouts, the blurry figures in the night sky, confirmed spaceships. An alien              invasion is no longer science fiction !!! The world needs to act quickly to be ready for the expected invasion. Using the observed information about alien armies, The Global Defense Unit decided to make            the world ready by simulating Earth’s power against aliens’ power.
    </p>
</div>

<div>

## Table of Contents
  - <a href="#Intro">Introduction</a>
  - <a href="#fea">Features</a>
  - <a href="#inst">Installation</a>
  - <a href="#Work">How Game Works </a>
  - <a href="#input">Input File Format</a>
  - <a href="#output">Output File Format</a>
  - <a href="#con">Contributers </a>
  - <a href="#li">Contributers </a>
  - <a href="#contact">Contact </a>


</div>

<div class="Project Intro">
    <h2 align="center" id="Intro">Introduction</h2>
    <p>
    This C++ project program that <u>simulates</u> the battle against alien armies and <u>calculates</u> some related <b>statistics</b> in order to help decision makers around the world. It uses different ways to keep track of soldiers and stuff for both sides. The game looks simple but it's really smart under the hood. with a GUI that is simple and It shows everything happening in the game on the screen using the interactive mode, and you can choose to watch it step by step or just let it run quietly in the background and check out what happened later using silent mode.
    </p>
</div>

<div class="Features">

<h2 align="center" id="fea">Features</h2>

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

</div>

<div class="Installation">

<h2 align="center" id="inst">Installation 🔽</h2>

### To run this project locally:

#### Clone the repository:

```
git clone https://github.com/MohanedM7md/AliensInvasion.git 
```

### Warning ⚠️

We Recommend you to run the game using **Visual Studio Community**
As This is the IDE Used for this Project

</div>

<div class="How Works">
<h2 align="center" id="Work">How The Game Works 🎲</h2>

The Game is all about probablity it takes the input ranges of both armies from a text file
(for more info about 
<a href="#input"> Input File </a> see below
) a random genrator uses the ranges from the input files to generates units of both armies the game runs for 500 time step where each time step the two armies attacks each other after the 500 time step one of the arimes win or the battle ends with draw


</div>

<div class="Input-Txt">

<h2 align="center" id="input">Input File Format 📃</h2>

The input file should adhere to the specified format, providing details about Earth and Alien forces, their formations, and strategies.



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

</div>

<div class="output-Txt">

<h2 align="center" id="output">Output File Format 📤</h2>

*This is an example to The Output File*

```Python
Td	ID	 Tj    	DF	Dd	Db	Ta


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

</div>

<div class = "Contributes">

<h2 align="center" id="con"> Contributors 👬</h2>

- Mohaned Mohammed Fathy (Leader)
- Seif Mohamed
- Amr Ashrf
- Nada Omar


</div>

<div class = "License">

<h2 align="center" id="li"> License ©️ </h2>

This project is solely owned and maintained by Mohaned Mohammed, Seif Mohamed, Nada Omar and Amr Ashrf. All rights reserved.

Unauthorized copying, modification, or distribution of this software, or any portion thereof, is strictly prohibited. Usage of this software is permitted only for non-commercial purposes and must include proper attribution to the author.

When using or distributing this software, please provide appropriate attribution to Mohaned Mohamemed.

For inquiries regarding licensing or usage permissions, please contact me.

</div>

<div class = "Contact">


<h2 align="center" id="contact"> Contact 📧 </h2>

### Mohandmohamed104@gmail.com
### eng.seifmohamed2004@gmail.com

</div>
