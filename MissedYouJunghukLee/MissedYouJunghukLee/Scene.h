#pragma once
#include "header.h"

void goto_xy(int x, int y);
int Select(int maxSelect, int gotoxyX, int gotoxyY);
int keyControl();
void Clear();

int MonsterChoice();
int KimChoice();

void TitleScene();
void Scene_First();
void Scene_Second();
void Scene_Third();
void Scene_Fourth();
void GameOver();

//void TitlePage(int menuStart, Player* player);
//void StartStory(Player* player);