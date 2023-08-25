#ifndef COUNTDOWN_H
#define COUNTDOWN_H

#include <string>
#include <sstream>
#include <vector>


std::string intToString(const int x)
{
    std::ostringstream str;
    str << x;
    return str.str();
}


using namespace std;
using std::vector;
using std::string;
using std::to_string;

class CountdownSolution {

private:
    string solution;
    int value;

public:

    CountdownSolution() : solution(), value(0) {}

    CountdownSolution(const string& solutionIn, const int valueIn)
            : solution(solutionIn), value(valueIn) {
    }

    const string& getSolution() const {
        return solution;
    }

    int getValue() const {
        return value;
    }
};

double evaluateCountdown(const string& expression) {
    string number;
    vector<double> stack;
    vector<char> vecOfChars(expression.begin(), expression.end());
    vector<string> vecOfStrings;
    for (auto character: vecOfChars) {
        auto value = intToString(character);
        if (stoi(value) >= 48 && stoi(value) <= 57) { //  [1:9]
            number += string(1, character);
        } else if (stoi(value) == 46) { //dot
            number += ".";
        } else if (stoi(value) == 32) { //space
            if (number != "") {
                vecOfStrings.push_back(number);
            }
            number = "";
        } else if (stoi(value) == 43 || stoi(value) == 45 || stoi(value) == 42 || stoi(value) == 47) { // +-*/
            double calc = 0;
            double calc1 = stod(vecOfStrings[vecOfStrings.size() - 2]);
            double calc2 = stod(vecOfStrings[vecOfStrings.size() - 1]);
            if (stoi(value) == 43) {
                calc = calc1 + calc2;
            } else if (stoi(value) == 45) {
                calc = calc1 - calc2;
            } else if (stoi(value) == 42) {
                calc = calc1 * calc2;
            } else if (stoi(value) == 47) {
                calc = calc1 / calc2;
            }
            vecOfStrings.pop_back();
            vecOfStrings.pop_back();
            vecOfStrings.push_back(to_string(calc));
        }
    }
    return stod(vecOfStrings[0]);
}

int pow(int number, int power)
{
    int result = number;
    for (int i = 1; i < power; ++i) {
        result *= number;
    }
    return result;
}

void searchChar(vector<vector<char>>& res, vector<char>& temp_perm, vector<bool>& chosen, vector<char>& arr)
{
    if (temp_perm.size() == arr.size())
    {
        res.push_back(temp_perm);
    }
    else
    {
        for (size_t i = 0; i < arr.size(); i++)
        {
            if (chosen[i] == true)
                continue;

            chosen[i] = true;
            temp_perm.push_back(arr[i]);

            searchChar(res, temp_perm, chosen, arr);

            chosen[i] = false;
            temp_perm.pop_back();
        }
    }
}

vector<vector<char>> generate_permutations_char(vector<char>& arr)
{
    vector<bool> chosen(arr.size() + 1);
    vector<vector<char>> permutations;
    vector<char> permutation;

    searchChar(permutations, permutation, chosen, arr);

    return permutations;
}

void search(vector<vector<int>>& res, vector<int>& temp_perm, vector<bool>& chosen, vector<int>& arr)
{
    if (temp_perm.size() == arr.size()) {
        res.push_back(temp_perm);
    }
    else {
        for (size_t i = 0; i < arr.size(); i++) {
            if (chosen[i] == true)
                continue;

            chosen[i] = true;
            temp_perm.push_back(arr[i]);

            search(res, temp_perm, chosen, arr);

            chosen[i] = false;
            temp_perm.pop_back();
        }
    }
}

vector<vector<int>> generate_permutations(vector<int>& arr)
{
    vector<bool> chosen(arr.size() + 1);
    vector<vector<int>> permutations;
    vector<int> permutation;

    search(permutations, permutation, chosen, arr);

    return permutations;
}

