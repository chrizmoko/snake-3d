// ViewPoint.hpp
//
// A similar structure to a quarternion, but only accounts for the rotation
// and pitch of the camera. The values of rotation and pitch are measured in
// degrees and does not need to be restricted to the range of 0 to 360 degrees.
// It is expected for functions and methods that use this struct to convert the
// values to the necessary unit and handle them appropriately. The distance of
// the viewpoint should be specified by a non-negative value. Moreover, the
// viewpoint is orientated around the zero origin of the virtual world.

#ifndef VIEWPOINT_HPP
#define VIEWPOINT_HPP



struct ViewPoint
{
	float rotation;
	float pitch;
	float distance;
};



#endif