#ifndef DRAWER_H
#define DRAWER_H


class Drawer
{

public:
    static Drawer *getInstance();
    void drawRect();

private:
    Drawer();
    static Drawer *instance;
};

#endif // DRAWER_H
