/*
 * vector.h
 *
 *  Created on: 2014-3-1
 *      Author: Vergil
 */


struct Point
{
	float x;
	float y;
};

struct Vector
{
	float dx;
	float dy;
	Point* start;
};


void move_vector_to(Point* new_starting_pt, Vector* vector);
void print_point_info(const Point* point);
void print_vector_info(const Vector* vector);
float get_length(const Vector* vector);
float get_distance(const Point *point1, const Point *point2);
float get_angle(const Vector* vector1, const Vector* vector2);
bool is_parallel(const Vector* vector1, const Vector* vector2);
