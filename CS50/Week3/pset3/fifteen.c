/**
 * fifteen.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Implements Game of Fifteen (generalized to d x d).
 *
 * Usage: fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [DIM_MIN,DIM_MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 */
 
#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// constants
#define DIM_MIN 3
#define DIM_MAX 9

// board
int board[DIM_MAX][DIM_MAX];

// dimensions
int d;

// prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);

int main(int argc, string argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }

    // ensure valid dimensions
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    // open log
    FILE* file = fopen("log.txt", "w");
    if (file == NULL)
    {
        return 3;
    }

    // greet user with instructions
    greet();

    // initialize the board
    init();

    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // log the current state of the board (for testing)
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                fprintf(file, "%i", board[i][j]);
                if (j < d - 1)
                {
                    fprintf(file, "|");
                }
            }
            fprintf(file, "\n");
        }
        fflush(file);

        // check for win
        if (won())
        {
            printf("ftw!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        int tile = GetInt();
        
        // quit if user inputs 0 (for testing)
        if (tile == 0)
        {
            break;
        }

        // log move (for testing)
        fprintf(file, "%i\n", tile);
        fflush(file);

        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // sleep thread for animation's sake
        usleep(500000);
    }
    
    // close log
    fclose(file);

    // success
    return 0;
}

/**
 * Clears screen using ANSI escape sequences.
 */
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

/**
 * Greets player.
 */
void greet(void)
{
    clear();
    printf("WELCOME TO GAME OF FIFTEEN\n");
    usleep(2000000);
}

/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).  
 */
void init(void)
{
    // TODO
    int num = d*d-1;
    for (int i = 0; i < d; ++i)
    {
        for (int j = 0; j < d; ++j)
        {
            if (num!=-1)
            {
                if (d%2==0&&num==2)
                {
                    board[i][j] = num-1;
                    --num;
                }else if(d%2==0&&num==1){
                    board[i][j] = num+1;
                    --num;
                }else if(num==0){
                    break;
                }else{
                    board[i][j] = num;
                    --num;
                }
            
            }
        }           
    }   
}

/**
 * Prints the board in its current state.
 */
void draw(void)
{
    // 'TODO'
    for (int i = 0; i < d; ++i)
    {
        for (int j = 0; j < d; ++j)
        {
            if (board[i][j]<10)
            {
                printf(" %i  ",board[i][j]);
            }else{
                printf("%i  ",board[i][j]);
            }
        }
        printf("\n");           
    }   

}

/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false. 
 */
bool move(int tile)
{
    // TODO
    int up = 2;
    int down =4;
    int left =1;
    int right = 3;
    int empty_sign = 0;

    int i = 0;
    int j = 0;
    //find the empty board element,represent by -1
    for (int m = 0; m < d; m++)
    {
      for (int n = 0; n < d; n++)
      {
        if (board[m][n]==empty_sign)
        {
            i = m;j = n;
            break;
        }
      }
    }
    //move action
    if (tile==up&&i!=0&&board[i-1][j]!=0)
    {
      //move up
      board[i][j]=board[i-1][j];
      board[i-1][j]=empty_sign;
      return true;
    }else if (tile==down&&i!=(d-1)&&board[i+1][j]!=0)
    {
      //move down
      board[i][j]=board[i+1][j];
      board[i+1][j]=empty_sign;
      return true;
    }else if (tile==left&&j!=0&&board[i][j-1]!=0)
    {
      //move left
      board[i][j]=board[i][j-1];
      board[i][j-1]=empty_sign;
      return true;
    }else if (tile==right&&j!=(d-1)&&board[i][j+1]!=0)
    {
      //move right
      board[i][j]=board[i][j+1];
      board[i][j+1]=empty_sign;
      return true;
    }else{
    return false;
    }
}

/**
 * Returns true if game is won (i.e., board is in winning configuration), 
 * else false.
 */
bool won(void)
{
    int i =0;
    int j =0;
    int n =1;
    
    while(n<d*d){
        //check number
        if(n!=board[i][j]){
            return false;
        }
        //go though the board
        if ((j+1)%d==0)
        {
            i++;
            j=0;
        }else{
            j++;
        }
        n++;
    }

    return true; 
}