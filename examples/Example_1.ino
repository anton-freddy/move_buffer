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

