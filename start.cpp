#include <iostream>

using namespace std;

// Colors for Squares and Pieces
enum Color
{
    WHITE,
    BLACK
};

// Standard Piece Names
enum PieceName
{
    KING,
    QUEEN,
    ROOK,
    KNIGHT,
    BISHOP,
    PAWN,
    NONE
};

// Piece Structure with Color and Name
struct Piece
{
    Color pieceColor;
    PieceName pieceName;
};

// Square with square color and a piece
struct Square
{
    Color squareColor;
    Piece piece;
};

int main()
{

    Square chessboard[8][8];

    // Setting Up Squares and Pieces

    for (int row = 0; row < 8; row++)
    {
        for (int col = 0; col < 8; col++)
        {
            chessboard[row][col].squareColor = (row + col) % 2 == 1 ? WHITE : BLACK;
            if (row < 2)
            {
                chessboard[row][col].piece.pieceColor = WHITE;
                // Set white pieces in the first two rows
                if (row == 0)
                {
                    switch (col)
                    {
                    case 0:
                    case 7:
                        chessboard[row][col].piece.pieceName = ROOK;
                        break;
                    case 1:
                    case 6:
                        chessboard[row][col].piece.pieceName = KNIGHT;
                        break;
                    case 2:
                    case 5:
                        chessboard[row][col].piece.pieceName = BISHOP;
                        break;
                    case 3:
                        chessboard[row][col].piece.pieceName = QUEEN;
                        break;
                    case 4:
                        chessboard[row][col].piece.pieceName = KING;
                        break;
                    default:
                        chessboard[row][col].piece.pieceName = NONE;
                        break;
                    }
                }
                else
                {
                    chessboard[row][col].piece.pieceName = PAWN;
                }
            }
            // Set black pieces in the last two rows
            else if (row >= 6)
            {
                chessboard[row][col].piece.pieceColor = BLACK;
                // Set Main pieces to last row
                if (row == 7)
                {
                    switch (col)
                    {
                    case 0:
                    case 7:
                        chessboard[row][col].piece.pieceName = ROOK;
                        break;
                    case 1:
                    case 6:
                        chessboard[row][col].piece.pieceName = KNIGHT;
                        break;
                    case 2:
                    case 5:
                        chessboard[row][col].piece.pieceName = BISHOP;
                        break;
                    case 3:
                        chessboard[row][col].piece.pieceName = QUEEN;
                        break;
                    case 4:
                        chessboard[row][col].piece.pieceName = KING;
                        break;
                    default:
                        chessboard[row][col].piece.pieceName = NONE;
                        break;
                    }
                }
                else
                {
                    chessboard[row][col].piece.pieceName = PAWN;
                }
            }
            else
            {

                chessboard[row][col].piece.pieceName = NONE;
            }
        }
    }

    // print the chess board
    for (int row = 7; row > -1; row--)
    {
        for (int col = 0; col < 8; col++)
        {
            
            if (chessboard[row][col].piece.pieceColor == WHITE)
            {
                switch (chessboard[row][col].piece.pieceName)
                {
                case KING:
                    cout << "K";
                    break;
                case QUEEN:
                    cout << "Q";
                    break;
                case ROOK:
                    cout << "R";
                    break;
                case KNIGHT:
                    cout << "N";
                    break;
                case BISHOP:
                    cout << "B";
                    break;
                case PAWN:
                    cout << "P";
                    break;
                case NONE:
                    cout << "X";
                    break;
                }
            }
            else
            {

                switch (chessboard[row][col].piece.pieceName)
                {
                case KING:
                    cout << "k";
                    break;
                case QUEEN:
                    cout << "q";
                    break;
                case ROOK:
                    cout << "r";
                    break;
                case KNIGHT:
                    cout << "n";
                    break;
                case BISHOP:
                    cout << "b";
                    break;
                case PAWN:
                    cout << "p";
                    break;

                case NONE:
                    cout << "X";
                    break;
                }
            }

            cout << "  ";
        }
        cout << endl;
    }

    return 0;
}