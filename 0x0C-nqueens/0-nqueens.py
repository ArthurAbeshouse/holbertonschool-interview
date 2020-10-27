#!/usr/bin/python3
"""N queens"""
import sys


def approve_placement(board, row, col):
    """Determine if it's safe for the queen to assume position"""
    for a in range(col):
        if board[a] is row or abs(board[a] - row) is abs(a - col):
            return False
    return True


def Print_Board(board):
    """Prints the solution and board"""
    pos = []
    board_size = len(board)
    for row in range(board_size):
        sub_array = [row, board[row]]
        pos.append(sub_array)
    print(pos)


def Place_Queen(board, col):
    """Places the queens safely on the board"""
    if col is len(board):
        Print_Board(board)
        return
    for row in range(len(board)):
        if approve_placement(board, row, col):
            board[col] = row
            Place_Queen(board, col + 1)


if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: nqueens N") or exit(1)
    try:
        n = int(sys.argv[1])
    except ValueError:
        print("N must be a number") or exit(1)
    if n < 4:
        print("N must be at least 4") or exit(1)
    board = [[0 for col in range(n)] for row in range(n)]
    Place_Queen(board, 0)
