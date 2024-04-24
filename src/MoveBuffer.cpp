#include <MoveBuffer.h>

// ------------------------------------ FLOAT(DEFAULT) DATA TYPE MOVE BUFFER ---------------------------------
MoveBuffer::MoveBuffer(){};

/*******************************************************
  Method: Checks if Buffer is empty
  In: none
  Out: Returns True if Empty
*******************************************************/
bool MoveBuffer::isEmpty()
{
  if (head != nullptr)
  {
    return false;
  }

  return true;
}

/*******************************************************
  Method: Checks Buffer Size
  In: none
  Out: Returns number of entries
*******************************************************/
int MoveBuffer::getSize()
{
  int count = 0;
  move *current = head;
  while (current != nullptr)
  {
    count++;
    current = current->next;
  }
  return count;
}

/*******************************************************
  Method: Delete buffer entry by index
  In: index
  Out: returns false if index is invalid
*******************************************************/
bool MoveBuffer::deleteMoveByIndex(int index)
{
  if (index < 1 || index >= getSize())
  {
    // Index out of range
    return false;
  }

  move *current = head;
  move *previous = nullptr;

  // Traverse to the node to be deleted
  for (int i = 1; i < index; i++)
  {
    previous = current;
    current = current->next;
  }

  if (previous == nullptr)
  {
    // If deleting the head node
    head = current->next;
  }
  else
  {
    previous->next = current->next;
  }

  if (current == tail)
  {
    // If deleting the tail node
    tail = previous;
  }

  delete current;
  return true;
}

/*******************************************************
  Method: Add moves to buffer
  In: xyz coordinates
  Out: none
*******************************************************/
void MoveBuffer::enqueueMove(float x, float y, float z)
{
  move *newmove = new move;
  newmove->x = x;
  newmove->y = y;
  newmove->z = z;
  newmove->next = nullptr;

  if (tail == nullptr)
  {
    head = newmove;
    tail = newmove;
  }
  else
  {
    tail->next = newmove;
    tail = newmove;
  }
}

/*******************************************************
  Method: Add moves to buffer
  In: xy coordinates
  Out: none
*******************************************************/
void MoveBuffer::enqueueMove(float x, float y)
{
  move *newmove = new move;
  newmove->x = x;
  newmove->y = y;
  newmove->next = nullptr;

  if (tail == nullptr)
  {
    head = newmove;
    tail = newmove;
  }
  else
  {
    tail->next = newmove;
    tail = newmove;
  }
}

/*******************************************************
  Method: Add data entry to top of buffer
  In: x y z variables
  Out:
*******************************************************/
void MoveBuffer::insertMoveBeforeCurrent(float x, float y, float z)
{
  move *newmove = new move;
  newmove->x = x;
  newmove->y = y;
  newmove->z = z;

  if (head == nullptr)
  {
    head = newmove;
    tail = newmove;
    newmove->next = nullptr;
  }
  else
  {
    newmove->next = head;
    head = newmove;
  }
}

/*******************************************************
  Method: Add data entry to top of buffer
  In: x y variables
  Out:
*******************************************************/
void MoveBuffer::insertMoveBeforeCurrent(float x, float y)
{
  move *newmove = new move;
  newmove->x = x;
  newmove->y = y;

  if (head == nullptr)
  {
    head = newmove;
    tail = newmove;
    newmove->next = nullptr;
  }
  else
  {
    newmove->next = head;
    head = newmove;
  }
}

/*******************************************************
  Method: Add data entry before selected index
  In: index and x y z variables
  Out:
*******************************************************/
void MoveBuffer::insertMoveBeforeIndex(int index, float x, float y, float z)
{
  if (index < 1 || index > getSize())
  {
    // Invalid index
    return;
  } else if (index == (getSize() + 1)){
    enqueueMove(x, y, z);
    return;
  } else if (index == 0){
    insertMoveBeforeCurrent(x, y, z);
    return;
  }

  move *newMove = new move;
  newMove->x = x;
  newMove->y = y;
  newMove->z = z;


    // Find the node before the index to insert
    move *current = head;
    for (int i = 1; i < index - 1; i++)
    {
      current = current->next;
    }
    newMove->next = current->next;
    current->next = newMove;
    if (current == tail)
    {
      tail = newMove;
    }
  }

