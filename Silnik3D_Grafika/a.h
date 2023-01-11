#pragma once
#include "GameObject.h"
#include "Drawer.h"
class a :
    public GameObject
{
    static int index[];
    glm::vec3 points[30];
    glm::mat4 matrix;
public:
    a(int h)
    {
        points[0] = { -1.5f * h,h,h / 4 };
        points[1] = { -1.0f * h,h * 2,h / 4 };
        points[2] = { 1.0f * h,h * 2,h / 4 };
        points[3] = { 1.5f * h,h,h / 4 };

        points[4] = { 1.0f * h,h,h / 4 };
        points[5] = { 1.5f * h,-2 * h,h / 4 };
        points[6] = { 1.0f * h,-2 * h,h / 4 };

        points[7] = { 1.0f * h,-1.5 * h,h / 4 };
        points[8] = { -1.5f * h,-2 * h,h / 4 };
        points[9] = { -1.5f * h,-1.5 * h,h / 4 };

        points[10] = { -1.5f * h,0,h / 4 };
        points[11] = { -1.0f * h,0,h / 4 };
        points[12] = { -1.0f * h,0.5 * h,h / 4 };

        points[13] = { 1.0f * h,0.5f * h,h / 4 };
        points[14] = { 1.0f * h,1.0f * h,h / 4 };
        for (int i = 0; i < 15; i++)
            points[i + 15] = { points[i].x,points[i].y,-h / 4 };
        for (int i = 0; i < 30; i++)
            points[i].x *= -1;
    }
    void update() {}
    void draw() {}
    void draw(glm::mat4 view);
};

