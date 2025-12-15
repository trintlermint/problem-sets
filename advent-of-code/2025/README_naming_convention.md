# Naming Convention

The directory structure is laid out as:

```
 .
├──  golf
│   ├──  g-d01-1.py
│   ├──  g-d01-12.cpp
│   ├──  g-d01-12.kt
│   ├──  g-d01-12.py
│   └──  g-d01-12.rs
├──  input
│   ├──  1.in
│   └──  2.in
└──  normal
    ├──  n-01-12.cpp
    ├──  n-01-12.py
    ├──  n-01-12.rs
    └──  n-d01-12.kt
```

remarkably, look at `golf/*`, `normal/*`;

these signify normal programs and code golfed solutions (which are for least byte possible programs and not efficiency)

when naming files, 1.in and 2.in refers to the real puzzle input and example puzzle input respectively, which have been omitted through gitignore due to Eric's requests.

when naming a file,
`[{golf | normal}-{d{day_number}}-{number_of_solutions_solved}].{extension}`

is used, i.e. `g-d01-1.py` signifies that it is a "golfed" solution for day 1 which solves only the 1st problem,
similarly, `n-01-12.cpp` signifies that it is the normal solution (without codegolfing) for day 01 with both problems solved.

# Repository Structure:

```

     .
├──  day-1-secret-entrance
│   ├──  golf
│   │   ├──  g-d01-1.py
│   │   ├──  g-d01-12.cpp
│   │   ├──  g-d01-12.kt
│   │   ├──  g-d01-12.py
│   │   └──  g-d01-12.rs
│   ├──  input
│   │   ├──  1.in
│   │   └──  2.in
│   └──  normal
│       ├──  n-01-12.cpp
│       ├──  n-01-12.py
│       ├──  n-01-12.rs
│       └──  n-d01-12.kt
├──  day-2-gift-shop
│   ├──  golf
│   │   ├──  g-d02-12.kt
│   │   ├──  g-d02-12.py
│   │   └──  g-d02-12.rs
│   ├──  input
│   │   ├──  1.in
│   │   └──  2.in
│   └──  normal
│       ├──  n-d02-12.cpp
│       ├──  n-d02-12.kt
│       ├──  n-d02-12.py
│       └──  n-d02-12.rs
├──  day-3-lobby
│   ├──  golf
│   │   ├──  g-d03-12.cpp
│   │   ├──  g-d03-12.hs
│   │   └──  g-d03-12.py
│   ├──  input
│   │   ├──  1.in
│   │   └──  2.in
│   └──  normal
│       ├──  n-d03-12.cpp
│       ├──  n-d03-12.kt
│       └──  n-d03-12.rs
├──  day-4-printing-department
│   ├──  golf
│   │   └──  g-d04-12.py
│   ├──  input
│   └──  normal
│       ├──  n-d04-12.cpp
│       ├──  n-d04-12.kt
│       ├──  n-d04-12.py
│       └──  n-d04-12.rs
├──  day-5-cafeteria
│   ├──  golf
│   ├──  input
│   └──  normal
│       ├──  n-d05-12.kt
│       ├──  n-d05-12.py
│       └──  n-d05-12.rs
├──  day-6-trash-compactor
│   ├──  golf
│   ├──  input
│   └──  normal
│       ├──  n-d06-12.cpp
│       ├──  n-d06-12.kt
│       ├──  n-d06-12.py
│       └──  n-d06-12.rs
├──  day-7-laboratories
│   ├──  golf
│   ├──  input
│   └──  normal
│       ├──  n-d07-12.cpp
│       ├──  n-d07-12.kt
│       ├──  n-d07-12.py
│       └──  n-d07-12.rs
├──  day-8-playground
│   ├──  golf
│   ├──  input
│   └──  normal
│       ├──  n-d08-12.cpp
│       ├──  n-d08-12.kt
│       ├──  n-d08-12.py
│       └──  n-d08-12.rs
├──  day-9-movie-theater
│   ├──  1.in
│   ├──  a.out
│   ├──  movie-theater-normal.py
│   ├──  movie-theater.kt
│   ├──  movie-theater.py
│   └──  README_movie_theater.md
├──  day-10-factory
│   ├──  venv
│   │   ├──  bin
│   │   ├──  include
│   │   ├──  lib
│   │   ├──  lib64 -> lib
│   │   ├── 󰊢 .gitignore
│   │   └──  pyvenv.cfg
│   ├──  1.in
│   ├──  factory-golf.py
│   ├──  factory.py
│   └──  README_EDITORIAL_factory.md
├──  day-11-reactor
│   ├──  1.in
│   └──  reactor-golf.py
├──  day-12-christmas-tree-farm
│   ├──  input
│   ├──  1.in
│   └──  christmas-tree-farm.py
├──  advent-of-code-fin.png
├──  problem.md
└──  README_naming_convention.md
```