/*******************************************************
  Method: Add data entry before selected index
  In: index and x y variables to store extarcted data
  Out:
*******************************************************/
void MoveBuffer::insertMoveBeforeIndex(int index, float x, float y)
{
    if (index < 1 || index > getSize())
  {
    // Invalid index
    return;
  } else if (index == (getSize() + 1)){
    enqueueMove(x, y);
    return;
  } else if (index == 0){
    insertMoveBeforeCurrent(x, y);
    return;
  }

  move *newMove = new move;
  newMove->x = x;
  newMove->y = y;


    // Find the node before the index to insert
    move *current = head;
    for (int i = 1; i < index - 1; i++)
    {
      current = current->next;
    }
    newMove->next = current->next;
    current->next = newMove;
    if (current == tail)
    {
      tail = newMove;
    }
}

/*******************************************************
  Method: Extract move data for next move but DOES NOT DELETE ENTRY
  In: index and x y z variables to store extarcted data
  Out: returns false if buffer is empty
*******************************************************/
bool MoveBuffer::peekNextMove(float &x, float &y, float &z)
{
  if (head != nullptr)
  {

    x = head->x;
    y = head->y;
    z = head->z;

    return false;
  }

  return true;
}

/*******************************************************
  Method: Extract move data for next move but DOES NOT DELETE ENTRY
  In: index and x y variables to store extarcted data
  Out: returns false if buffer is empty
*******************************************************/
bool MoveBuffer::peekNextMove(float &x, float &y)
{
  if (head != nullptr)
  {
    x = head->x;
    y = head->y;

    return false;
  }

  return true;
}

/*******************************************************
  Method: Gets next move from queue and deletes move from queue afterwards
  In: x y z varibles to store requested move in
  Out: Returns true if buffer/queue is empty
*******************************************************/
bool MoveBuffer::getNextMove(float &x, float &y, float &z)
{
  if (head != nullptr)
  {
    move *current = head;

    x = head->x;
    y = head->y;
    z = head->z;

    head = current->next;
    delete current; // Free memory for the completed move
    return false;
  }

  return true;
}

/*******************************************************
  Method: Gets next move from queue and deletes move from queue afterwards
  In: x y varibles to store requested move in
  Out: Returns true if buffer/queue is empty
*******************************************************/
bool MoveBuffer::getNextMove(float &x, float &y)
{
  if (head != nullptr)
  {
    move *current = head;

    x = head->x;
    y = head->y;

    head = current->next;
    delete current; // Free memory for the completed move
    return false;
  }

  return true;
}

/*******************************************************
  Method: Extract move data by index but DOES NOT DELETE ENTRY
  In: index and x y z variables to store extarcted data
  Out: returns false if buffer is empty or index is out of range
*******************************************************/
bool MoveBuffer::peekMoveByIndex(int index, float &x, float &y, float &z)
{
  if (index < 1 || index > getSize())
  {
    // Index out of range
    return false;
  }

  move *current = head;
  for (int i = 1; i < index; i++)
  {
    current = current->next;
  }

  // Assign values
  x = current->x;
  y = current->y;
  z = current->z;

  return true;
}

/*******************************************************
  Method: Extract move data by index but DOES NOT DELETE ENTRY
  In: index and x y variables to store extarcted data
  Out: returns false if buffer is empty or index is out of range
*******************************************************/
bool MoveBuffer::peekMoveByIndex(int index, float &x, float &y)
{
  if (index < 1 || index > getSize())
  {
    // Index out of range
    return false;
  }

  move *current = head;
  for (int i = 1; i < index; i++)
  {
    current = current->next;
  }

  // Assign values
  x = current->x;
  y = current->y;

  return true;
}

/*******************************************************
  Method: Extract move data by index and delete move at index
  In: index and x y z variables to store extarcted data
  Out: returns false if buffer is empty or index is out of range
*******************************************************/
bool MoveBuffer::getNextMoveByIndex(int index, float &x, float &y, float &z)
{
  if (index < 1 || index >= getSize())
  {
    // Index out of range
    return false;
  }

  move *current = head;
  move *previous = nullptr;

  // Traverse to the node to be deleted
  for (int i = 1; i < index; i++)
  {
    previous = current;
    current = current->next;
  }

  x = current->x;
  y = current->y;
  z = current->z;

  if (previous == nullptr)
  {
    // If deleting the head node
    head = current->next;
  }
  else
  {
    previous->next = current->next;
  }

  if (current == tail)
  {
    // If deleting the tail node
    tail = previous;
  }

  delete current;
  return true;
}

