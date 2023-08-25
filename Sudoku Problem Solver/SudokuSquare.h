#ifndef SUDOKUSQUARE_H
#define SUDOKUSQUARE_H

#include <cstdint>
#include <Iostream>


class SudokuSquareSet {
private:
    int          numOfValues;
    unsigned int bitStorage;
public:
    SudokuSquareSet() : numOfValues(0), bitStorage(0) {}

    int size()
    {
        return numOfValues;
    }

    bool empty()
    {
        return numOfValues ? false : true;
    }

    void clear()
    {
        numOfValues = 0;
        bitStorage  = 0;
    }

    friend bool operator==(const SudokuSquareSet& lhs, const SudokuSquareSet& rhs);
    friend bool operator!=(const SudokuSquareSet& lhs, const SudokuSquareSet& rhs);

    class Iterator
    {
    private:
        uint32_t pos{};
        unsigned int bits{};
    public:
        Iterator(unsigned int _bits)
        {
            bits = _bits;

            while ((pos < 32) and not ((bits >> pos) & 1))
            {
                ++pos;
            }
        }
        Iterator(const Iterator& other) : pos(other.pos), bits(other.bits) {}

        Iterator& operator++()
        {
            ++pos;

            while((pos < 32) and not ((bits >> pos) & 1))
            {
                //std::cout << ".!.\n";
                ++pos;
            }
            return *this;
        }

        uint32_t & getPos() {
            return pos;
        }

        Iterator operator++(int)
        {
            Iterator tmp(*this);

            ++pos;

            while((pos < 32) and not ((bits >> pos) & 1))
            {
                ++pos;
            }

            return tmp;
        }

        Iterator operator+(const int rhs)
        {
            Iterator tmp(*this);
            for (size_t i = 0; i < rhs; ++i)
            {
                ++tmp;
            }
            return tmp;
        }

        Iterator& operator+=(const int rhs)
        {
            for (size_t i = 0; i < rhs; ++i)
            {
                ++(*this);
            }
            return *this;
        }

        int operator*()
        {
            return pos + 1;
        }

        friend bool operator==(const Iterator& lhs, const Iterator& rhs);
        friend bool operator!=(const Iterator& lhs, const Iterator& rhs);

    };

    Iterator begin()
    {
        return Iterator(bitStorage);
    }

    Iterator end()
    {
        return Iterator(bitStorage) + numOfValues;
    }

    Iterator insert(int value)
    {
        bitStorage |= (1 << (value - 1));
        ++numOfValues;
        return Iterator(bitStorage) + (numOfValues - 1);
    }

    Iterator erase(int value) {
        bitStorage &= ~(1 << (value - 1));
        --numOfValues;
        return Iterator(bitStorage) + (numOfValues - 1);
    }

    Iterator erase(SudokuSquareSet::Iterator& value) {
        return erase((int) value.getPos());
    }

    Iterator find(int value) {
        value = (uint32_t) value;
        Iterator tmp(begin());
        ++tmp.getPos();

        while ((tmp.getPos() < 32) and not((tmp.getPos() >> tmp.getPos()) & 1)) {
            if (tmp.getPos() == value)
                return value;
            ++tmp.getPos();
        }

        return end();
    }



};

inline bool operator==(const SudokuSquareSet& lhs, const SudokuSquareSet& rhs)
{
    return lhs.bitStorage == rhs.bitStorage;
}

inline bool operator!=(const SudokuSquareSet& lhs, const SudokuSquareSet& rhs)
{
    return lhs.bitStorage != rhs.bitStorage;
}

inline bool operator==(const SudokuSquareSet::Iterator& lhs, const SudokuSquareSet::Iterator& rhs)
{
    return lhs.pos == rhs.pos;
}

inline bool operator!=(const SudokuSquareSet::Iterator& lhs, const SudokuSquareSet::Iterator& rhs)
{
    return lhs.pos != rhs.pos;
}

static_assert(sizeof(SudokuSquareSet) == sizeof(unsigned int) + sizeof(int), "The SudokuSquareSet class needs to have exactly two 'int' member variables, and no others");


#endif

