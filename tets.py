game_board = [
    [0, 2, 0, 0, 3, 0],
    [0, 2, 0, 0, 3, 0],
    [1, 1, 0, 0, 0, 0],
    [0, 0, 0, 4, 0, 0],
    [0, 0, 0, 4, 0, 0],
    [0, 0, 0, 0, 0, 0]
]
def display_board(board):
    for row in board:
        print(' '.join(str(cell) for cell in row))
def find_block_positions(board, block_number):
    positions = []
    for i, row in enumerate(board):
        for j, cell in enumerate(row):
            if cell == block_number:
                positions.append((i, j))
    return positions

def is_move_legal(board, positions, direction):
    for i, j in positions:
        if direction == "up" and (i == 0 or board[i-1][j] not in (0, positions)):
            return False
        elif direction == "down" and (i == 5 or board[i+1][j] not in (0, positions)):
            return False
        elif direction == "left" and (j == 0 or board[i][j-1] not in (0, positions)):
            return False
        elif direction == "right" and (j == 5 or board[i][j+1] not in (0, positions)):
            return False
    return True

def move_block(board, block_number, direction):
    positions = find_block_positions(board, block_number)
    if not positions:
        print(f"Block {block_number} not found.")
        return False

    if not is_move_legal(board, positions, direction):
        print(f"Move {direction} is not legal.")
        return False

    # Clear current positions
    for i, j in positions:
        board[i][j] = 0

    # Move block
    new_positions = []
    if direction == "up":
        new_positions = [(i-1, j) for i, j in positions]
    elif direction == "down":
        new_positions = [(i+1, j) for i, j in positions]
    elif direction == "left":
        new_positions = [(i, j-1) for i, j in positions]
    elif direction == "right":
        new_positions = [(i, j+1) for i, j in positions]

    # Set new positions
    for i, j in new_positions:
        board[i][j] = block_number

    return True

def run_game():
    while True:
        display_board(game_board)
        block_number = int(input("Enter block number to move (1 for red block): "))
        direction = input("Enter direction to move (left, right, up, down): ")
        if move_block(game_board, block_number, direction):
            print("Move not possible. Try again.")
        # Add more conditions to check for game win or quit.

run_game()