/*******************************************************
  Method: Extract move data by index and delete move at index
  In: index and x y variables to store extarcted data
  Out: returns false if buffer is empty or index is out of range
*******************************************************/
bool MoveBuffer::getNextMoveByIndex(int index, float &x, float &y)
{
  if (index < 1 || index >= getSize())
  {
    // Index out of range
    return false;
  }

  move *current = head;
  move *previous = nullptr;

  // Traverse to the node to be deleted
  for (int i = 1; i < index; i++)
  {
    previous = current;
    current = current->next;
  }

  x = current->x;
  y = current->y;

  if (previous == nullptr)
  {
    // If deleting the head node
    head = current->next;
  }
  else
  {
    previous->next = current->next;
  }

  if (current == tail)
  {
    // If deleting the tail node
    tail = previous;
  }

  delete current;
  return true;
}

/*******************************************************
  Method: Clears the move buffer
  In: none
  Out: none
*******************************************************/
void MoveBuffer::clearMoves()
{
  while (head != nullptr)
  {
    move *current = head;
    head = current->next;
    delete current; // Free memory for the removed move
  }
  head = nullptr; // Reset the head pointer to nullptr since the list is empty
  tail = nullptr; // Reset the tail pointer to nullptr since the list is empty
}
// ------------------------------------ End of Section---------------------------------

// ------------------------------------ DOUBLE DATA TYPE MOVE BUFFER ---------------------------------
MoveBuffer_double::MoveBuffer_double(){};

/*******************************************************
  Method: Checks if Buffer is empty
  In: none
  Out: Returns True if Empty
*******************************************************/
bool MoveBuffer_double::isEmpty()
{
  if (head != nullptr)
  {
    return false;
  }

  return true;
}

/*******************************************************
  Method: Checks Buffer Size
  In: none
  Out: Returns number of entries
*******************************************************/
int MoveBuffer_double::getSize()
{
  int count = 0;
  move_double *current = head;
  while (current != nullptr)
  {
    count++;
    current = current->next;
  }
  return count;
}

/*******************************************************
  Method: Delete buffer entry by index
  In: index
  Out: returns false if index is invalid
*******************************************************/
bool MoveBuffer_double::deleteMoveByIndex(int index)
{
  if (index < 1 || index >= getSize())
  {
    // Index out of range
    return false;
  }

  move_double *current = head;
  move_double *previous = nullptr;

  // Traverse to the node to be deleted
  for (int i = 1; i < index; i++)
  {
    previous = current;
    current = current->next;
  }

  if (previous == nullptr)
  {
    // If deleting the head node
    head = current->next;
  }
  else
  {
    previous->next = current->next;
  }

  if (current == tail)
  {
    // If deleting the tail node
    tail = previous;
  }

  delete current;
  return true;
}

/*******************************************************
  Method: Add moves to buffer
  In: xyz coordinates
  Out: none
*******************************************************/
void MoveBuffer_double::enqueueMove(double x, double y, double z)
{
  move_double *newmove = new move_double;
  newmove->x = x;
  newmove->y = y;
  newmove->z = z;
  newmove->next = nullptr;

  if (tail == nullptr)
  {
    head = newmove;
    tail = newmove;
  }
  else
  {
    tail->next = newmove;
    tail = newmove;
  }
}

/*******************************************************
  Method: Add moves to buffer
  In: xy coordinates
  Out: none
*******************************************************/
void MoveBuffer_double::enqueueMove(double x, double y)
{
  move_double *newmove = new move_double;
  newmove->x = x;
  newmove->y = y;
  newmove->next = nullptr;

  if (tail == nullptr)
  {
    head = newmove;
    tail = newmove;
  }
  else
  {
    tail->next = newmove;
    tail = newmove;
  }
}

/*******************************************************
  Method: Add data entry to top of buffer
  In: x y z variables
  Out:
*******************************************************/
void MoveBuffer_double::insertMoveBeforeCurrent(double x, double y, double z)
{
  move_double *newmove = new move_double;
  newmove->x = x;
  newmove->y = y;
  newmove->z = z;

  if (head == nullptr)
  {
    head = newmove;
    tail = newmove;
    newmove->next = nullptr;
  }
  else
  {
    newmove->next = head;
    head = newmove;
  }
}

