#include <MoveBuffer.h>

MoveBuffer MoveList;

void setup()
{
    Serial.begin(119200);
    MoveList.clearMoves(); // Clear teh whole buffer

    // Add moves to end of list
    MoveList.enqueueMove(100, 200, 300);
    MoveList.enqueueMove(500, 300, 20);
    MoveList.enqueueMove(0, 20, 50);

    // Add move to top of list
    MoveList.insertMoveBeforeCurrent(0, 0, 0);

    // Gets next move from the buffer and stores values in temp_x, temp_y, temp_z but does not delete or go to next move in list
    float temp_x, temp_y, temp_z;
    MoveList.getCurrentMove(temp_x, temp_y, temp_z);
    Serial.println("X value: " + (String)temp_x);
    Serial.println("Y value: " + (String)temp_y);
    Serial.println("Z value: " + (String)temp_z);

    Serial.println("END OF SETUP");
}

void loop()
{
    if (!MoveList.isEmpty())
    {
        // Gets next move into the temp values and deltes it from the buffer
        float temp_x, temp_y, temp_z;
        MoveList.getNextMove(temp_x, temp_y, temp_z);
        Serial.println("X value: " + (String)temp_x);
        Serial.println("Y value: " + (String)temp_y);
        Serial.println("Z value: " + (String)temp_z);
    }
    else
    {
        Serial.println("Buffer is empty");
    }

    delay(1000);
}

//  OUTPUT SHOULD SHOW
//      END OF SETUP
//      X value: 0.00
//      Y value: 0.00
//      Z value: 0.00
//      X value: 100.00
//      Y value: 200.00
//      Z value: 300.00
//      X value: 500.00
//      Y value: 300.00
//      Z value: 20.00
//      X value: 0.00
//      Y value: 20.00
//      Z value: 50.00
//      Buffer is empty