[33mcommit cd4a6de77dc1df8231c8f0fbbb769d15bf287aba[m[33m ([m[1;36mHEAD -> [m[1;32mgameplay-stats[m[33m, [m[1;31morigin/gameplay-stats[m[33m, [m[1;31morigin/fusion[m[33m, [m[1;32mfusion[m[33m)[m
Merge: 367715e e385963
Author: denotavail <denotavail>
Date:   Wed Feb 2 22:15:26 2022 +0100

    Merge branch 'linter' into fusion

[33mcommit e385963dc728abd4764aa2f5a6a8c789d870e8f9[m[33m ([m[1;31morigin/linter[m[33m, [m[1;32mlinter[m[33m)[m
Author: Leon Montag <leon.montag@informatik.hs-fulda.de>
Date:   Wed Feb 2 19:02:06 2022 +0100

    Tabs instead of space

[33mcommit 367715e3bdc90b9c8a6b0f81ecdd32a42cfd78c5[m
Author: denotavail <denotavail>
Date:   Wed Feb 2 03:57:04 2022 +0100

    adding build.sh

[33mcommit b6189d02b8b30060bd8c9ee0a406f98074d68c16[m
Author: denotavail <denotavail>
Date:   Wed Feb 2 03:40:53 2022 +0100

    adding installation instructions

[33mcommit b168ec1555efce66a30ea0c0363bb64a0e190a6d[m
Author: denotavail <denotavail>
Date:   Wed Feb 2 01:58:31 2022 +0100

    delete mapgen-test.c & rename movement-test.c

[33mcommit bfdf16be6da9af31dc8d62f259a2bed6a966a5c3[m
Author: denotavail <denotavail>
Date:   Wed Feb 2 01:07:16 2022 +0100

    improve acceleration values

[33mcommit e7108e54bce6b9f52c0a188344efa39fb9c337ae[m
Author: denotavail <denotavail>
Date:   Wed Feb 2 00:30:08 2022 +0100

    big fusion: integrating mapgen into movement

[33mcommit d2538e41cf1ae6e6c37b8d801f1d8f6c34e9f76b[m
Author: denotavail <denotavail>
Date:   Tue Feb 1 20:15:45 2022 +0100

    improve indentation

[33mcommit 4cdce7fa58ba71dca1cbf1f5bf4ac4d6c5f8efdd[m
Merge: 194d646 a40b89a
Author: denotavail <denotavail>
Date:   Tue Feb 1 20:05:28 2022 +0100

    Merge branch 'movement' into fusion

[33mcommit a40b89a88c627cf92fd3fcf5275f7f06ca351a9b[m[33m ([m[1;31morigin/movement[m[33m)[m
Author: denotavail <denotavail>
Date:   Tue Feb 1 19:53:16 2022 +0100

    fix: replace float with double everywhere
    
    Acceleration didn't work properly in the lower right corner of the
    screen and showed some weird behaviour. Switching from float to double
    seems to fix this bug.

[33mcommit 194d646d3e05ecb3ba050b0e970e200bc3f24a1d[m
Author: denotavail <denotavail>
Date:   Mon Jan 31 22:42:50 2022 +0100

    prevent unneeded screen updates

[33mcommit 521c76f928727a74d2b49afa852b8cfc89d28ae2[m
Author: denotavail <denotavail>
Date:   Mon Jan 31 22:18:49 2022 +0100

    replace figure symbol: '@' -> 'A'

[33mcommit 0ac80321996dcc4019552844999b15dbd8449fea[m
Author: denotavail <denotavail>
Date:   Mon Jan 31 22:10:12 2022 +0100

    use customCurses from within movement

[33mcommit c190353b47255ba8ee55d292a6861db6115cb722[m
Merge: f8b395c c9856dd
Author: denotavail <denotavail>
Date:   Mon Jan 31 21:49:23 2022 +0100

    Merge branch 'mapgen' into fusion
    
    The branch 'fusion' was created from 'movement' to fuse it together with
    'mapgen'.

[33mcommit f8b395c2b8b258738c8292c8a86b67bc894723b6[m[33m ([m[1;32mmovement[m[33m)[m
Author: denotavail <denotavail>
Date:   Mon Jan 31 07:54:59 2022 +0100

    switch from flying to jumping

[33mcommit dfe8691038c201038c78764d2e71703e7862d36b[m
Author: denotavail <denotavail>
Date:   Mon Jan 31 07:26:48 2022 +0100

    make cursor invisible

[33mcommit cdfeedf147adecd61e77599924dbeb49b57aed7a[m
Author: denotavail <denotavail>
Date:   Mon Jan 31 07:18:10 2022 +0100

    upgrade function resolveCollision()

[33mcommit 563d4ceb7c9b296c95c75e772ac005b8640c29f8[m
Author: denotavail <denotavail>
Date:   Mon Jan 31 06:29:12 2022 +0100

    implementing gravity

[33mcommit f69cbc62cae1e8ebd4dd6c5c2b83e1c2aad6962b[m
Author: denotavail <denotavail>
Date:   Mon Jan 31 05:07:07 2022 +0100

    new function onGround()

[33mcommit 6d86d4209f7d9de4c7b8980f412aae0d03e6bf59[m
Author: denotavail <denotavail>
Date:   Mon Jan 31 03:27:41 2022 +0100

    resolve diagonal collision

[33mcommit a26513f7330d118012f065745cc40f78d4d95df7[m
Author: denotavail <denotavail>
Date:   Thu Jan 27 21:34:17 2022 +0100

    resolve collision according to it's direction

[33mcommit 55c707ec5808483021d00877c0417cf704ba2f6a[m
Author: denotavail <denotavail>
Date:   Thu Jan 27 14:27:11 2022 +0100

    refactoring: input evaluation & acceleration
    
    splitting input evaluation and acceleration into two different functions

[33mcommit c9856ddee0c6b68b7825cae979db1f254782772e[m[33m ([m[1;31morigin/mapgen[m[33m, [m[1;32mmapgen[m[33m)[m
Merge: 370597b 5c5335e
Author: denotavail <denotavail>
Date:   Wed Jan 26 23:39:13 2022 +0100

    Merge branch 'gpl-mapgen' into mapgen

[33mcommit c667a48b779c7cef5952c09e2ff9aa11d943ba9f[m
Merge: 27c1d84 9ffb7bc
Author: denotavail <denotavail>
Date:   Wed Jan 26 23:33:15 2022 +0100

    Merge branch 'gpl-movement' into movement

[33mcommit 9ffb7bc241c0b2919cf8d98d762b0179d9664455[m
Author: denotavail <denotavail>
Date:   Wed Jan 26 23:20:56 2022 +0100

    adding copyright and license info to each C file

[33mcommit 155c9dd4542147acbb03122201bde000dd83f2c8[m
Merge: 27c1d84 2c11db2
Author: denotavail <denotavail>
Date:   Wed Jan 26 23:10:23 2022 +0100

    Merge branch 'gpl' into gpl-movement

[33mcommit 27c1d84c3c7b733186e3a78fcc715b84f6563146[m
Author: denotavail <denotavail>
Date:   Wed Jan 26 22:47:34 2022 +0100

    skip position calculation if not moving

[33mcommit 2acade12411aa8f1ad654829aece906bd05f441f[m
Author: denotavail <denotavail>
Date:   Wed Jan 26 21:56:36 2022 +0100

    quit program if 'q' is pressed

[33mcommit ec7e70639a9ba0ee5503b69bbf67f426902e76a3[m
Author: denotavail <denotavail>
Date:   Wed Jan 26 21:40:54 2022 +0100

    adding average timeDiff calculation

[33mcommit edf549894ace2329a9dd4bdd874d40644a914717[m
Author: denotavail <denotavail>
Date:   Wed Jan 26 06:31:44 2022 +0100

    reset velocity after collision

[33mcommit 2360621dc88092ad46cc746781e5845f9e9631d1[m
Author: denotavail <denotavail>
Date:   Wed Jan 26 06:02:16 2022 +0100

    filling isObstacle() with code

[33mcommit 5aac21bfe1c6d6cb6f0068bdcd3c40c6d7ec5f4c[m
Author: denotavail <denotavail>
Date:   Wed Jan 26 05:43:30 2022 +0100

    collisionArea(): fixing negative numbers

[33mcommit 96fe881f6ffb689523e40e9337c0ac0cbca5cbcf[m
Author: denotavail <denotavail>
Date:   Wed Jan 26 04:33:14 2022 +0100

    adding setPos() & collision()

[33mcommit 97c8d4567f50335154eecd536439fa047c27e856[m
Author: denotavail <denotavail>
Date:   Wed Jan 26 02:51:26 2022 +0100

    preparing jump restriction for collision detection

[33mcommit 874cf6438013d236e79fa602382f3363eebc0e47[m
Author: denotavail <denotavail>
Date:   Mon Jan 24 08:41:50 2022 +0100

    fixing some bugs

[33mcommit 3c41b2eb8e8ef328ac805105d07c5b41b53de7eb[m
Author: denotavail <denotavail>
Date:   Mon Jan 24 08:21:24 2022 +0100

    adding input based acceleration

[33mcommit 7358cc63c2c55a8e2a74ea2f5a368d800092105c[m
Author: denotavail <denotavail>
Date:   Sun Jan 23 07:55:44 2022 +0100

    refactoring

[33mcommit 62a1010460896e65704abf9fcced2349242ced32[m
Author: denotavail <denotavail>
Date:   Sun Jan 23 07:12:47 2022 +0100

    prevent position skipping

[33mcommit 301b67f4f39308a23964b1ccd3ba04585150e064[m
Author: denotavail <denotavail>
Date:   Sun Jan 23 04:35:59 2022 +0100

    removing printf-debugging

[33mcommit 1bae1f3102439b059a370ef92e117909868769f8[m
Author: denotavail <denotavail>
Date:   Sat Jan 22 23:41:58 2022 +0100

    movement.c: printw() -> addch()

[33mcommit 20690e5d40c5c5e0cb58a978bbc67888cb9c2fe7[m
Author: denotavail <denotavail>
Date:   Sat Jan 22 23:06:32 2022 +0100

    beginning with ncurses integration

[33mcommit 87b7da145240e01022b4ba5ac8aa17e7724a1246[m
Author: denotavail <denotavail>
Date:   Sat Jan 22 21:58:08 2022 +0100

    infinite testing loop

[33mcommit 7f948d996640dbf8a47dcc16442c410cd8bac3c2[m
Author: denotavail <denotavail>
Date:   Sat Jan 22 21:20:08 2022 +0100

    adding calcPos()

[33mcommit b9ad38065395cceb7645e1b2d88eba27d5b2355b[m
Author: denotavail <denotavail>
Date:   Sat Jan 22 19:19:48 2022 +0100

    move time calculation to new function getTimeDiff

[33mcommit 96b8c571546ef9f53e7cf900216382c14a890d2f[m
Author: denotavail <denotavail>
Date:   Fri Jan 21 21:13:26 2022 +0100

    adding new movement files

[33mcommit 5c5335e9ea0f5ecf649e72835fdd62608e02dbf0[m
Merge: ec32291 2c11db2
Author: denotavail <denotavail>
Date:   Thu Jan 20 16:41:24 2022 +0100

    Merge branch 'gpl' into gpl-mapgen

[33mcommit ec32291a1e21851e5b1dc2f58437675ef547d11e[m
Author: denotavail <denotavail>
Date:   Tue Jan 18 22:49:56 2022 +0100

    adding copyright and license info to each C file

[33mcommit 2c11db272a093d09d68bc7b98ee3375189c42a12[m[33m ([m[1;31morigin/gpl[m[33m)[m
Author: denotavail <denotavail>
Date:   Tue Jan 18 22:16:46 2022 +0100

    README.md: adding project name to license info

[33mcommit 370597b7701ba3e96488fa9a382f0480492bad40[m
Merge: ea24eab 36b677c
Author: denotavail <denotavail>
Date:   Tue Jan 18 21:56:05 2022 +0100

    Merge branch 'rename' into mapgen

[33mcommit 089369572f14174d38de23f928d1fd87f67dc99b[m
Merge: ebcc657 36b677c
Author: denotavail <denotavail>
Date:   Tue Jan 18 21:41:39 2022 +0100

    Merge branch 'rename' into gpl

[33mcommit 36b677c55c10a05164165cce649a4f0d0eb77719[m[33m ([m[1;31morigin/rename[m[33m, [m[1;32mrename[m[33m)[m
Author: denotavail <denotavail>
Date:   Tue Jan 18 21:19:50 2022 +0100

    rename project from 'Martell' to 'SuperCursey'

[33mcommit ebcc65768bff8a8e2aeeefdf359a25228182c05f[m
Author: denotavail <denotavail>
Date:   Tue Jan 18 02:07:59 2022 +0100

    README.md: adding license info (GPL-3.0-or-later)

[33mcommit 8af31996ea692a2f19410742bb77aa684566a65d[m
Author: denotavail <denotavail>
Date:   Tue Jan 18 01:48:52 2022 +0100

    adding COPYING (GPLv3)

[33mcommit ea24eaba5843ee0d553e5972c0d42a135e48d5fa[m
Author: denotavail <denotavail>
Date:   Fri Jan 7 12:50:06 2022 +0100

    group movement keys together

[33mcommit 5f610d87195df95eaaf932838b8e576a9b9fa6a1[m
Author: denotavail <denotavail>
Date:   Fri Jan 7 07:14:43 2022 +0100

    add customCurses files with initialize() function

[33mcommit 98b6672fe14a6bdb598bba8eea00ba1c69379742[m
Author: denotavail <denotavail>
Date:   Thu Jan 6 08:39:49 2022 +0100

    mapgen.h: change defMapLength from 100 to 500

[33mcommit 6549de0c8dfa24a536dbcb5f552865ee2f99edfe[m
Author: denotavail <denotavail>
Date:   Thu Jan 6 08:32:12 2022 +0100

    mapgen-test.c: scroll pad with arrow keys

[33mcommit 86d7fabc50c11deb9fe89e76a054902e3406aad7[m
Author: denotavail <denotavail>
Date:   Thu Jan 6 04:17:45 2022 +0100

    mapgen-test.c: adding cbreak() noecho() keypad()

[33mcommit 1b05818964b8a8ff0951433d8163d1f45e369eba[m
Author: denotavail <denotavail>
Date:   Thu Jan 6 03:46:05 2022 +0100

    mapgen.c: move starting point to middle of screen

[33mcommit 0306c063420acdfc1d5d064be21c1f87479c8123[m
Author: denotavail <denotavail>
Date:   Wed Jan 5 15:56:09 2022 +0100

    move prefresh() to new function refPad()

[33mcommit 14016a78589d9b892badc076a0816f09cdff4b15[m
Author: denotavail <denotavail>
Date:   Wed Jan 5 02:44:44 2022 +0100

    mapgen-test.c: show pad at the bottom of screen

[33mcommit cb9b5db76bc69f0f9c66acd2715952c931c1e28e[m
Author: denotavail <denotavail>
Date:   Tue Jan 4 02:10:50 2022 +0100

    mapgen-test.c: replace pad-size with screen-size
    
    This is needed to make the pad work even if the screen is smaller than
    the pad.

[33mcommit e159e652b4acfced16b6e5caf832f40afa644f4b[m
Author: denotavail <denotavail>
Date:   Tue Jan 4 01:47:23 2022 +0100

    mapgen-test.c: adding 'padHeightmap()'

[33mcommit 88277d194b5299f9f6975ccbcb4448def4a11916[m
Author: denotavail <denotavail>
Date:   Tue Jan 4 00:46:49 2022 +0100

    global declaration of 'padHeight' and 'map'

[33mcommit 5b1ad6b1a880ce93f688210b766b3a5aa492735a[m
Author: denotavail <denotavail>
Date:   Sun Jan 2 04:33:51 2022 +0100

    mapgen-test.c: read arguments form shell

[33mcommit 118888b363ed95da7b51a7e319a8adb554ab7030[m
Author: denotavail <denotavail>
Date:   Sat Jan 1 19:05:06 2022 +0100

    bugfix: ',' -> ';'

[33mcommit a1efc649e34db0304526c6f9b89f88ce7a002283[m
Author: denotavail <denotavail>
Date:   Sat Jan 1 19:01:42 2022 +0100

    'mapgen.h': add 'genPad()'

[33mcommit e3565d996da12225203d360c61ba99d801c2a8a5[m
Author: denotavail <denotavail>
Date:   Sat Jan 1 18:57:20 2022 +0100

    'mapgen.c': add visual heightmap into 'genPad()'

[33mcommit 00fdcc9dfb66ca9c0876dd9600a801ea33a3ad82[m
Author: denotavail <denotavail>
Date:   Sat Jan 1 08:08:56 2022 +0100

    'mapgen.c': recreate 'genPad()'

[33mcommit 8bb1d4d831b52dd9446bc9482f20e10bf943198e[m
Author: denotavail <denotavail>
Date:   Sat Jan 1 01:00:00 2022 +0100

    Happy New Year! (UTC edition)
    
    Hopefully I got the time stamp right this time ...

[33mcommit 77ce5e539f64a2d9fae120d9737142e75c5fb117[m
Author: denotavail <denotavail>
Date:   Fri Dec 31 23:56:16 2021 +0100

    New Year commit (UTC+1 edition)
    
    Happy New Year!

[33mcommit f34083157713fe49dd67c271a99b45efab02b99a[m
Author: denotavail <denotavail>
Date:   Fri Dec 31 01:56:02 2021 +0100

    'mapgen-test.c': use 'maxHeightDiff'

[33mcommit fa6973ccd67c47c8002551025d6bea394709dc11[m
Author: denotavail <denotavail>
Date:   Fri Dec 31 01:45:18 2021 +0100

    mapgen: make 'maxHeightDiff' available

[33mcommit d8169bfd9413fa21be7802e3db9b457fd08db79c[m
Author: denotavail <denotavail>
Date:   Thu Dec 30 17:24:07 2021 +0100

    bugfix: initialize 'x' with '0'

[33mcommit 132c2570ecf4e3c5279e1a322ff5ac60e9cbf6ba[m
Author: denotavail <denotavail>
Date:   Thu Dec 30 07:46:02 2021 +0100

    adding mapgen-test.c
    
    'mapgen-test.c' is only meant for testing 'mapgen.c' and 'mapgen.h'.
    Use it with the following shell command:
    'gcc mapgen-test.c mapgen.c && ./a.out'

[33mcommit 5c24265cca715030453f19e0227447c545a0a951[m
Author: denotavail <denotavail>
Date:   Thu Dec 30 06:13:01 2021 +0100

    bugfix: move defMapLength to mapgen.h

[33mcommit 114a3706cb653259f0979511813b3bd0af1e26d2[m
Author: denotavail <denotavail>
Date:   Thu Dec 30 05:49:52 2021 +0100

    fix mapgen.c by adding defMapLength

[33mcommit 3e58dd8581a8430614468692acfec6242860ba07[m
Author: denotavail <denotavail>
Date:   Thu Dec 30 04:45:44 2021 +0100

    adapt mapgen.h

[33mcommit 3fdc4c4c46d2919d3e1dd27850801e87c7021b19[m
Author: denotavail <denotavail>
Date:   Thu Dec 30 04:30:57 2021 +0100

    adding heightmap generator to mapgen.c

[33mcommit 72a1df4fb48907424c9df2abb7da7898f60450e7[m
Author: denotavail <denotavail>
Date:   Tue Dec 28 21:26:42 2021 +0100

    adding mapgen.c and mapgen.h

[33mcommit 570304b9c316e1c179892abc0c7d6f4cb73002de[m[33m ([m[1;31morigin/gitignore[m[33m, [m[1;32mgitignore[m[33m)[m
Author: denotavail <denotavail>
Date:   Tue Dec 28 16:46:00 2021 +0100

    adding .gitignore

[33mcommit 8a8e7a4eae9e1d681f649fcfcd426a267a704b3b[m[33m ([m[1;31morigin/main[m[33m, [m[1;31morigin/HEAD[m[33m, [m[1;32mmain[m[33m)[m
Merge: 05eaf71 474c0da
Author: denotavail <94467324+denotavail@users.noreply.github.com>
Date:   Sun Dec 19 23:46:00 2021 +0100

    Merge pull request #10 from Julius0204/clang-format
    
    adding .clang-format

[33mcommit 474c0da41b9fab022857c0e4bf8e8cdae51077a2[m
Author: denotavail <denotavail>
Date:   Wed Dec 15 01:17:42 2021 +0100

    adding .clang-format

[33mcommit 05eaf71c4258387bb173759cae14218424835afa[m
Author: Leon Montag <leon.montag@informatik.hs-fulda.de>
Date:   Tue Dec 14 20:29:04 2021 +0100

    Linter

[33mcommit e4279bd44d4c8b089c4bfc01be9a3ad3507a8d5c[m
Merge: 05110ce 1137470
Author: Julius0204 <julius-philipp.engel@informatik.hs-fulda.de>
Date:   Tue Dec 14 17:28:15 2021 +0100

    Merge branch 'main' of github.com:Julius0204/Martell

[33mcommit 05110ce837bb5f2a7c9a83d3fcd243bda3f8f6ef[m
Author: Julius0204 <julius-philipp.engel@informatik.hs-fulda.de>
Date:   Tue Dec 14 17:27:56 2021 +0100

    reformating update

[33mcommit 113747040246c5ec5bf41e64156de9308d460862[m
Author: Julius0204 <94465733+Julius0204@users.noreply.github.com>
Date:   Tue Dec 14 17:24:30 2021 +0100

    Delete .github/workflows directory

[33mcommit d0a427d45245b5a9261ffed9e343f0e2cc8bd4a2[m
Author: Julius0204 <94465733+Julius0204@users.noreply.github.com>
Date:   Tue Dec 14 17:18:08 2021 +0100

    Create blank.yml

[33mcommit 5bf7cb62fd1e939eb3d197ccf6df3878156bfa76[m
Author: denotavail <denotavail>
Date:   Tue Dec 7 16:59:59 2021 +0100

    reformatting of the team list

[33mcommit 1d891559874e912c5e46df60627cf3d49e122272[m
Author: Julius0204 <94465733+Julius0204@users.noreply.github.com>
Date:   Tue Dec 7 15:59:37 2021 +0100

    Team members & roles

[33mcommit 071f00ba3b33b7dc1414a16dcfed1edf3de08ab4[m
Author: Julius0204 <94465733+Julius0204@users.noreply.github.com>
Date:   Tue Dec 7 15:55:28 2021 +0100

    Team members and roles

[33mcommit 2a8869df79e33960b7321a8adacc77a37f040f91[m
Author: Julius0204 <94465733+Julius0204@users.noreply.github.com>
Date:   Tue Nov 30 15:44:29 2021 +0100

    Initial commit
