
# MoveBuffer Library

*Copyright (c) 2024 Anton Andres*

The `MoveBuffer` library provides a circular buffer for storing and managing movement data in Cartesian coordinates (X, Y, Z). Designed for use in robotics and 3D printing, this library efficiently manages sequences of moves.

## Features

- Efficiently add and remove moves.
- Peek at moves without removing them from the buffer.
- Access moves directly by index.
- Support for multiple data types with specialized classes.
- Automatic management of buffer space.

## Supported Data Types

The library provides separate classes for different data types, allowing users to choose the appropriate precision and type based on their needs:
- `MoveBuffer`: Handles `float` data types, used as the default.
- `MoveBuffer_double`: Handles `double` data types for higher precision.
- `MoveBuffer_long`: Handles `long` data types for integer coordinates.

## Installation
There's two option for installing the `MoveBuffer` library
#### Manual Installation
Download or clone the repository from github: https://github.com/anton-freddy/move_buffer

#### Library Registry
The library is available on both Arduino IDE registry as well as PlatformIO

#### Add to project
Add this line to your main header or cpp/ino file
```plaintext
#include <MoveBuffer.h>
```

## Methods

### Class Definition
```cpp
MoveBuffer myBuffer;
```
- float variant (default)
```cpp
MoveBuffer_double myBuffer;
```
- double variant
```cpp
MoveBuffer_long myBuffer;
```
- long variant

##### The following methods are common across all class variants.
Note these definition are examples of the float variant, if you require higher accuracy double long variable types, please define the class 
### Check if buffer empty
```cpp
bool isEmpty()
```
Checks if the buffer is empty.

- **Returns**: `true` if the buffer is empty, `false` otherwise.

### Getting the number of buffer entries
```cpp
int getSize()`
```
Check the number of entries in the buffer.

- **Returns**: `int` value for number of entries

### Queuing up moves (add to end)
```cpp
void enqueueMove(float x, float y, float z) // 3rd coordinate is optional
```
Adds a new move to the end of the buffer.

- **Parameters**:
  - `x`: X coordinate of the move.
  - `y`: Y coordinate of the move.
  - `z`: Z coordinate of the move. [OPTIONAL]

### Adding a move to the top of the buffer
```cpp
void insertMoveBeforeCurrent(float x, float y, float z) // 3rd coordinate is optional
```
Adds a new move to the top of the buffer, the newly added move will be the next move retrieved.

- **Parameters**:
  - `x`: X coordinate of the move.
  - `y`: Y coordinate of the move.
  - `z`: Z coordinate of the move. [OPTIONAL]

### Adding a move anywhere in the buffer
```cpp
void insertMoveBeforeIndex(int index, float x, float y, float z) // 3rd coordinate is optional
```
Adds a move at chosen index position and shuffles moves already in the buffer down.
If an invalid index (out of range) is entered the function returns without adding the move.
*PLEASE NOTE: This buffer starts its index at 1 unlike an array which would start at 0.*

- **Parameters**:
  - `index`: Index number for buffer position (1 is the top of queue).
  - `x`: X coordinate of the move.
  - `y`: Y coordinate of the move.
  - `z`: Z coordinate of the move. [OPTIONAL]

### Previewing the next move
```cpp
bool peekNextMove(float &x, float &y, float &z) // 3rd coordinate is optional
```
Peeks at the next move without removing it from the buffer.
Temporary variables for coordinates must be created before calling this function
***Example***
```cpp
float temp_x, temp_y, temp_z;
peekNextMove(temp_x, temp_y, temp_z);
```
The coordinates will be stored in the variables you create as a function can normally only return one variable at a time.

- **Parameters**:
  - `x`: X coordinate of the move.
  - `y`: Y coordinate of the move.
  - `z`: Z coordinate of the move. [OPTIONAL]

### Retrieving the next move
```cpp
bool getNextMove(float &x, float &y, float &z) // 3rd coordinate is optional
```
Gets the next move and removes it from the buffer.
Temporary variables for coordinates must be created before calling this function
***Example***
```cpp
float temp_x, temp_y, temp_z;
getNextMove(temp_x, temp_y, temp_z);
```
The coordinates will be stored in the variables you create as a function can normally only return one variable at a time.

- **Parameters**:
  - `x`: X coordinate of the move.
  - `y`: Y coordinate of the move.
  - `z`: Z coordinate of the move. [OPTIONAL]

### Getting Moves By Index
```cpp
peekMoveByIndex(int index, float &x, float &y, float &z)
getNextMoveByIndex(int index, float &x, float &y, float &z)
```
- **Parameters**:
  - `index`: Index for choosing position in buffer ***Index for buffer starts at **1** not **0*****
  - `x`: X coordinate of the move.
  - `y`: Y coordinate of the move.
  - `z`: Z coordinate of the move. [OPTIONAL]
The functionality is the same but instead of taking the move from the top of the buffer you can choose any move in the buffer.

If you wan to get a move from the bottom of the buffer, use:
```cpp
float temp_x, temp_y, temp_z;
getMoveByIndex(getSize(), temp_x, temp_y, temp_z);
```
The size of the buffer will always be the same number as the index of the last move.

### Clear Entries
```cpp
void clearMoves()
```
Deletes all entries in the buffer
### Delete Move By Index
```cpp
deleteMoveByIndex(int index)
```
Deletes a single move, define the move using the index, after deletion the buffer will automatically reassign index values.
E.g. Suppose your buffer had 3 entries, so index 1, 2 and 3. And now you called for the deletion of index 2 move.
The move that was previously at index 3 becomes index 2 immediately after the old move is deleted and if your list was longer,
like 10 moves then all the other entries would also change their index by -1.
#


## Example

Here is an example of how to use the `MoveBuffer_float` class:

```cpp
#include <MoveBuffer.h>