/*******************************************************
  Method: Add data entry to top of buffer
  In: x y variables
  Out:
*******************************************************/
void MoveBuffer_double::insertMoveBeforeCurrent(double x, double y)
{
  move_double *newmove = new move_double;
  newmove->x = x;
  newmove->y = y;

  if (head == nullptr)
  {
    head = newmove;
    tail = newmove;
    newmove->next = nullptr;
  }
  else
  {
    newmove->next = head;
    head = newmove;
  }
}

/*******************************************************
  Method: Add data entry before selected index
  In: index and x y z variables
  Out:
*******************************************************/
void MoveBuffer_double::insertMoveBeforeIndex(int index, double x, double y, double z)
{
  if (index < 1 || index > getSize())
  {
    // Invalid index
    return;
  } else if (index == (getSize() + 1)){
    enqueueMove(x, y, z);
    return;
  } else if (index == 0){
    insertMoveBeforeCurrent(x, y, z);
    return;
  }

  move_double *newMove = new move_double;
  newMove->x = x;
  newMove->y = y;
  newMove->z = z;


    // Find the node before the index to insert
    move_double *current = head;
    for (int i = 1; i < index - 1; i++)
    {
      current = current->next;
    }
    newMove->next = current->next;
    current->next = newMove;
    if (current == tail)
    {
      tail = newMove;
    }
  }

/*******************************************************
  Method: Add data entry before selected index
  In: index and x y variables to store extarcted data
  Out:
*******************************************************/
void MoveBuffer_double::insertMoveBeforeIndex(int index, double x, double y)
{
    if (index < 1 || index > getSize())
  {
    // Invalid index
    return;
  } else if (index == (getSize() + 1)){
    enqueueMove(x, y);
    return;
  } else if (index == 0){
    insertMoveBeforeCurrent(x, y);
    return;
  }

  move_double *newMove = new move_double;
  newMove->x = x;
  newMove->y = y;


    // Find the node before the index to insert
    move_double *current = head;
    for (int i = 1; i < index - 1; i++)
    {
      current = current->next;
    }
    newMove->next = current->next;
    current->next = newMove;
    if (current == tail)
    {
      tail = newMove;
    }
}

/*******************************************************
  Method: Extract move data for next move but DOES NOT DELETE ENTRY
  In: index and x y z variables to store extarcted data
  Out: returns false if buffer is empty
*******************************************************/
bool MoveBuffer_double::peekNextMove(double &x, double &y, double &z)
{
  if (head != nullptr)
  {

    x = head->x;
    y = head->y;
    z = head->z;

    return false;
  }

  return true;
}

/*******************************************************
  Method: Extract move data for next move but DOES NOT DELETE ENTRY
  In: index and x y variables to store extarcted data
  Out: returns false if buffer is empty
*******************************************************/
bool MoveBuffer_double::peekNextMove(double &x, double &y)
{
  if (head != nullptr)
  {
    x = head->x;
    y = head->y;

    return false;
  }

  return true;
}

/*******************************************************
  Method: Gets next move from queue and deletes move from queue afterwards
  In: x y z varibles to store requested move in
  Out: Returns true if buffer/queue is empty
*******************************************************/
bool MoveBuffer_double::getNextMove(double &x, double &y, double &z)
{
  if (head != nullptr)
  {
    move_double *current = head;

    x = head->x;
    y = head->y;
    z = head->z;

    head = current->next;
    delete current; // Free memory for the completed move
    return false;
  }

  return true;
}

/*******************************************************
  Method: Gets next move from queue and deletes move from queue afterwards
  In: x y varibles to store requested move in
  Out: Returns true if buffer/queue is empty
*******************************************************/
bool MoveBuffer_double::getNextMove(double &x, double &y)
{
  if (head != nullptr)
  {
    move_double *current = head;

    x = head->x;
    y = head->y;

    head = current->next;
    delete current; // Free memory for the completed move
    return false;
  }

  return true;
}

/*******************************************************
  Method: Extract move data by index but DOES NOT DELETE ENTRY
  In: index and x y z variables to store extarcted data
  Out: returns false if buffer is empty or index is out of range
*******************************************************/
bool MoveBuffer_double::peekMoveByIndex(int index, double &x, double &y, double &z)
{
  if (index < 1 || index > getSize())
  {
    // Index out of range
    return false;
  }

  move_double *current = head;
  for (int i = 1; i < index; i++)
  {
    current = current->next;
  }

  // Assign values
  x = current->x;
  y = current->y;
  z = current->z;

  return true;
}

