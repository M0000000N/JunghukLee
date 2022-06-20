#include "header.h"
#include "Scene.h"


int main()
{
    TitleScene();
    if (IS_KEY_DOWN(VK_SPACE))
    {
        Clear();        
    }
    return 0;
}