MoveBuffer MoveList;



void setup()
{
    Serial.begin(115200);

    MoveList.clearMoves(); // Clear the whole buffer

    // Add moves to end of list
    MoveList.enqueueMove(100, 200, 300); // Entry 1
    MoveList.enqueueMove(500, 300, 20);  // Entry 2
    MoveList.enqueueMove(0, 20, 50);     // Entry 3

    // Add move at index position
    // e.g. This move was added before entry 2 so it becomes entry 2
    // and the whole buffer after entry 2 gets shifted by 1
    // so the original entry 2 is now entry 3 and so on...
    MoveList.insertMoveBeforeIndex(2, 22, 66, 88);


    // Delete move at index
    // This deletes the move that was just added before and reorganises the index
    // so now the entry at index 3 becomes the new index 2 entry and so on...
    MoveList.deleteMoveByIndex(2);

    // Add move to top of list (index 1)
    MoveList.insertMoveBeforeCurrent(0, 0, 0);

    // Gets next move from the buffer and stores values in temp_x, temp_y, temp_z but does not delete or go to next move in list
    float temp_x, temp_y, temp_z;
    MoveList.peekNextMove(temp_x, temp_y, temp_z);
    Serial.println("Peek next move example");
    Serial.println("X value: " + (String)temp_x);
    Serial.println("Y value: " + (String)temp_y);
    Serial.println("Z value: " + (String)temp_z);

    // The same can also be done by index
    MoveList.peekMoveByIndex(3, temp_x, temp_y, temp_z);
    Serial.println("Peek by Index example for entry 3");
    Serial.println("X value: " + (String)temp_x);
    Serial.println("Y value: " + (String)temp_y);
    Serial.println("Z value: " + (String)temp_z);
    // Remember, teh index numbers will change every time a move is added or deleted
    // The top move will always be index 1 and counting upwards from there
    Serial.println("END OF SETUP");
}

void loop()
{
    if (!MoveList.isEmpty())
    {
        // Gets next move into the temp values and deletes it from the buffer
        float temp_x, temp_y, temp_z;
        MoveList.getNextMove(temp_x, temp_y, temp_z);
        Serial.println("X value: " + (String)temp_x);
        Serial.println("Y value: " + (String)temp_y);
        Serial.println("Z value: " + (String)temp_z);
    }
    else
    {
        Serial.println("Buffer is empty");
        while(1);
    }

    delay(1000);
}
```