string toBinaryString(const int& number)
{
    int temp_number = number;
    string res = "";

    while (temp_number) {
        res += temp_number % 2 + '0'; // 0 in ascii = 48; converts to symbol type;
        temp_number /= 2;
    }

    for (int i = res.size(); i < 6; i++) {
        res += '0';
    }

    for (int i = 0; i < res.size() / 2; ++i) {
        char temp = res[i];
        res[i] = res[res.size() - 1 - i];
        res[res.size() - 1 - i] = temp;
    }

    return res;
}

vector<vector<int>> getSubsetValues(vector<int>& vec)
{
    vector<vector<int>> subsets;

    for (int i = 0; i < pow(2, vec.size()); i++) {

        vector<int> subset;
        string selected = toBinaryString(i);

        for (int j = 0; j < vec.size(); j++) {
            if (selected[j] == '1') {
                subset.push_back(vec[j]);
            }
        }

        subsets.push_back(subset);
    }

    return subsets;
}

string merge_nums_with_operations(vector<int>& nums, vector<char>& operations)
{
    string res = "";

    int j = 0;
    int k = 0;
    for (size_t i = 0; i < (nums.size() + operations.size()); i++) {
        if (i % 2 == 0) {
            res += to_string(nums[j]);
            j++;
        }
        else {
            res += operations[k];
            k++;
        }
    }

    return res;
}

string merge_nums_with_operations_polish(vector<int>& nums, vector<char>& operations)
{
    string res = "";

    for (size_t i = 0; i < nums.size(); i++) {
        res += to_string(nums[i]);
        res += " ";
    }
    //res += " ";
    for (int i = operations.size() - 1; i >= 0 ; i--) {
        res += operations[i];
        if (i != 0) {
            res += " ";
        }
    }

    return res;
}

CountdownSolution solveCountdownProblem(vector<int>& vec, const int& targetNumber)
{
    string rpn = "";
    vector<char> vectorOfMathsOperations = {'+', '-', '*', '/'};
    vector<vector<char>> vectorOfSubsetsOfMathsOperations;

    vector<char> temp_operations = vectorOfMathsOperations;
    for (size_t i = 0; i < vectorOfMathsOperations.size(); i++) {
        temp_operations.push_back(vectorOfMathsOperations[i]);

        auto temp_subset_operation = generate_permutations_char(temp_operations);
        for (size_t j = 0; j < temp_subset_operation.size(); j++) {
            vectorOfSubsetsOfMathsOperations.push_back(temp_subset_operation[j]);
        }

        temp_operations.pop_back();
    }

    vector<vector<int>> vectorOfSubsetsFromVec = getSubsetValues(vec);

    double the_closest = 1e5;
    double diff_res = targetNumber - the_closest;
    for (int i = 0; i < vectorOfSubsetsFromVec.size(); ++i) {
        vector<vector<int>> generatedPermutations = generate_permutations(vectorOfSubsetsFromVec[i]);
        for (int j = 0; j < generatedPermutations.size(); ++j) {
            for (size_t k = 0; k < vectorOfSubsetsOfMathsOperations.size(); k++) {
                if (vectorOfSubsetsOfMathsOperations[k].size() != generatedPermutations[j].size() - 1) {
                    continue;
                }
                else {
                    if (generatedPermutations[j].size() == 0 || vectorOfSubsetsOfMathsOperations[i].size() == 0) {
                        continue;
                    } else {
                        //cout << merge_nums_with_operations_polish(generatedPermutations[j], vectorOfSubsetsOfMathsOperations[k]) << "=" <<  evaluateCountdown(merge_nums_with_operations_polish(generatedPermutations[j],vectorOfSubsetsOfMathsOperations[k])) << '\n';
                        //cout << rpn << '\n';
                        double calculation = evaluateCountdown(merge_nums_with_operations_polish(generatedPermutations[j], vectorOfSubsetsOfMathsOperations[k]));
                        if (abs(targetNumber - calculation) < abs(targetNumber - the_closest)) {
                            the_closest = calculation;
                            //cout << the_closest << '\n';
                            rpn = merge_nums_with_operations_polish(generatedPermutations[j], vectorOfSubsetsOfMathsOperations[k]);
                            //cout << the_closest;
                        }
                    }
                }
            }
        }
    }

    return CountdownSolution(rpn, the_closest);
}

#endif

