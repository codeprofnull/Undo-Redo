# Undo-Redo Engine

## Branch: main
Two stack linear undo/redo engine in C++ implementing the command pattern.

## Branch: tree-undo  
Non-linear undo tree with branching history. When you undo and make a new 
edit, history is never lost — previous branches remain navigable.

## Features
- Insert and delete operations on a character buffer
- Full undo and redo support
- Branching history — multiple redo paths preserved
- User can choose which branch to redo into

## How to run
g++ -o undoredotree undoredotree.cpp
.\undoredotree.exe

## Next steps
- Regional selective undo (AZURITE inspired)
- Unique character IDs to handle position shifts