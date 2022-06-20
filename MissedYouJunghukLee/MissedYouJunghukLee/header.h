#pragma once

#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <Time.h>
#include <conio.h>

#define IS_KEY_DOWN(vkey) (0x80000 & GetAsyncKeyState(vkey))
#define UP 1
#define RIGHT 2
#define LEFT 3
#define DOWN 4
#define ENTER 120

using namespace std;
