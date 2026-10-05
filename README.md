*This project has been created as part of the 42 curriculum by vpoka.*

# CPP03 — Inheritance

A C++98 project from the 42 curriculum focused on inheritance, from a single derived class up to the diamond problem solved with virtual inheritance.

## Table of contents

- [Description](#description)
- [Instructions](#instructions)
- [Resources](#resources)
- [What this project demonstrates](#what-this-project-demonstrates)
- [Technical constraints](#technical-constraints)
- [Repository structure](#repository-structure)
- [Focus areas by exercise](#focus-areas-by-exercise)
- [Testing](#testing)
- [Status](#status)

## Description

CPP03 introduces inheritance in C++98 through a growing family of robot classes. Each exercise derives a new class from the previous work and ends with a class that inherits from two parents at once while containing exactly one shared base.

This module is split into four exercises:

* **ex00 — Aaaaand... OPEN!**
  Implement `ClapTrap`, a small robot with a name, hit points, energy points, and attack damage, plus the `attack`, `takeDamage`, and `beRepaired` member functions.
* **ex01 — Serena, my love!**
  Derive `ScavTrap` from `ClapTrap` with its own stats, its own messages, and the `guardGate` special ability.
* **ex02 — Repetitive work**
  Derive `FragTrap` from `ClapTrap` with its own stats and the `highFivesGuys` special ability.
* **ex03 — Now it's weird!**
  Create `DiamondTrap`, which inherits from both `ScavTrap` and `FragTrap`, keeps exactly one `ClapTrap` instance, and can reveal both of its names with `whoAmI`.

| Exercise | Executable | New class | Stats (HP / EP / AD) |
| --- | --- | --- | --- |
| [ex00](ex00/) — Aaaaand... OPEN! | `ex00` | `ClapTrap` | 10 / 10 / 0 |
| [ex01](ex01/) — Serena, my love! | `ex01` | `ScavTrap` | 100 / 50 / 20 |
| [ex02](ex02/) — Repetitive work | `ex02` | `FragTrap` | 100 / 100 / 30 |
| [ex03](ex03/) — Now it's weird! | `ex03` | `DiamondTrap` | 100 / 50 / 30 (mixed from both parents) |

As required by the subject turn-in rules, each exercise is self-contained and includes the class files of the previous exercises.

## Instructions

### Prerequisites

- A C++ compiler available as `c++`, supporting `-std=c++98`.
- GNU Make and standard Unix shell utilities. The Makefiles use `-Wall -Wextra -Werror -std=c++98` with `-MD -MP` header dependency tracking; `ex03` additionally uses `-Wshadow`. No external libraries are required.

The repository does not specify minimum compiler or Make versions.

### Build

Run these commands from the repository root. Each exercise has its own Makefile; there is no root Makefile.

```bash
make -C ex00
make -C ex01
make -C ex02
make -C ex03
```

Each Makefile provides `all`, `clean` (remove the `build/` directory), `fclean` (also remove the executable), `re` (rebuild), and `run` (full rebuild, then run the executable). For example:

```bash
make -C ex00 clean
make -C ex01 fclean
make -C ex02 re
```

The executables are named after their exercise and stay inside its directory: `ex00/ex00`, `ex01/ex01`, `ex02/ex02`, `ex03/ex03`.

None of the programs take arguments or read input; each `main.cpp` is a self-written test sequence that prints its results to standard output. No configuration files or environment variables are used.

### ex00 — Aaaaand... OPEN!

From the repository root:

```bash
./ex00/ex00
```

The demo exercises `ClapTrap` in several scenarios: a basic attack and repair, energy drain through repeated attacks, refusal to act when dead, refusal when out of energy, and copying or assigning a destroyed unit. Messages follow the subject format, for example:

```text
ClapTrap ct1 attacks ct2, causing 0 points of damage!
```

(ClapTrap's attack damage starts at 0, so its attacks report zero damage.)

### ex01 — Serena, my love!

From the repository root:

```bash
./ex01/ex01
```

The same test sequence runs on `ScavTrap` (20 attack damage), followed by a `guardGate()` call. Constructing a `ScavTrap` first constructs its `ClapTrap` base and destruction happens in reverse order; the transcript shows this chaining.

### ex02 — Repetitive work

From the repository root:

```bash
./ex02/ex02
```

The demo creates one `ClapTrap`, one `ScavTrap`, and one `FragTrap`, demonstrates the special abilities (`guardGate`, `highFivesGuys`), and closes with destruction of all three in reverse construction order.

### ex03 — Now it's weird!

From the repository root:

```bash
./ex03/ex03
```

The demo uses a default-constructed `DiamondTrap` (name `noname`) and prints `whoAmI()`: both the DiamondTrap name and its `ClapTrap` base name (`noname_clap_name`). It also shows the inherited stats (100 hit points from `FragTrap`, 50 energy points from `ScavTrap`, 30 attack damage from `FragTrap`) and the inherited abilities (`attack` from `ScavTrap`, `guardGate`, `highFivesGuys`).

## Resources

- **The module subject (PDF)**, supplied alongside the module repositories in the parent directory of this checkout — exercise requirements and general rules.
- **cppreference.com** — C++ language reference entries on derived classes, virtual inheritance, constructors and destructors, and class member name lookup. Consult the C++98 behavior when reading modern documentation.
- **ISO/IEC 14882:1998 (C++98)** — the clauses on derived classes and virtual base classes.
- **GNU Make manual** — targets, automatic variables, and dependency tracking (the Makefiles use `-MD -MP`).

### AI usage

AI was used to help write and improve this README and project documentation, prepare commits, and, where output or data visualisation is more complex, tweak that output.

## What this project demonstrates

* C++98 development under strict compilation rules (`-Wall -Wextra -Werror -std=c++98`)
* Single inheritance with clear constructor/destructor chaining
* Virtual inheritance keeping exactly one base subobject in the diamond (ex03)
* Class design in the Orthodox Canonical Form (copy constructor, assignment operator, destructor)
* Name shadowing between a derived member and its base counterpart (`m_name` in `DiamondTrap` and `ClapTrap`)
* State-dependent behaviour with explicit refusal messages (no hit points, no energy)

## Technical constraints

This project is developed under the 42 C++ module rules:

* Standard: **C++98**
* Compiler flags: **`-Wall -Wextra -Werror -std=c++98`** (plus **`-Wshadow`** in ex03)
* External libraries, Boost, and C++11 or later features are forbidden; `*printf()`, `*alloc()` and `free()` are forbidden
* `using namespace` and `friend` are forbidden unless explicitly stated
* The STL (containers and algorithms) is forbidden before modules 08 and 09; this module uses none
* Classes follow the Orthodox Canonical Form; no function implementations in headers (templates excepted); headers must be self-contained and include-guarded
* Every output message ends with a newline and goes to standard output

## Repository structure

```text
cpp03/
├── README.md
├── ex00/   # ClapTrap: include/ClapTrap.hpp, src/ClapTrap.cpp, src/main.cpp, Makefile
├── ex01/   # adds ScavTrap; copies of the ex00 class files
├── ex02/   # adds FragTrap; copies of the ex01 class files
└── ex03/   # adds DiamondTrap; ScavTrap and FragTrap inherit virtually from ClapTrap
```

Each exercise keeps headers in `include/`, sources in `src/`, and builds an executable named after the exercise inside its own directory.

## Focus areas by exercise

### ex00 — Aaaaand... OPEN!

* class design in the Orthodox Canonical Form
* action costs: attacking and repairing each spend one energy point
* refusal to act with no hit points or no energy points
* clamped damage and overflow-safe repair

### ex01 — Serena, my love!

* deriving `ScavTrap` from `ClapTrap`
* construction/destruction chaining between base and derived
* a redefined `attack()` with its own messages
* the `guardGate()` special ability

### ex02 — Repetitive work

* a second derived class (`FragTrap`) with its own stats and messages
* the `highFivesGuys()` special ability
* showing the chaining of all three classes together

### ex03 — Now it's weird!

* multiple inheritance (`ScavTrap` and `FragTrap`)
* virtual inheritance so the `ClapTrap` instance exists exactly once
* a `m_name` member shadowing `ClapTrap`'s `m_name`, with the base name set to `<name>_clap_name`
* mixing parent traits: hit points and attack damage from `FragTrap`, energy points and `attack()` from `ScavTrap`
* `whoAmI()` displaying both identities

## Testing

The subject requires self-written tests; each exercise ships them as a demo sequence in `src/main.cpp`. Build and run them from the repository root:

```bash
make -C ex00
./ex00/ex00
```

The sequences cover attacks and repairs, energy consumption, refusal to act when dead or out of energy, copying and assigning destroyed units, construction/destruction chaining (ex01 onward), and the special abilities. There are no separate test scripts or fixtures beyond these `main.cpp` programs.

## Status

* **Status:** Completed
* **Final grade:** **100/100 points**
