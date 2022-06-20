#include "header.h"
#include  "Scene.h"

int x = 30;
int y = 8;

// 위치이동
void goto_xy(int x, int y)
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos; // 커서 위치 지정
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(h, pos);//커서 옮겨주는 함수
}

// 선택지
int Select(int maxSelect, int x, int y)
{
    int menuPos = 1;
    while (true)
    {
        int keyCode = keyControl();

        switch (keyCode)
        {
        case UP:
            if (menuPos > 1)
            {
                goto_xy(x, y);
                cout << " ";
                goto_xy(x, --y);
                cout << "> ";
                menuPos--;
            }
            break;
        case DOWN:
            if (menuPos < maxSelect)
            {
                goto_xy(x, y);
                cout << " ";
                goto_xy(x, ++y);
                cout << "> ";
                menuPos++;
            }
            break;
        case ENTER:
        {
            return menuPos;
            break;
        } //변수 선언 있을 경우 블럭 처리 해주어야 함
        default:
            goto_xy(x, y);
            cout << "> ";
            menuPos = 1;
            break;
        }
    }
}

int keyControl()
{
    int temp = _getch();

    if (temp == 224)
    {
        temp = _getch();
        if (temp == 72) {
            return UP;
        }
        else if (temp == 80) {
            return DOWN;
        }
        else if (temp == 77) {
            return RIGHT;
        }
        else if (temp == 75) {
            return LEFT;
        }
    }
    if (temp == 13) {
        return ENTER;
    }
    return -1;
}

void Clear()
{
    system("cls");
}

int MonsterChoice(int max)
{
    srand(time(NULL));
    int monsterChoice = rand() % max + 1;
    return monsterChoice;
}

void TitleScene()
{
    x = 30;
    y = 8;
    //system("mode con cols=37 lines=24");
    goto_xy(30, 5);
    cout << "보고싶었어요 리정혁씨";

    /*goto_xy(x, y);
    cout << "> ";*/

    goto_xy(33, y);
    //system("color2f");
    cout << "Game Start";

    goto_xy(33, y + 1);
    cout << "Exit";
    Select(2, 30, y) == 1;
    if (Select(2,x,y) == 1)
    {
        Scene_First();
    }
    if (Select(2, x, y) == 2)
    {
        GameOver();
    }
}

void Scene_First()
{
    Clear();
    goto_xy(30, 5);
    cout << "윗동네에 사는 리정혁은 윤세리를 그리워하며 하루하루를 보내고 있다.";

    //goto_xy(x, y);
    //cout << "> ";

    goto_xy(33, y);
    cout << "1. 현실에 안주한다.";
    goto_xy(33, y + 1);
    cout << "2. 사랑을 쫒아간다. ";

    Select(2, 33, y) == 1;

    if (Select(2,30, y) == 1)
    {
        GameOver();
    }
    if (Select(2, 30, y) == 2)
    {
        Scene_Second();
    }
}

void Scene_Second()
{
    Clear();

    goto_xy(30, 5);
    cout << "자리에서 벌떡 일어나 윤세리가 살고있는 아랫동네로 무작정 달려갔다.";
    goto_xy(30, 6);
    cout << "아랫동네로 가는 길은 험난하다.총알이 빗발치는 갈대밭에서 당신은…";

    goto_xy(33, y);
    //system("color2f");
    cout << "1. 총을 쏜다.";

    goto_xy(33, y + 1);
    cout << "2. 총을 피한다. ";

    int playerHP = 100;
    int monsterHP = 100;
    int select = Select(4, x, y);

    while (playerHP == 0 || monsterHP == 0)
    {
        Clear();
		if (select == 1)
		{
			if (MonsterChoice(2) == 1)
			{
				goto_xy(30, y + 3);
				cout << "서로의 총에 맞았다";
				playerHP -= 10;
				monsterHP -= 10;
			}
			else if (MonsterChoice(2) == 2)
			{
				goto_xy(30, y + 3);
				cout << "공격에 성공했다.";
				monsterHP -= 20;
			}
		}
		if (select == 2)
		{
			if (MonsterChoice(2) == 1)
			{
				goto_xy(30, y + 3);
				cout << "총알을 피했다";
			}
			else if (MonsterChoice(2) == 2)
			{
				goto_xy(30, y + 3);
				cout << "힘이 든다";
				playerHP -= 10;
			}
		}
		cout << "리정혁의 체력 : " << playerHP << "\t상대의 체력 : " << monsterHP;
    }
    if (playerHP == 0)
    {
        GameOver();
    }
    if (monsterHP == 0)
    {
        Scene_Third();
    }

}  

void Scene_Third()
{
    Clear();

    goto_xy(30, 5);
    cout << "최종보스 김장군을 만났다.";
    goto_xy(30, 5);
    cout << "\"”나와 묵찌빠 한판 하지. 이기면 아랫동네로 쿨하게 보내주겠다.";
    goto_xy(30, 5);
    cout << "비기거나 진다면 자네는 죽는다.\"";

    goto_xy(x, y);
    cout << "> ";

    goto_xy(33, y);
    cout << "1. 묵";
    goto_xy(33, y + 1);
    cout << "2. 찌";
    goto_xy(33, y + 1);
    cout << "3. 빠";

	while (true)
	{
		Clear();
		if (Select(3, x, y)==1 && MonsterChoice(3) == 2 || Select(3, x, y) == 2 && MonsterChoice(3) == 3 || Select(3, x, y) == 3 && MonsterChoice(3) == 0)
		{
			goto_xy(30, y + 3);
			cout << "쿨바 <아랫동네로 넘어간다>";
            Scene_Fourth();
		}
	    else
		{
			goto_xy(30, y + 3);
			cout << "탕! <GAME OVER>";
		}

	}
}

void Scene_Fourth()
{
    Clear();

    goto_xy(30, 5);
    cout << "리정혁은 아랫동네에서 윤세리를 만났다.";
    goto_xy(30, 5);
    cout << "\"보고싶었어요 리정혁씨\"";
}

void GameOver()
{
    Clear();
    cout << "  ■■■■■■      ■■■■       ■■        ■■  ■■■■■■\n";
    cout << " ■■              ■■   ■■     ■■■    ■■■  ■■\n";
    cout << "■■              ■■      ■■   ■■ ■■■ ■■  ■■\n";
    cout << "■■    ■■■   ■■       ■■   ■■  ■■  ■■  ■■■■■■\n";
    cout << "■■      ■■   ■■■■■■■■  ■■        ■■  ■■\n";
    cout << " ■■     ■■   ■■       ■■   ■■        ■■  ■■\n";
    cout << "  ■■■■■■   ■■       ■■   ■■        ■■  ■■■■■■\n";
    cout << "\n";
    cout << " ■■■■■■   ■■       ■■   ■■■■■■■■   ■■■■■■\n";
    cout << "■■      ■■  ■■       ■■   ■■               ■■    ■■\n";
    cout << "■■      ■■  ■■       ■■   ■■               ■■    ■■\n";
    cout << "■■      ■■  ■■       ■■   ■■■■■■■■   ■■■■■\n";
    cout << "■■      ■■   ■■     ■■    ■■               ■■  ■■\n";
    cout << "■■      ■■    ■■■■■      ■■               ■■     ■■\n";
    cout << " ■■■■■■        ■■         ■■■■■■■■   ■■      ■■\n";
}
