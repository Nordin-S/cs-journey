#ifndef IMOVABLE_H
#define IMOVABLE_H
class IMovable
{
public:
    virtual void moveLeft() = 0;
    virtual void moveRight() = 0;
    virtual void stop() = 0;
};
#endif // IMOVABLE_H
