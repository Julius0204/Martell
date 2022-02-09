# SuperCursey

## Team

- [Julius0204](https://github.com/Julius0204) - Developer
- [DHaytham](https://github.com/DHaytham) - Developer
- [Horst Geißler](https://github.com/fdai5433) - Product Owner
- [Hassan0895](https://github.com/Hassan0895) - Scrum Master
- [Leon114m](https://github.com/Leon114m) - Developer
- [denotavail](https://github.com/denotavail) - Developer

## Installation

### Dependencies

- `gcc` (It probably also works with other C compilers.)
- `ncurses`

SuperCursey has been tested with gcc and ncurses on Ubuntu (native and in WSL) with x86-64 Hardware.

### Compilation

```
gcc main.c movement.c customCurses.c mapgen.c -lncurses -o supercursey -fcommon
```

### Execution

```
./supercursey
```

## [License](COPYING)

This file is part of SuperCursey.

SuperCursey is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
