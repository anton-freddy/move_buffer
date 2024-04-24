// MIT License

// Copyright (c) 2024 Anton Andres

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#ifndef MoveBuffer_h
#define MoveBuffer_h

#include <Arduino.h>

// ------------------------------------ FLOAT(DEFAULT) DATA TYPE MOVE BUFFER ---------------------------------
struct move
{
    float x;
    float y;
    float z;
    move *next;
};

class MoveBuffer
{
private:
    move *head = nullptr;
    move *tail = nullptr;

public:
    MoveBuffer();
    bool isEmpty();
    int getSize();
    bool deleteMoveByIndex(int index);
    void enqueueMove(float x, float y, float z);
    void enqueueMove(float x, float y);
    void insertMoveBeforeCurrent(float x, float y, float z);
    void insertMoveBeforeCurrent(float x, float y);
    void insertMoveBeforeIndex(int index, float x, float y, float z);
    void insertMoveBeforeIndex(int index, float x, float y);
    bool peekNextMove(float &x, float &y, float &z);
    bool peekNextMove(float &x, float &y);
    bool getNextMove(float &x, float &y, float &z);
    bool getNextMove(float &x, float &y);
    bool peekMoveByIndex(int index, float &x, float &y, float &z);
    bool peekMoveByIndex(int index, float &x, float &y);
    bool getNextMoveByIndex(int index, float &x, float &y, float &z);
    bool getNextMoveByIndex(int index, float &x, float &y);

    void clearMoves();
};

// ------------------------------------ End of Section---------------------------------

// ------------------------------------ DOUBLE DATA TYPE MOVE BUFFER ---------------------------------
struct move_double
{
    double x;
    double y;
    double z;
    move_double *next;
};

class MoveBuffer_double
{
private:
    move_double *head = nullptr;
    move_double *tail = nullptr;

public:
    MoveBuffer_double();
    bool isEmpty();
    int getSize();
    bool deleteMoveByIndex(int index);
    void enqueueMove(double x, double y, double z);
    void enqueueMove(double x, double y);
    void insertMoveBeforeCurrent(double x, double y, double z);
    void insertMoveBeforeCurrent(double x, double y);
    void insertMoveBeforeIndex(int index, double x, double y, double z);
    void insertMoveBeforeIndex(int index, double x, double y);
    bool peekNextMove(double &x, double &y, double &z);
    bool peekNextMove(double &x, double &y);
    bool getNextMove(double &x, double &y, double &z);
    bool getNextMove(double &x, double &y);
    bool peekMoveByIndex(int index, double &x, double &y, double &z);
    bool peekMoveByIndex(int index, double &x, double &y);
    bool getNextMoveByIndex(int index, double &x, double &y, double &z);
    bool getNextMoveByIndex(int index, double &x, double &y);

    void clearMoves();
};

// ------------------------------------ End of Section---------------------------------

// ------------------------------------ LONG DATA TYPE MOVE BUFFER ---------------------------------
struct move_long
{
    long x;
    long y;
    long z;
    move_long *next;
};

class MoveBuffer_long
{
private:
    move_long *head = nullptr;
    move_long *tail = nullptr;

public:
    MoveBuffer_long();
    bool isEmpty();
    int getSize();
    bool deleteMoveByIndex(int index);
    void enqueueMove(long x, long y, long z);
    void enqueueMove(long x, long y);
    void insertMoveBeforeCurrent(long x, long y, long z);
    void insertMoveBeforeCurrent(long x, long y);
    void insertMoveBeforeIndex(int index, long x, long y, long z);
    void insertMoveBeforeIndex(int index, long x, long y);
    bool peekNextMove(long &x, long &y, long &z);
    bool peekNextMove(long &x, long &y);
    bool getNextMove(long &x, long &y, long &z);
    bool getNextMove(long &x, long &y);
    bool peekMoveByIndex(int index, long &x, long &y, long &z);
    bool peekMoveByIndex(int index, long &x, long &y);
    bool getNextMoveByIndex(int index, long &x, long &y, long &z);
    bool getNextMoveByIndex(int index, long &x, long &y);

    void clearMoves();
};
// ------------------------------------ END ---------------------------------
#endif