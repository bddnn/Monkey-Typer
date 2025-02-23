# MonkeyTyper

MonkeyTyper is a typing speed test game developed in C++ using the SFML library for rendering and user interaction. Players can practice typing skills by typing randomly generated words while receiving real-time feedback.

## Features
- Classic typing speed test gameplay.
- Real-time feedback on typing speed and accuracy.
- Different difficulty levels and customizable word lists.
- Engaging graphical interface with SFML.
- High-score tracking system.

## Background
This project was created as part of a university assignment and serves as a learning exercise in C++ and SFML development.
This project was created as a learning exercise in C++ and SFML development.

## Getting Started

### Prerequisites
To build and run the project, ensure you have the following:
- C++17 or later.
- SFML library installed on your system.

### Installation
Clone the repository:
```sh
git clone <repository-url>
```
Navigate to the project directory:
```sh
cd MonkeyTyper
```
Install SFML (if not already installed):
```sh
sudo apt-get install libsfml-dev  # Debian/Ubuntu
brew install sfml                 # macOS
pacman -S sfml                    # Arch Linux
```

### Running the Game
There are multiple ways to run the game:

#### Compiling from Source
Compile the project using g++:
```sh
g++ -o MonkeyTyper MonkeyTyper.cpp -lsfml-graphics -lsfml-window -lsfml-system
```
Run the executable:
```sh
./MonkeyTyper
```

## Project Structure
```
MonkeyTyper/
├── src/
│   ├── MonkeyTyper.cpp
│   ├── Game.cpp
│   ├── UI.cpp
├── include/
│   ├── Game.h
│   ├── UI.h
├── assets/
│   ├── fonts/
│   ├── wordlists/
├── CMakeLists.txt
├── README.md
```
- `src/`: Contains the source code files for the game.
- `include/`: Header files for managing game components.
- `assets/`: Stores fonts and word lists for the game.
- `CMakeLists.txt`: CMake build configuration.

## Technologies Used
- **C++**: Programming language used for the game's logic.
- **SFML**: Library for rendering graphics and handling input.

## Author
Created by bddnn.

## License
This project is licensed under the MIT License.

