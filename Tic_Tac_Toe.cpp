#include <iostream>
#include <cstdlib>
using namespace std;
#define nl "\n"
char matrix[3][3];
char check();
void init_matrix();
void get_player_move();
void get_computer_move();
void disp_matrix();
int main()
{
    char done;
    cout << "This is the game of Tic Tac Toe." << nl;
    cout << "You'll be playing against computer." << nl;
    done = ' ';
    init_matrix();
    do
    {
        disp_matrix();
        get_player_move();
        done = check();
        if (done != ' ')
        {
            break;
        }
        get_computer_move();
        done = check();
    }
    while (done == ' ');

    if (done == 'X')
    {
        cout << "You won!!!" << nl;
    }
    else if (done == 'O')
    {
        cout << "Robot Won!!!" << nl;
    }
    else
    {
        cout << "It's a draw!!!" << nl;
    }
    disp_matrix();
    return 0;
}
void init_matrix()
{
    int i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            matrix[i][j] = ' ';
        }
    }
}
void get_player_move()
{
    int x, y;
    cout << "Enter X,Y coordinates for your move: ";
    cin >> x >> y;
    x--;
    y--;
    if (matrix[x][y] == ' ')
    {
        matrix[x][y] = 'X';
    }
    else
    {
        cout << "Invalid move, try again." << nl;
        get_player_move();

    }
}
void get_computer_move()
{
    int i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (matrix[i][j] == ' ')
            {
                break;
            }
        }
        if (matrix[i][j] == ' ')
        {
            break;
        }
    }
    if (i * j == 9)
    {
        cout << "Draw!" << nl;
        exit(0);
    }
    else
    {
        matrix[i][j] = 'O';
    }
}
void disp_matrix()
{
    int t;
    for (t = 0; t < 3; t++)
    {
        cout << matrix[t][0] << "  | " << matrix[t][1] << " |" << matrix[t][2];
        if (t != 2)
        {
            cout << "\n---|---|---\n";
        }
        else
        {
            cout << endl;

        }
    }
}
char check()
{
    int i, j;
    for (i = 0; i < 3; i++)   /* check rows */
    {
        if (matrix[i][0] == matrix[i][1] && matrix[i][0] == matrix[i][2])
        {
            return matrix[i][0];
        }
    }
    for (i = 0; i < 3; i++)   /* check columns */
    {
        if (matrix[0][i] == matrix[1][i] && matrix[0][i] == matrix[2][i])
        {
            return matrix[0][i];
        }
    }
    /* test diagonals */
    if (matrix[0][0] == matrix[1][1] && matrix[1][1] == matrix[2][2])
    {
        return matrix[0][0];
    }
    if (matrix[0][2] == matrix[1][1] && matrix[1][1] == matrix[2][0])
    {
        return matrix[0][2];
    }
    return ' ';
}
