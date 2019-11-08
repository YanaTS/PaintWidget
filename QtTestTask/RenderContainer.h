#pragma once
#include <vector>
#include <memory> 
#include <QRect>
#include "Figure.h"
#include "Transform.h"

class RenderContainer
{
public:	
	static std::vector <std::shared_ptr<Figure>> objectsOnFrame;
	static std::vector <std::shared_ptr<Figure>> selectedObjects;
	static std::shared_ptr<Transform> frameTransform;
	static QPen pen;

	static const int normalLineWidth = 2;
	static const int selectedLineWidth = 5;
};

