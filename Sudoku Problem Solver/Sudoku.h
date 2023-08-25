#ifndef SUDOKU_H
#define SUDOKU_H

#include "Searchable.h"
#include <set>
#include <vector>
#include <iostream>
#include <utility>


#include <cmath>
#include <string>
#include <iomanip>
using namespace std;


class Sudoku : public Searchable
{
private:
    int size;
    vector<vector<set<int>>> board;

    /*
     * Helper function for successors()
     * Returns the position of a cell where we can put more than one value
     * If there is no such cell, returns pair(-1, -1)
    */
    pair<int, int> findVariadicCellPosition() const
    {
        for (int i = 0; i < size; ++i)
        {
            for (int j = 0; j < size; ++j)
            {
                if (board[i][j].size() > 1)
                {
                    return make_pair(i, j);
                }
            }
        }
        return make_pair(-1, -1);
    }
public:
    Sudoku(int sizeIN) :size(sizeIN) {
        board.resize(size);

        for (int i = 0; i < size; ++i) {
            board[i].resize(size);

            for (int j = 0; j < size; ++j)
                for (int k = 1; k <= size; ++k)
                    board[i][j].insert(k);
        }
    }

    Sudoku(const Sudoku& other) : size(other.size)
    {
        board.resize(size);
        for (size_t i = 0; i < size; ++i)
        {
            board[i].resize(size);

            for (size_t j = 0; j < size; ++j)
            {
                board[i][j] = other.board[i][j];
            }
        }

    }

    int getSquare(int row, int col) const {
        if (board[row][col].size() == 1)
            return *(board[row][col].begin()); // here is the mistake
        return -1;
    }

    bool eraseExtraValues(int row, int col, int value)
    {
        board[row][col].clear();

        bool isErased = false;
        for (int j = 0; j < board[row].size(); ++j)
            if (board[row][j].find(value) != board[row][j].end())
            {
                board[row][j].erase(value);
                isErased = true;
            }

        for (int i = 0; i < size; ++i)
            if (board[i][col].find(value) != board[i][col].end())
            {
                board[i][col].erase(value);
                isErased = true;
            }

        //the size of the box is always the square root of the size of the grid
        int count = sqrt(size);

        if (count * count == size)
        {
            //check if the size of the box has changed, now its 3x3;
            int rowBox = row / count;
            int colBox = col / count;

            int shiftRow = rowBox * count;
            int shiftCol = colBox * count;

            for (int i = 0; i < count; ++i)
                for (int j = 0; j < count; ++j)
                    if (board[i + shiftRow][j + shiftCol].find(value) != board[i + shiftRow][j + shiftCol].end())
                    {
                        board[i + shiftRow][j + shiftCol].erase(value);
                        isErased = true;
                    }
        }

        board[row][col].insert(value);

        return isErased;
    }

    bool setSquare(int row, int col, int value) {
        board[row][col].clear();
        board[row][col].insert(value);

        eraseExtraValues(row, col, value);

        bool isErased;
        do
        {
            isErased = false;

            for (int i = 0; i < size; ++i)
                for (int j = 0; j < size; ++j) {
                    if (board[i][j].size() == 0)
                        return false;

                    if (board[i][j].size() == 1)
                        if (eraseExtraValues(i, j, *board[i][j].begin()))
                            isErased = true;
                }

        } while (isErased);

        return true;
    }

    bool isSolution() const override
    {
        for (const auto& str : board)
        {
            for (const auto& elem : str)
            {
                if (elem.size() > 1)
                {
                    return false;
                }
            }
        }
        return true;
    }

    void write(ostream & o) const override
    {
        for (const auto& str : board)
        {
            for (const auto& elem : str)
            {
                if (elem.size() > 1)
                {
                    o << ' ';
                }
                else
                {
                    o << *(elem.begin());
                }
            }
            o << '\n';
        }
    }

    vector<unique_ptr<Searchable>> successors() const override
    {
        vector<unique_ptr<Searchable>> res{};
        pair<int, int> posOfVariadicCell = findVariadicCellPosition();
        if (posOfVariadicCell.first == -1)
        {
            return res;
        }

        set<int> setOfValues = board[posOfVariadicCell.first][posOfVariadicCell.second];
        for (auto val : setOfValues)
        {
            unique_ptr<Sudoku> s (new Sudoku(*this));
            if ((*s).setSquare(posOfVariadicCell.first, posOfVariadicCell.second, val))
            {
                res.push_back(move(s));
            }
        }
        //return res;
    }

    /**
    void write() const
    {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j)
            {
                string s = "[";

                for (auto it = board[i][j].begin(); it != board[i][j].end(); ++it)
                    s += to_string(*it) + " ";

                s += "] ";

                cout << setw(size * 2 + 3) << s;
            }
            cout << endl;
        }
    }
    */

};


#endif


