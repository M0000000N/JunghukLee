#include "header.h"
#include  "Scene.h"

int x = 30;
int y = 8;

// ��ġ�̵�
void goto_xy(int x, int y)
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos; // Ŀ�� ��ġ ����
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(h, pos);//Ŀ�� �Ű��ִ� �Լ�
}

// ������
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
        } //���� ���� ���� ��� �� ó�� ���־�� ��
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
    cout << "����;���� ��������";

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
    cout << "�����׿� ��� �������� �������� �׸����ϸ� �Ϸ��Ϸ縦 ������ �ִ�.";

    //goto_xy(x, y);
    //cout << "> ";

    goto_xy(33, y);
    cout << "1. ���ǿ� �����Ѵ�.";
    goto_xy(33, y + 1);
    cout << "2. ����� �i�ư���. ";

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
    cout << "�ڸ����� ���� �Ͼ �������� ����ִ� �Ʒ����׷� ������ �޷�����.";
    goto_xy(30, 6);
    cout << "�Ʒ����׷� ���� ���� �賭�ϴ�.�Ѿ��� ����ġ�� ����翡�� �������";

    goto_xy(33, y);
    //system("color2f");
    cout << "1. ���� ���.";

    goto_xy(33, y + 1);
    cout << "2. ���� ���Ѵ�. ";

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
				cout << "������ �ѿ� �¾Ҵ�";
				playerHP -= 10;
				monsterHP -= 10;
			}
			else if (MonsterChoice(2) == 2)
			{
				goto_xy(30, y + 3);
				cout << "���ݿ� �����ߴ�.";
				monsterHP -= 20;
			}
		}
		if (select == 2)
		{
			if (MonsterChoice(2) == 1)
			{
				goto_xy(30, y + 3);
				cout << "�Ѿ��� ���ߴ�";
			}
			else if (MonsterChoice(2) == 2)
			{
				goto_xy(30, y + 3);
				cout << "���� ���";
				playerHP -= 10;
			}
		}
		cout << "�������� ü�� : " << playerHP << "\t����� ü�� : " << monsterHP;
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
    cout << "�������� ���屺�� ������.";
    goto_xy(30, 5);
    cout << "\"������ ����� ���� ����. �̱�� �Ʒ����׷� ���ϰ� �����ְڴ�.";
    goto_xy(30, 5);
    cout << "���ų� ���ٸ� �ڳ״� �״´�.\"";

    goto_xy(x, y);
    cout << "> ";

    goto_xy(33, y);
    cout << "1. ��";
    goto_xy(33, y + 1);
    cout << "2. ��";
    goto_xy(33, y + 1);
    cout << "3. ��";

	while (true)
	{
		Clear();
		if (Select(3, x, y)==1 && MonsterChoice(3) == 2 || Select(3, x, y) == 2 && MonsterChoice(3) == 3 || Select(3, x, y) == 3 && MonsterChoice(3) == 0)
		{
			goto_xy(30, y + 3);
			cout << "��� <�Ʒ����׷� �Ѿ��>";
            Scene_Fourth();
		}
	    else
		{
			goto_xy(30, y + 3);
			cout << "��! <GAME OVER>";
		}

	}
}

void Scene_Fourth()
{
    Clear();

    goto_xy(30, 5);
    cout << "�������� �Ʒ����׿��� �������� ������.";
    goto_xy(30, 5);
    cout << "\"����;���� ��������\"";
}

void GameOver()
{
    Clear();
    cout << "  �������      �����       ���        ���  �������\n";
    cout << " ���              ���   ���     ����    ����  ���\n";
    cout << "���              ���      ���   ��� ���� ���  ���\n";
    cout << "���    ����   ���       ���   ���  ���  ���  �������\n";
    cout << "���      ���   ���������  ���        ���  ���\n";
    cout << " ���     ���   ���       ���   ���        ���  ���\n";
    cout << "  �������   ���       ���   ���        ���  �������\n";
    cout << "\n";
    cout << " �������   ���       ���   ���������   �������\n";
    cout << "���      ���  ���       ���   ���               ���    ���\n";
    cout << "���      ���  ���       ���   ���               ���    ���\n";
    cout << "���      ���  ���       ���   ���������   ������\n";
    cout << "���      ���   ���     ���    ���               ���  ���\n";
    cout << "���      ���    ������      ���               ���     ���\n";
    cout << " �������        ���         ���������   ���      ���\n";
}
