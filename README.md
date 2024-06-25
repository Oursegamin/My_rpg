# EPITECH 2024 | MUL | CSFML - my_RPG

<img src="assets/doc_readme/Epitech_banner.png" alt="Architecture">

## Contributors

- Baptiste Blambert ([GITHUB](https://github.com/baptistebd))
- Axel Lavrador ([GITHUB](https://github.com/Oursegamin))
- Florian Labadie ([GITHUB](https://github.com/florian-labadie))
- Armand Dufresne ([GITHUB](https://github.com/Beezarment))
- Faris Khsime ([GITHUB](https://github.com/fariskhsime))

## Description

Last project for our graphical course.

This "My_rpg" project is about all the things we learned about this year, as you normally already understood this project is about creating our own game using CSFML by groups of five persons.


## Usage

```bash
$> make re
[...]
./my_rpg
```

### Launch tests

```bash
$> make tests_run
[...]
```

### Debug mode

```bash
$> make fclean && make debug
[...]
$> valgrind --leak-check=full --show-leak-kinds=all -s ./my_rpg
```

## Commit Norms

| Commit Type | Description                                                                                                               |
|:------------|:--------------------------------------------------------------------------------------------------------------------------|
| feat        | adding new features                                                                                                       |
| modified    | changes on a file                                                                                                         |
| build       | Changes that affect the build system or external dependencies (npm, make, etc.)                                           |
| ci          | Changes related to integration files and scripts or configuration (Travis, Ansible, BrowserStack, etc.)                   |
| fix         | Bug fix                                                                                                                   |
| perf        | Performance improvements                                                                                                  |
| refactor    | Modification that neither adds a new feature nor improves performance                                                     |
| style       | Change that does not affect functionality or semantics (indentation, formatting, adding space, renaming a variable, etc.) |
| docs        | Writing or updating documentation                                                                                         |
| test        | Addition or modification of tests                                                                                         |
