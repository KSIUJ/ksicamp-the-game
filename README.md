# ksicamp-the-game

## Building the game

### Option 1 (Recommended): Use make
```
$ make
```

### Option 2: Compile by hand
```
$ mkdir bin; g++ --std=c++11 -g -Wall -fsanitize=undefined -fsanitize=address -D_GLIBCXX_DEBUG -o bin/ksicamp-the-game main.cpp util.cpp rooms/*.cpp events/*.cpp
```

## Running the game
```
$ bin/ksicamp-the-game
```

## Checking code quality

### Requirements
* clang (including `clang-tidy` and `clang-format`)
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

