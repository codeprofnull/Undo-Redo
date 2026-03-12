# Undo-Redo Engine

A two stack linear undo/redo engine in C++ implementing the command pattern.

## Features
- Insert and delete operations on a character buffer
- Full undo and redo support
- Command pattern — every action is a self contained object

## How to run
g++ -o undo main.cpp
./undo

## Next steps
- Undo tree for non-linear history
- Regional selective undo