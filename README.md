# ksicamp-the-game

## How to build
### Option 1: Compile by hand
```
$ g++ --std=c++11 -g -Wall -fsanitize=undefined -fsanitize=address -D_GLIBCXX_DEBUG -o ksicamp-the-game main.cpp util.cpp rooms/*.cpp events/*.cpp
$ ./ksicamp-the-game
```
### Option 2: use make
```
make
```

## Code quality checks
### Requirements:
* clang (including clang-tidy and clang-format)
* cpplint (`sudo pip install cpplint`)
### Check code quality:
```
make lint
```
### Auto-fix
```
make fix
```