/*******************************************************
  Method: Extract move data by index but DOES NOT DELETE ENTRY
  In: index and x y variables to store extarcted data
  Out: returns false if buffer is empty or index is out of range
*******************************************************/
bool MoveBuffer_double::peekMoveByIndex(int index, double &x, double &y)
{
  if (index < 1 || index > getSize())
  {
    // Index out of range
    return false;
  }

  move_double *current = head;
  for (int i = 1; i < index; i++)
  {
    current = current->next;
  }

  // Assign values
  x = current->x;
  y = current->y;

  return true;
}

/*******************************************************
  Method: Extract move data by index and delete move at index
  In: index and x y z variables to store extarcted data
  Out: returns false if buffer is empty or index is out of range
*******************************************************/
bool MoveBuffer_double::getNextMoveByIndex(int index, double &x, double &y, double &z)
{
  if (index < 1 || index >= getSize())
  {
    // Index out of range
    return false;
  }

  move_double *current = head;
  move_double *previous = nullptr;

  // Traverse to the node to be deleted
  for (int i = 1; i < index; i++)
  {
    previous = current;
    current = current->next;
  }

  x = current->x;
  y = current->y;
  z = current->z;

  if (previous == nullptr)
  {
    // If deleting the head node
    head = current->next;
  }
  else
  {
    previous->next = current->next;
  }

  if (current == tail)
  {
    // If deleting the tail node
    tail = previous;
  }

  delete current;
  return true;
}

/*******************************************************
  Method: Extract move data by index and delete move at index
  In: index and x y variables to store extarcted data
  Out: returns false if buffer is empty or index is out of range
*******************************************************/
bool MoveBuffer_double::getNextMoveByIndex(int index, double &x, double &y)
{
  if (index < 1 || index >= getSize())
  {
    // Index out of range
    return false;
  }

  move_double *current = head;
  move_double *previous = nullptr;

  // Traverse to the node to be deleted
  for (int i = 1; i < index; i++)
  {
    previous = current;
    current = current->next;
  }

  x = current->x;
  y = current->y;

  if (previous == nullptr)
  {
    // If deleting the head node
    head = current->next;
  }
  else
  {
    previous->next = current->next;
  }

  if (current == tail)
  {
    // If deleting the tail node
    tail = previous;
  }

  delete current;
  return true;
}

/*******************************************************
  Method: Clears the move buffer
  In: none
  Out: none
*******************************************************/
void MoveBuffer_double::clearMoves()
{
  while (head != nullptr)
  {
    move_double *current = head;
    head = current->next;
    delete current; // Free memory for the removed move
  }
  head = nullptr; // Reset the head pointer to nullptr since the list is empty
  tail = nullptr; // Reset the tail pointer to nullptr since the list is empty
}
// ------------------------------------ End of Section---------------------------------

// ------------------------------------ LONG DATA TYPE MOVE BUFFER ---------------------------------
MoveBuffer_long::MoveBuffer_long(){};

/*******************************************************
  Method: Checks if Buffer is empty
  In: none
  Out: Returns True if Empty
*******************************************************/
bool MoveBuffer_long::isEmpty()
{
  if (head != nullptr)
  {
    return false;
  }

  return true;
}

/*******************************************************
  Method: Checks Buffer Size
  In: none
  Out: Returns number of entries
*******************************************************/
int MoveBuffer_long::getSize()
{
  int count = 0;
  move_long *current = head;
  while (current != nullptr)
  {
    count++;
    current = current->next;
  }
  return count;
}

/*******************************************************
  Method: Delete buffer entry by index
  In: index
  Out: returns false if index is invalid
*******************************************************/
bool MoveBuffer_long::deleteMoveByIndex(int index)
{
  if (index < 1 || index >= getSize())
  {
    // Index out of range
    return false;
  }

  move_long *current = head;
  move_long *previous = nullptr;

  // Traverse to the node to be deleted
  for (int i = 1; i < index; i++)
  {
    previous = current;
    current = current->next;
  }

  if (previous == nullptr)
  {
    // If deleting the head node
    head = current->next;
  }
  else
  {
    previous->next = current->next;
  }

  if (current == tail)
  {
    // If deleting the tail node
    tail = previous;
  }

  delete current;
  return true;
}

