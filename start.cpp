#include <iostream>

using namespace std;

#define BOARD_SIZE 64
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

    Square chessboard[BOARD_SIZE];

    // Setting Up Squares and Pieces

    for (int i = 0; i < BOARD_SIZE; i++)
    {

        chessboard[i].squareColor = (i) % 2 == 1 ? WHITE : BLACK;
        if (i < 16)
        {
            chessboard[i].piece.pieceColor = WHITE;
            // Set white pieces in the first two rows
            if (i < 8)
            {
                switch (i % 8)
                {
                case 0:
                case 7:
                    chessboard[i].piece.pieceName = ROOK;
                    break;
                case 1:
                case 6:
                    chessboard[i].piece.pieceName = KNIGHT;
                    break;
                case 2:
                case 5:
                    chessboard[i].piece.pieceName = BISHOP;
                    break;
                case 4:
                    chessboard[i].piece.pieceName = QUEEN;
                    break;
                case 3:
                    chessboard[i].piece.pieceName = KING;
                    break;
                default:
                    chessboard[i].piece.pieceName = NONE;
                    break;
                }
            }
            else
            {
                chessboard[i].piece.pieceName = PAWN;
            }
        }
        // Set black pieces in the last two rows
        else if (i >= 48)
        {
            chessboard[i].piece.pieceColor = BLACK;
            // Set Main pieces to last row
            if (i >= 56)
            {
                switch (i % 8)
                {
                case 0:
                case 7:
                    chessboard[i].piece.pieceName = ROOK;
                    break;
                case 1:
                case 6:
                    chessboard[i].piece.pieceName = KNIGHT;
                    break;
                case 2:
                case 5:
                    chessboard[i].piece.pieceName = BISHOP;
                    break;
                case 4:
                    chessboard[i].piece.pieceName = QUEEN;
                    break;
                case 3:
                    chessboard[i].piece.pieceName = KING;
                    break;
                default:
                    chessboard[i].piece.pieceName = NONE;
                    break;
                }
            }
            else
            {
                chessboard[i].piece.pieceName = PAWN;
            }
        }
        else
        {

            chessboard[i].piece.pieceName = NONE;
        }
    }

    // print the chess board

    for (int i = 63; i > -1; i--)
    {

        if (chessboard[i].piece.pieceColor == WHITE)
        {
            switch (chessboard[i].piece.pieceName)
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

            switch (chessboard[i].piece.pieceName)
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
        if (i % 8 == 0)
        {
            cout << "\n";
        }
    }

    return 0;
}