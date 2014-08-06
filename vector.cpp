/*
 * vector.cpp
 *
 *  Created on: 2014¦~4¤ë3¤é
 *      Author: psyeung
 */
#include <iostream>
#include <cmath>
#include "vector.h"

using namespace std;


void move_vector_to(Point* new_starting_pt, Vector* vector)
{
	vector->start->x = new_starting_pt->x ;
	vector->start->y = new_starting_pt->y ;
}

void print_point_info(const Point* point)
{
	cout << "its coordinate are (" << point->x << "," << point->y << ")" << endl;
}

void print_vector_info(const Vector* vector)
{
	cout << "The vector is start with point (" << vector->start->x << "," << vector->start->y
			<< ") and its direction vector is (" << vector->dx << "," << vector->dy << ")" << endl;
}

float get_length(const Vector* vector)
{
	return sqrt((vector->dx)*(vector->dx)+(vector->dy)*(vector->dy));
}

float get_distance(const Point *point1, const Point *point2)
{
	float x_diff = point1->x - point2->x;
	float y_diff = point1->y - point2->y;
	return sqrt(x_diff*x_diff + y_diff*y_diff);
}
float get_angle(const Vector* vector1, const Vector* vector2)
{
	return acos(((vector1->dx*vector2->dx) + (vector1->dy*vector2->dy))/
			(get_length(vector1)*get_length(vector2)))/M_PI*180;
}
bool is_parallel(const Vector* vector1, const Vector* vector2)
{
	if ((vector1->dx)*(vector2->dy)-(vector1->dy)*(vector2->dx) == 0)
		return true;
	return false;
}
