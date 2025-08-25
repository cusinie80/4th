import time
import os

board = [' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ']     
player = 1     
Win = 1     
Draw = -1     
Running = 0     
Stop = 1

Game = Running     
Mark = 'X'     

# This Function Draws Game Board     
def DrawBoard():
    print(" %c | %c | %c " % (board[1], board[2], board[3]))
    print("___|___|___")     
    print(" %c | %c | %c " % (board[4], board[5], board[6]))
    print("___|___|___")     
    print(" %c | %c | %c " % (board[7], board[8], board[9]))
    print("   |   |   ")     

# This Function Checks if the position is empty
def CheckPosition(x):
    return board[x] == ' '

# This Function Checks if a player has won or not
def CheckWin():
    global Game     
    # Horizontal winning condition
    if (board[1] == board[2] == board[3] != ' ' or
        board[4] == board[5] == board[6] != ' ' or
        board[7] == board[8] == board[9] != ' '):
        Game = Win

    # Vertical Winning Condition
    elif (board[1] == board[4] == board[7] != ' ' or
          board[2] == board[5] == board[8] != ' ' or
          board[3] == board[6] == board[9] != ' '):
        Game = Win

    # Diagonal Winning Condition
    elif (board[1] == board[5] == board[9] != ' ' or
          board[3] == board[5] == board[7] != ' '):
        Game = Win

    # Match Tie or Draw Condition
    elif all(space != ' ' for space in board[1:]):
        Game = Draw
    else:
        Game = Running     

# Game Start
print("Tic-Tac-Toe Game")
print("Player 1 [X] --- Player 2 [O]\n")
print("Please Wait...")
time.sleep(1)

while Game == Running:
    os.system('cls' if os.name == 'nt' else 'clear')
    DrawBoard()
    if player % 2 != 0:
        print("Player 1's Turn [X]")
        Mark = 'X'
    else:
        print("Player 2's Turn [O]")
        Mark = 'O'

    try:
        choice = int(input("Enter the position between [1-9] where you want to mark: "))
        if choice >= 1 and choice <= 9:
            if CheckPosition(choice):
                board[choice] = Mark
                player += 1
                CheckWin()
            else:
                print("Position already taken. Try again.")
                time.sleep(1)
        else:
            print("Invalid Input. Enter number between 1-9.")
            time.sleep(1)
    except ValueError:
        print("Invalid input! Please enter a number.")
        time.sleep(1)

# Game Over - Final Board
os.system('cls' if os.name == 'nt' else 'clear')
DrawBoard()
if Game == Draw:
    print("Game Draw")
elif Game == Win:
    player -= 1
    if player % 2 != 0:
        print("Player 1 Won")
    else:
        print("Player 2 Won")

# ✅ Prevent immediate closure
input("\nPress Enter to exit...")
