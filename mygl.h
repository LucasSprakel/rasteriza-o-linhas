#ifndef _MYGL_H_
#define _MYGL_H_

#include "definitions.h"
#include <tuple>


void MyGlDraw(void);
void PutPixel(std::tuple<int, int> point, std::tuple<int, int, int, int> color);
void DrawLine(std::tuple<int, int> start, std::tuple<int, int, int, int> colorStart, std::tuple<int, int> end, std::tuple<int, int, int, int> colorEnd);
void DrawTriangle(std::tuple<int, int> v0, std::tuple<int, int, int, int> color0, std::tuple<int, int> v1, std::tuple<int, int, int, int> color1, std::tuple<int, int> v2, std::tuple<int, int, int, int> color2);

#endif 
