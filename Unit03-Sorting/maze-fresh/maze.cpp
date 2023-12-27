/*
#include <iostream>
#include <string>

#include "Grid.h"

int main(int argc, char* argv[]) {
    // Write your code here

    return 0;
}
*/

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <stack>
#include "Grid.h"

bool isValidCell(const Grid& maze, int row, int column, int level, std::vector<std::vector<std::vector<bool>>>& visited) {
    return row >= 0 && row < maze.height() &&
           column >= 0 && column < maze.width() &&
           level >= 0 && level < maze.depth() &&
           maze.at(row, column, level) == 1 && !visited[level][row][column];
}

bool solveMaze(const Grid& maze, int row, int column, int level, std::vector<std::vector<std::vector<bool>>>& visited, std::stack<std::vector<int>>& path) {
    if (row == maze.height() - 1 && column == maze.width() - 1 && level == maze.depth() - 1) {
        path.push({row, column, level});
        return true;
    }

    visited[level][row][column] = true;

    int dr[] = {0, 0, 0, 0, 1, -1};
    int dc[] = {0, 0, -1, 1, 0, 0};
    int dl[] = {1, -1, 0, 0, 0, 0};

    for (int i = 0; i < 6; ++i) {
        int newRow = row + dr[i];
        int newColumn = column + dc[i];
        int newLevel = level + dl[i];

        if (isValidCell(maze, newRow, newColumn, newLevel, visited)) {
            path.push({newRow, newColumn, newLevel});
            visited[newLevel][newRow][newColumn] = true;
            //std::cout << "Visiting cell: " << row << " " << column << " " << level << std::endl;

            if (solveMaze(maze, newRow, newColumn, newLevel, visited, path)) {
                return true;
            }
            path.pop();
        }
    }
    return false;
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " <input_maze_file> <output_solution_file>" << std::endl;
        return 1;
    }

    std::string inputFileName = argv[1];
    std::string outputFileName = argv[2];

    Grid maze;
    std::ifstream inputMazeFile(inputFileName);

    try {
        inputMazeFile >> maze;
    } catch (const std::exception& e) {
        std::cerr << "Error reading maze: " << e.what() << std::endl;
        return 1;
    }

    std::vector<std::vector<std::vector<bool>>> visited(
        maze.depth(), std::vector<std::vector<bool>>(
            maze.height(), std::vector<bool>(maze.width(), false)
        )
    );
/*
    std::stack<std::vector<int>> path;

    if (solveMaze(maze, 0, 0, 0, visited, path)) {
        std::ofstream outputSolutionFile(outputFileName);
        outputSolutionFile << "SOLUTION" << std::endl;
        path.pop();
        while (!path.empty()) {
            auto coords = path.top();
            path.pop();
            outputSolutionFile << coords[0] << " " << coords[1] << " " << coords[2] << std::endl;
        }

        outputSolutionFile.close();
    } else {
        std::ofstream outputSolutionFile(outputFileName);
        outputSolutionFile << "NO SOLUTION" << std::endl;
        outputSolutionFile.close();
    }
*/
    std::stack<std::vector<int>> path;
    std::vector<std::vector<int>> solutionPath;

    if (solveMaze(maze, 0, 0, 0, visited, path)) {
        // Collect the solution path in reverse order
        while (!path.empty()) {
            solutionPath.push_back(path.top());
            path.pop();
        }   

        std::ofstream outputSolutionFile(outputFileName);
        outputSolutionFile << "SOLUTION" << std::endl;
        outputSolutionFile << "0 0 0" << std::endl;

        // Write the solution path in the correct order
        for (int i = solutionPath.size() - 1; i >= 1; --i) {
            auto coords = solutionPath[i];
            outputSolutionFile << coords[0] << " " << coords[1] << " " << coords[2] << std::endl;
        }

        outputSolutionFile.close();
    } else {
        std::ofstream outputSolutionFile(outputFileName);
        outputSolutionFile << "NO SOLUTION" << std::endl;
        outputSolutionFile.close();
    }

    return 0;
}
