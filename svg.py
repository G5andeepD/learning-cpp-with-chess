
import chess
import chess.svg

board = chess.Board("8/8/8/8/4N3/8/8/8 w - - 0 1")

s = chess.svg.board(
    board,
    fill=dict.fromkeys(board.attacks(chess.E4), "#cc0000cc"),
    arrows=[chess.svg.Arrow(chess.E4, chess.F6, color="#0000cccc")],
    squares=chess.SquareSet(chess.BB_DARK_SQUARES & chess.BB_FILE_B),
    size=350,
) 
print(s)