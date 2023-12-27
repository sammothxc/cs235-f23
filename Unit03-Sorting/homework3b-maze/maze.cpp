#include <iostream>
#include <fstream>
#include <vector>
#include "Grid.h"

using namespace std;

// Function to solve the maze using recursion
bool solveMaze(Grid& maze, int row, int column, int level, vector<vector<vector<bool>>>& visited, vector<vector<vector<int>>>& path) {
    // Base case: If we reached the destination
    cout << "entered solvemaze" << endl;
    if (row == maze.height() - 1 && column == maze.width() - 1 && level == maze.depth() - 1) {
        return true;
    }
    cout << "sm1" << endl;
    // Check if the current cell is valid and not visited
    if (row >= 0 && row < maze.height() && column >= 0 && column < maze.width() && level >= 0 && level < maze.depth() && maze.at(row, column, level) == 1 && !visited[row][column][level]) {
        // Mark the current cell as visited
        visited[row][column][level] = true;
        cout << "visiting a cell" << endl;


        // Try moving in all possible directions
        if (solveMaze(maze, row + 1, column, level, visited, path) ||
            solveMaze(maze, row - 1, column, level, visited, path) ||
            solveMaze(maze, row, column + 1, level, visited, path) ||
            solveMaze(maze, row, column - 1, level, visited, path) ||
            solveMaze(maze, row, column, level + 1, visited, path) ||
            solveMaze(maze, row, column, level - 1, visited, path)) {
            // If a path is found, add the current coordinate to the path
            path.push_back({{row, column, level}});
            cout << "found a path" << endl;
            return true;
        }

    }

    // If no path found from this cell, mark it as unvisited and return false
    visited[row][column][level] = false;
    cout << "no path" << endl;

    return false;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cerr << "Usage: " << argv[0] << " <input_maze_file> <output_solution_file>" << endl;
        return 1;
    }

    ifstream input(argv[1]);
    ofstream output(argv[2]);

    if (!input) {
        cerr << "Error: Unable to open input file." << endl;
        return 1;
    }

    if (!output) {
        cerr << "Error: Unable to open output file." << endl;
        return 1;
    }
    cout << "files initialized" << endl;
    Grid maze; // Create a Grid object to store the maze
    input >> maze; // Read the maze from the input file

    vector<vector<vector<bool>>> visited(maze.height(), vector<vector<bool>>(maze.width(), vector<bool>(maze.depth(), false)));

    vector<vector<vector<int>>> path;
    cout << "starting maze" << endl;
    if (solveMaze(maze, 0, 0, 0, visited, path)) {
        output << "SOLUTION" << endl;
        cout << "printing solution" << endl;
        for (const auto& coordinates : path) {
            for (const auto& coordinate : coordinates) {
                output << coordinate[0] << ' ' << coordinate[1] << ' ' << coordinate[2] << endl;
            }
        }
        cout << "solution" << endl;
   } else {
        output << "NO SOLUTION" << endl;
        cout << "no solution" << endl;
    }

    input.close();
    output.close();
    cout << "ending" << endl;
    return 0;
}
