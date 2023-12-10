@echo off

clang -I ../include ../src/main.c ../lib/raylib.lib -lwinmm -lgdi32 -lopengl32 