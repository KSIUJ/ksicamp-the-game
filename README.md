# ksicamp-the-game

## Building the game

### Option 1: Compile by hand
```
$ g++ --std=c++11 -g -Wall -fsanitize=undefined -fsanitize=address -D_GLIBCXX_DEBUG -o ksicamp-the-game main.cpp util.cpp rooms/*.cpp events/*.cpp
```

### Option 2: Use make
```
$ make
```

## Running the game
```
$ ./ksicamp-the-game
```

## Checking code quality

### Requirements
* clang (including clang-tidy and clang-format)
* cpplint (`$ pip install --user cpplint`)

Make sure everything is installed with:
```
$ which clang-tidy clang-format cpplint
```
#### Check code quality
```
$ make lint
```
#### Auto-fix (fixes only trivial issues)
```
$ make fix
```
