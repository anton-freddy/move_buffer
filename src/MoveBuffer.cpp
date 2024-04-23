#include <MoveBuffer.h>

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
  Method: Add moves to buffer
  In: xy coordinates
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
  Method: Add moves to buffer before current move
  In: xy coordinates
  Out: none
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
  Method: Gets next move from queue. DOES NOT DELETE MOVE OR PUTS NEXT MOVE TO TOP OF LIST.
  ONLY USE FOR PREVIEWING WHAT THE NEXT MOVE IS
  In: x y z varibles to store requested move in
  Out: Returns true if buffer/queue is empty
*******************************************************/
bool MoveBuffer::getCurrentMove(float &x, float &y, float &z)
{
  if (head != nullptr)
  {
    move *current = head;

    x = head->x;
    y = head->y;
    z = head->z;

    return false;
  }

  return true;
}

/*******************************************************
  Method: Gets next move from queue. DOES NOT DELETE MOVE OR PUTS NEXT MOVE TO TOP OF LIST.
  ONLY USE FOR PREVIEWING WHAT THE NEXT MOVE IS
  In: x y z varibles to store requested move in
  Out: Returns true if buffer/queue is empty
*******************************************************/
bool MoveBuffer::getCurrentMove(float &x, float &y)
{
  if (head != nullptr)
  {
    move *current = head;

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
  In: x y z varibles to store requested move in
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