#include <oslib/oslib.h>

/* CallBacks */
PSP_MODULE_INFO("ConnectFour", 0, 1, 1);
PSP_MAIN_THREAD_ATTR(THREAD_ATTR_USER | THREAD_ATTR_VFPU);

int board[6][7];
int lastMoveX = 0;
int lastMoveY = 0;
int player;
int nMoves;

void drawBoard()
{
    oslPrintf("Connect Four \n\n");
    int y;
    int x;
    oslPrintf("| 1 | 2 | 3 | 4 | 5 | 6 | 7 |\n");
    oslPrintf("-----------------------------\n");
    for (y = 5; y >= 0; y--)
    {
        for (x = 0; x < 7; x++)
        {
            if (board[y][x] == 0)
                oslPrintf("|   ");
            else if (board[y][x] == 1)
                oslPrintf("| X ");
            else if (board[y][x] == 2)
                oslPrintf("| O ");
            if (x == 7 - 1)
                oslPrintf("|\n");
        }
        oslPrintf("-----------------------------\n");
    }
}

void initializeBoard()
{
    int i;
    int j;
    for (i = 0; i < 6; i++)
        for (j = 0; j < 7; j++)
            board[i][j] = 0;
    nMoves = 0;
    player = 1;
}

bool validMove(int col)
{
    return (col >= 1 && col <= 7 && board[5][col - 1] == 0);
}

void executeMove(int col)
{
    int i = 0;
    while (board[i][col - 1] != 0)
        i++;
    board[i][col - 1] = player;
    lastMoveY = i;
    lastMoveX = col - 1;
    player = 3 - player;
    nMoves++;
}

int main()
{
    //Initialization of the Oslib library
    oslInit(0);

    //Initialization of the graphics mode
    oslInitGfx(OSL_PF_8888, 0);

    //Initialization of the text console
    oslInitConsole();

    initializeBoard();
    drawBoard();

    oslWaitKey();

    // End Program
    oslEndGfx();
    oslQuit();
    return 0;
}