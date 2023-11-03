#include <iostream>

using namespace std;
//Define enum with 64 squares
//Fix Numbers
//Enums -> File Rank
//Functions -> get Rank and File by square

//constexpr bitboard kRank1{0b11111111};
//typedef uint64_t bitboard;

//constexpr bitboard kFileA{0x101010101010101ULL};
//constexpr bitboard kAllSquares = ~0ULL;

//constexpr bitboard kLightSquares
//constexpr bitboard kCenter

//whiteRooks   = 0b10000001;

//Define Kingside QueenSide and WhiteSide and BlackSide

//64 bits booleans 
//White Pawns

//Bit Board  - 64 bit



#define BOARD_SIZE 64
#define END_OF_WHITE_PIECE_SQUARES 15
#define RANK_SIZE 8
#define START_OF_BLACK_PIECE_SQUARES 48
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
            if (i >= START_OF_BLACK_PIECE_SQUARES+RANK_SIZE)
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

    for (int i = BOARD_SIZE-1; i > -1; i--)
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