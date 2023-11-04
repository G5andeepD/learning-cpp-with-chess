/*
    CHESS BITBOARD

    This is a representation of different entities in a chessboard using 64 bit integers

    Note:
    Least Significant Bit corresponds to a1 square
    Most Significant Bit corresponds to h8 square 

*/
#include <iostream>
using namespace std;

typedef uint64_t bitboard;
// Squares
constexpr bitboard kAllSquares = ~0ULL;

//a1 square is a dark square
constexpr bitboard kLightSquares = 0x55AA55AA55AA55AAULL;
constexpr bitboard kDarkSquares = ~kLightSquares;

constexpr bitboard kKingSide = 0x0F0F0F0F0F0F0F0FULL;
constexpr bitboard kQueenSide = ~kKingSide;

constexpr bitboard kWhiteSide = 0xFFFFFFFFULL;
constexpr bitboard kBlackSide = ~kWhiteSide;

// Ranks
constexpr bitboard kRank1{0b11111111};
constexpr bitboard kRank2 = kRank1 << 8;
constexpr bitboard kRank3 = kRank2 << 8;
constexpr bitboard kRank4 = kRank3 << 8;
constexpr bitboard kRank5 = kRank4 << 8;
constexpr bitboard kRank6 = kRank5 << 8;
constexpr bitboard kRank7 = kRank6 << 8;
constexpr bitboard kRank8 = kRank7 << 8;

// Files
constexpr bitboard kFileA{0x101010101010101ULL};
constexpr bitboard kFileB = kFileA << 1;
constexpr bitboard kFileC = kFileB << 1;
constexpr bitboard kFileD = kFileC << 1;
constexpr bitboard kFileE = kFileD << 1;
constexpr bitboard kFileF = kFileE << 1;
constexpr bitboard kFileG = kFileF << 1;
constexpr bitboard kFileH = kFileG << 1;

// Special Regions
constexpr bitboard kCenter = (kFileD | kFileE) & (kRank4 | kRank5);

// Pieces
// White Pieces
constexpr bitboard kWhiteRooks{0b10000001};
constexpr bitboard kWhiteKnights{0b01000010};
constexpr bitboard kWhiteBishops{0b00100100};
constexpr bitboard kWhiteQueen{0b00010000};
constexpr bitboard kWhiteKing{0b00001000};
constexpr bitboard kWhitePawns{0xFF00ULL};

// Black Pieces

constexpr bitboard kBlackRooks = kWhiteRooks << 56;
constexpr bitboard kBlackKnights = kWhiteKnights << 56;
constexpr bitboard kBlackBishops = kWhiteBishops << 56;
constexpr bitboard kBlackQueen = kWhiteQueen << 56;
constexpr bitboard kBlackKing = kWhiteKing << 56;
constexpr bitboard kBlackPawns = kWhitePawns << 40;

//This function prints the board by taking 8 bit segments starting from MSB and printing the MSB of the segment first
//This will print the bits as like you are looking at the board from white side - (a1 square is at bottom left)
void print_board(bitboard num)
{
    for (int i = 7; i > -1; i--)
    {
        int row = ((num >> i * 8) & 0xFF);
        for (int j = 7; j > -1; j--)
        {
            cout << ((row >> j) & 1);
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{
    bitboard allWhitePieces = kWhiteRooks | kWhiteKnights | kWhiteBishops | kWhiteQueen | kWhiteKing | kWhitePawns;
    bitboard allBlackPieces = kBlackRooks | kBlackKnights | kBlackBishops | kBlackQueen | kBlackKing | kBlackPawns;

    bitboard startingBoard = allWhitePieces | allBlackPieces;
    print_board(startingBoard);
    print_board(kDarkSquares);
    print_board(kLightSquares);
    print_board(kKingSide);
    return 0;
}
