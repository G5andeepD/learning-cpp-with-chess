#include <iostream>
using namespace std;

typedef uint64_t bitboard;
//Squares
constexpr bitboard kAllSquares = ~0ULL;

// constexpr bitboard kLightSquares;
//constexpr bitboard kDarkSquares = ~kLightSquares;

// constexpr bitboard kKingSide;
//constexpr bitboard kQueenSide = ~kKingSide;

//constexpr bitboard kWhiteSide;
//constexpr bitboard kBlackSide = ~kWhiteSide;



//Ranks
constexpr bitboard kRank1{0b11111111};
// constexpr bitboard kRank2;
// constexpr bitboard kRank3;
// constexpr bitboard kRank4;
// constexpr bitboard kRank5;
// constexpr bitboard kRank6;
// constexpr bitboard kRank7;
// constexpr bitboard kRank8;


//Files
constexpr bitboard kFileA{0x101010101010101ULL};
// constexpr bitboard kFileB;
// constexpr bitboard kFileC;
// constexpr bitboard kFileD;
// constexpr bitboard kFileE;
// constexpr bitboard kFileF;
// constexpr bitboard kFileG;
// constexpr bitboard kFileH;


//Special Regions
//constexpr bitboard kCenter = (kFileD|kFileE) & (kRank4 | kRank5);


//Pieces
//White Pieces
// constexpr bitboard kWhiteRooks;
// constexpr bitboard kWhiteKnights;
// constexpr bitboard kWhiteBishops;
// constexpr bitboard kWhiteQueen;
// constexpr bitboard kWhiteKing;
// constexpr bitboard kWhitePawns;

//Black Pieces

// constexpr bitboard kBlackRooks;
// constexpr bitboard kBlackKnights;
// constexpr bitboard kBlackBishops;
// constexpr bitboard kBlackQueen;
// constexpr bitboard kBlackKing;
// constexpr bitboard kBlackPawns;

void print_binary_64_bit(uint64_t num) {
    for (int i = 63; i >= 0; --i) {
        cout << ((num >> i) & 1);
        if (i % 8 == 0) {
            cout << endl;
        }
    }
    cout << endl;
}

int main(){
    print_binary_64_bit(kAllSquares);
    return 0;
}

