#include <iostream>
#include <string.h>

using namespace std;

#define BOARD_SIZE 64
#define END_OF_WHITE_PIECE_SQUARES 15
#define RANK_SIZE 8
#define START_OF_BLACK_PIECE_SQUARES 48

enum SquareName
{
    a1,
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    b1,
    b2,
    b3,
    b4,
    b5,
    b6,
    b7,
    b8,
    c1,
    c2,
    c3,
    c4,
    c5,
    c6,
    c7,
    c8,
    d1,
    d2,
    d3,
    d4,
    d5,
    d6,
    d7,
    d8,
    e1,
    e2,
    e3,
    e4,
    e5,
    e6,
    e7,
    e8,
    f1,
    f2,
    f3,
    f4,
    f5,
    f6,
    f7,
    f8,
    g1,
    g2,
    g3,
    g4,
    g5,
    g6,
    g7,
    g8,
    h1,
    h2,
    h3,
    h4,
    h5,
    h6,
    h7,
    h8
};

enum Rank
{
    Rank1,
    Rank2,
    Rank3,
    Rank4,
    Rank5,
    Rank6,
    Rank7,
    Rank8
};
enum File
{
    a,
    b,
    c,
    d,
    e,
    f,
    g,
    h
};

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
    SquareName squareName;
    Piece piece;
};

Rank getRank(SquareName squareName){
    int i = static_cast<int>(squareName);
    

    return Rank(i%RANK_SIZE);
};

File getFile(SquareName squareName){

    int i = static_cast<int>(squareName);
    

    return File(i/RANK_SIZE);

}

int main()
{

    Square chessboard[BOARD_SIZE];

    // Setting Up Squares and Pieces
    for (int i = 0; i < BOARD_SIZE; i++)
    {

        chessboard[i].squareName = SquareName(i);
        chessboard[i].squareColor = (i) % 2 == 1 ? WHITE : BLACK;
        if (i <= END_OF_WHITE_PIECE_SQUARES)
        {
            chessboard[i].piece.pieceColor = WHITE;
            // Set white pieces in the first two rows
            if (i < RANK_SIZE)
            {
                switch (i % RANK_SIZE)
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
        else if (i >= START_OF_BLACK_PIECE_SQUARES)
        {
            chessboard[i].piece.pieceColor = BLACK;
            // Set Main pieces to last row
            if (i >= START_OF_BLACK_PIECE_SQUARES + RANK_SIZE)
            {
                switch (i % RANK_SIZE)
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

    for (int i = BOARD_SIZE - 1; i > -1; i--)
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