/*******************************************************
  Method: Add moves to buffer
  In: xyz coordinates
  Out: none
*******************************************************/
void MoveBuffer_long::enqueueMove(long x, long y, long z)
{
  move_long *newmove = new move_long;
  newmove->x = x;
  newmove->y = y;
  newmove->z = z;
  newmove->next = nullptr;

  if (tail == nullptr)
  {
    head = newmove;
    tail = newmove;
  }
  else
  {
    tail->next = newmove;
    tail = newmove;
  }
}

/*******************************************************
  Method: Add moves to buffer
  In: xy coordinates
  Out: none
*******************************************************/
void MoveBuffer_long::enqueueMove(long x, long y)
{
  move_long *newmove = new move_long;
  newmove->x = x;
  newmove->y = y;
  newmove->next = nullptr;

  if (tail == nullptr)
  {
    head = newmove;
    tail = newmove;
  }
  else
  {
    tail->next = newmove;
    tail = newmove;
  }
}

/*******************************************************
  Method: Add data entry to top of buffer
  In: x y z variables
  Out:
*******************************************************/
void MoveBuffer_long::insertMoveBeforeCurrent(long x, long y, long z)
{
  move_long *newmove = new move_long;
  newmove->x = x;
  newmove->y = y;
  newmove->z = z;

  if (head == nullptr)
  {
    head = newmove;
    tail = newmove;
    newmove->next = nullptr;
  }
  else
  {
    newmove->next = head;
    head = newmove;
  }
}

/*******************************************************
  Method: Add data entry to top of buffer
  In: x y variables
  Out:
*******************************************************/
void MoveBuffer_long::insertMoveBeforeCurrent(long x, long y)
{
  move_long *newmove = new move_long;
  newmove->x = x;
  newmove->y = y;

  if (head == nullptr)
  {
    head = newmove;
    tail = newmove;
    newmove->next = nullptr;
  }
  else
  {
    newmove->next = head;
    head = newmove;
  }
}

/*******************************************************
  Method: Add data entry before selected index
  In: index and x y z variables
  Out:
*******************************************************/
void MoveBuffer_long::insertMoveBeforeIndex(int index, long x, long y, long z)
{
  if (index < 1 || index > getSize())
  {
    // Invalid index
    return;
  } else if (index == (getSize() + 1)){
    enqueueMove(x, y, z);
    return;
  } else if (index == 0){
    insertMoveBeforeCurrent(x, y, z);
    return;
  }

  move_long *newMove = new move_long;
  newMove->x = x;
  newMove->y = y;
  newMove->z = z;


    // Find the node before the index to insert
    move_long *current = head;
    for (int i = 1; i < index - 1; i++)
    {
      current = current->next;
    }
    newMove->next = current->next;
    current->next = newMove;
    if (current == tail)
    {
      tail = newMove;
    }
  }

/*******************************************************
  Method: Add data entry before selected index
  In: index and x y variables to store extarcted data
  Out:
*******************************************************/
void MoveBuffer_long::insertMoveBeforeIndex(int index, long x, long y)
{
    if (index < 1 || index > getSize())
  {
    // Invalid index
    return;
  } else if (index == (getSize() + 1)){
    enqueueMove(x, y);
    return;
  } else if (index == 0){
    insertMoveBeforeCurrent(x, y);
    return;
  }

  move_long *newMove = new move_long;
  newMove->x = x;
  newMove->y = y;


    // Find the node before the index to insert
    move_long *current = head;
    for (int i = 1; i < index - 1; i++)
    {
      current = current->next;
    }
    newMove->next = current->next;
    current->next = newMove;
    if (current == tail)
    {
      tail = newMove;
    }
}

/*******************************************************
  Method: Extract move data for next move but DOES NOT DELETE ENTRY
  In: index and x y z variables to store extarcted data
  Out: returns false if buffer is empty
*******************************************************/
bool MoveBuffer_long::peekNextMove(long &x, long &y, long &z)
{
  if (head != nullptr)
  {

    x = head->x;
    y = head->y;
    z = head->z;

    return false;
  }

  return true;
}

/*******************************************************
  Method: Extract move data for next move but DOES NOT DELETE ENTRY
  In: index and x y variables to store extarcted data
  Out: returns false if buffer is empty
*******************************************************/
bool MoveBuffer_long::peekNextMove(long &x, long &y)
{
  if (head != nullptr)
  {
    x = head->x;
    y = head->y;

    return false;
  }

  return true;
}

