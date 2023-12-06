# Robot-Maze

This project is a simple console-based robot maze implemented in C++. The program allows a robot to navigate through a maze from a starting point '*' to a finish point '$' while avoiding obstacles ('o').

# How to Use
- **Input Specifications**

  The program takes input for the maze dimensions (N rows and M columns), where both N and M are integers between 2 and 100 (inclusive).
The maze is represented by characters, where '*' denotes the starting point, '$' denotes the finish point, 'o' denotes an obstacle, and '#' denotes the robot's path.

- **Maze Configuration**

  Users input the maze configuration by providing characters for each cell in the maze.
The program identifies the starting point '*' and the finish point '$' based on user input.
Instruction Input

  Users input the number of instructions the robot will follow (num_instructions), where 1 <= num_instructions <= 100.
Each instruction is a character ('w', 'a', 's', or 'd') representing the movement direction (up, left, down, or right, respectively).
Running the Program

  The program executes the robot's instructions, updating the robot's position and checking for collisions with obstacles or walls.
The program outputs error messages for incorrect instructions and displays the final state of the maze.
Output

  The program outputs any error messages for incorrect instructions, such as collisions with obstacles or walls.
It also prints the final state of the maze, marking the robot's path with '#'.
The program concludes by indicating whether the robot successfully reached the finish point or not.

# Example
- Input 1
  ```
  4 4
  ..o$
  *.o.
  o.o.
  ....
  8
  dssddwww
  ```
- Output 1
  ```
  ..o*
  ##o#
  o#o#
  .###
  Robot Mencapai Finish
  ```
- Input 2
  ```
  4 4
  $.o.
  o...
  .oo.
  *...
  11
  ddddwwaaawa
  ```
- Output 2
  ```
  4 Robot Menabrak Tembok
  9 Robot Menabrak Obstacle
  *#o.
  o###
  .oo#
  *###
  Robot Mencapai finish
  ```
