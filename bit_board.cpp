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

// a1 square is a dark square
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

// This function prints the board by taking 8 bit segments starting from MSB and printing the MSB of the segment first
// This will print the bits as like you are looking at the board from white side - (a1 square is at bottom left)
void print_board(bitboard num)
{
    for (int i = 7; i > -1; i--)
    {
        int row = ((num >> (i * 8)));
        for (int j = 0; j < 8; j++)
        {
            cout << ((row >> j) & 1);
        }
        cout << endl;
    }
    cout << endl;
}

// This function takes a fen string as an input and returns the bitboard representation of the board
bitboard fen_to_bitboard(std::string fen)
{
    bitboard board = 0ULL;
    int square = 56; // Starting square is a8 (top-left corner)

    for (char c : fen)
    {
        
        switch (c)

        {
        case 'p':
            board |= (1ULL << square);
            break;
        case 'P':
            board |= (1ULL << square);
            break;
        case 'n':
            board |= (1ULL << square);
            break;
        case 'N':
            board |= (1ULL << square);
            break;
        case 'b':
            board |= (1ULL << square);
            break;
        case 'B':
            board |= (1ULL << square);
            break;
        case 'r':
            board |= (1ULL << square);
            break;
        case 'R':
            board |= (1ULL << square);
            break;
        case 'q':
            board |= (1ULL << square);
            break;
        case 'Q':
            board |= (1ULL << square);
            break;
        case 'k':
            board |= (1ULL << square);
            break;
        case 'K':
            board |= (1ULL << square);
            break;
        case '/':
            square -= 17; // Move to the next rank
            break;
        default:
            square += (c - '0' - 1);
            break;
        }
        square++;
    }

    return board;
}

int main()
{
     // Test Case 1
    std::string fen1 = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR ";
    bitboard board1 = fen_to_bitboard(fen1);
    std::cout << "Board 1: " << fen1 << std::endl;
    print_board(board1);

    // Test Case 2
    std::string fen2 = "8/8/8/8/8/8/8/8 ";
    bitboard board2 = fen_to_bitboard(fen2);
    std::cout << "Board 2: " << fen2 << std::endl;
    print_board(board2);

    // Test Case 3
    std::string fen3 = "rnbqkbnr/1ppppppp/8/p7/8/8/PPPPPPPP/RNBQKBNR ";
    bitboard board3 = fen_to_bitboard(fen3);
    std::cout << "Board 3: " << fen3 << std::endl;
    print_board(board3);

    // Test Case 4
    std::string fen4 = "4k3/8/8/8/8/8/8/4K3 ";
    bitboard board4 = fen_to_bitboard(fen4);
    std::cout << "Board 4: " << fen4 << std::endl;
    print_board(board4);

    // Test Case 5
    std::string fen5 = "r3k2r/8/8/8/8/8/8/R3K2R ";
    bitboard board5 = fen_to_bitboard(fen5);
    std::cout << "Board 5: " << fen5 << std::endl;
    print_board(board5);

    return 0;

    

    return 0;
}