/*******************************************************
  Method: Gets next move from queue and deletes move from queue afterwards
  In: x y z varibles to store requested move in
  Out: Returns true if buffer/queue is empty
*******************************************************/
bool MoveBuffer_long::getNextMove(long &x, long &y, long &z)
{
  if (head != nullptr)
  {
    move_long *current = head;

    x = head->x;
    y = head->y;
    z = head->z;

    head = current->next;
    delete current; // Free memory for the completed move
    return false;
  }

  return true;
}

/*******************************************************
  Method: Gets next move from queue and deletes move from queue afterwards
  In: x y varibles to store requested move in
  Out: Returns true if buffer/queue is empty
*******************************************************/
bool MoveBuffer_long::getNextMove(long &x, long &y)
{
  if (head != nullptr)
  {
    move_long *current = head;

    x = head->x;
    y = head->y;

    head = current->next;
    delete current; // Free memory for the completed move
    return false;
  }

  return true;
}

/*******************************************************
  Method: Extract move data by index but DOES NOT DELETE ENTRY
  In: index and x y z variables to store extarcted data
  Out: returns false if buffer is empty or index is out of range
*******************************************************/
bool MoveBuffer_long::peekMoveByIndex(int index, long &x, long &y, long &z)
{
  if (index < 1 || index > getSize())
  {
    // Index out of range
    return false;
  }

  move_long *current = head;
  for (int i = 1; i < index; i++)
  {
    current = current->next;
  }

  // Assign values
  x = current->x;
  y = current->y;
  z = current->z;

  return true;
}

/*******************************************************
  Method: Extract move data by index but DOES NOT DELETE ENTRY
  In: index and x y variables to store extarcted data
  Out: returns false if buffer is empty or index is out of range
*******************************************************/
bool MoveBuffer_long::peekMoveByIndex(int index, long &x, long &y)
{
  if (index < 1 || index > getSize())
  {
    // Index out of range
    return false;
  }

  move_long *current = head;
  for (int i = 1; i < index; i++)
  {
    current = current->next;
  }

  // Assign values
  x = current->x;
  y = current->y;

  return true;
}

/*******************************************************
  Method: Extract move data by index and delete move at index
  In: index and x y z variables to store extarcted data
  Out: returns false if buffer is empty or index is out of range
*******************************************************/
bool MoveBuffer_long::getNextMoveByIndex(int index, long &x, long &y, long &z)
{
  if (index < 1 || index >= getSize())
  {
    // Index out of range
    return false;
  }

  move_long *current = head;
  move_long *previous = nullptr;

  // Traverse to the node to be deleted
  for (int i = 1; i < index; i++)
  {
    previous = current;
    current = current->next;
  }

  x = current->x;
  y = current->y;
  z = current->z;

  if (previous == nullptr)
  {
    // If deleting the head node
    head = current->next;
  }
  else
  {
    previous->next = current->next;
  }

  if (current == tail)
  {
    // If deleting the tail node
    tail = previous;
  }

  delete current;
  return true;
}

/*******************************************************
  Method: Extract move data by index and delete move at index
  In: index and x y variables to store extarcted data
  Out: returns false if buffer is empty or index is out of range
*******************************************************/
bool MoveBuffer_long::getNextMoveByIndex(int index, long &x, long &y)
{
  if (index < 1 || index >= getSize())
  {
    // Index out of range
    return false;
  }

  move_long *current = head;
  move_long *previous = nullptr;

  // Traverse to the node to be deleted
  for (int i = 1; i < index; i++)
  {
    previous = current;
    current = current->next;
  }

  x = current->x;
  y = current->y;

  if (previous == nullptr)
  {
    // If deleting the head node
    head = current->next;
  }
  else
  {
    previous->next = current->next;
  }

  if (current == tail)
  {
    // If deleting the tail node
    tail = previous;
  }

  delete current;
  return true;
}

/*******************************************************
  Method: Clears the move buffer
  In: none
  Out: none
*******************************************************/
void MoveBuffer_long::clearMoves()
{
  while (head != nullptr)
  {
    move_long *current = head;
    head = current->next;
    delete current; // Free memory for the removed move
  }
  head = nullptr; // Reset the head pointer to nullptr since the list is empty
  tail = nullptr; // Reset the tail pointer to nullptr since the list is empty
}
// ------------------------------------ End of Section---------------------------------