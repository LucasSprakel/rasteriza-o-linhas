#include "mygl.h"
#include <iostream>
#include <cmath>
#include <tuple>

using namespace std;

//-----------------------------------------------------------------------------
void MyGlDraw(void)
{
    //PutPixel({0, 0}, {255, 0, 0, 255});  cria um pixel
    //DrawLine({0, 0}, {255, 0, 0, 255}, {250, 250}, {0, 255, 0, 255}); cria uma linha 
    

    DrawTriangle({100, 100}, {255, 0, 0, 255}, {150, 200}, {0, 255, 0, 255}, {50, 200}, {0, 0, 255, 255});
    DrawTriangle({300, 100}, {255, 255, 0, 255}, {250, 200}, {0, 255, 255, 255}, {350, 200}, {255, 0, 255, 255}); 
    DrawTriangle({100, 300}, {255, 128, 0, 255}, {50, 350}, {128, 255, 0, 255}, {50, 250}, {0, 128, 255, 255}); 
    DrawTriangle({300, 300}, {128, 0, 255, 255}, {350, 350}, {255, 0, 128, 255}, {350, 250}, {0, 255, 128, 255}); 
}


void PutPixel(tuple<int, int> point, tuple<int, int, int, int> color) {
    int x = get<0>(point);
    int y = get<1>(point);
    int r = get<0>(color);
    int g = get<1>(color);
    int b = get<2>(color);
    int a = get<3>(color);

    int index = 4 * (x + y * IMAGE_WIDTH);
    FBptr[index] = r;
    FBptr[index + 1] = g;
    FBptr[index + 2] = b;
    FBptr[index + 3] = a;
}

void DrawLine(tuple<int, int> start, tuple<int, int, int, int> colorStart, tuple<int, int> end, tuple<int, int, int, int> colorEnd)
{
    int x0 = get<0>(start);
    int y0 = get<1>(start);
    int x1 = get<0>(end);
    int y1 = get<1>(end);
    int r0 = get<0>(colorStart);
    int g0 = get<1>(colorStart);
    int b0 = get<2>(colorStart);
    int a0 = get<3>(colorStart);
    int r1 = get<0>(colorEnd);
    int g1 = get<1>(colorEnd);
    int b1 = get<2>(colorEnd);
    int a1 = get<3>(colorEnd);

    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = x0 < x1 ? 1 : -1;
    int sy = y0 < y1 ? 1 : -1; 
    int err = (dx > dy ? dx : -dy) / 2, e2;
    int r = r0, g = g0, b = b0, a = a0;

    while (true) {
        PutPixel({x0, y0}, {r, g, b, a});

        if (x0 == x1 && y0 == y1) break;
        e2 = err;
        if (e2 > -dx) { err -= dy; x0 += sx; }
        if (e2 < dy) { err += dx; y0 += sy; }

        float t = (dx > dy) ? float(abs(x0 - x1)) / dx : float(abs(y0 - y1)) / dy;
        r = r0 + t * (r1 - r0);
        g = g0 + t * (g1 - g0);
        b = b0 + t * (b1 - b0);
        a = a0 + t * (a1 - a0);
    }
}

void DrawTriangle(tuple<int, int> v0, tuple<int, int, int, int> color0, tuple<int, int> v1, tuple<int, int, int, int> color1, tuple<int, int> v2, tuple<int, int, int, int> color2)
{
    DrawLine(v0, color0, v1, color1); 
    DrawLine(v1, color1, v2, color2); 
    DrawLine(v2, color2, v0, color0); 
}
