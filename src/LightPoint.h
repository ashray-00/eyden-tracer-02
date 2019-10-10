#pragma once

#include "ILight.h"

/**
 * @brief Point light source class
 */
class CLightPoint : public ILight
{
public:
	/**
	 * @brief Constructor
	 * @param position The position (origin) of the light source
	 * @param intensity The emission color and strength of the light source
	 */
	CLightPoint(Vec3f intensity, Vec3f position)
		: m_intensity(intensity)
		, m_position(position)
	{} 
	virtual ~CLightPoint(void) = default;

	virtual std::optional<Vec3f> Illuminate(Ray& ray) override
	{
		// --- PUT YOUR CODE HERE ---
		Vec3f intensity; 
		intensity[0]= m_intensity[0]/pow(((ray.org[0] + ray.t * ray.dir[0]) - m_position[0]),2);
		intensity[1]= m_intensity[1]/pow(((ray.org[1] + ray.t * ray.dir[1]) - m_position[1]),2);
		intensity[2]= m_intensity[2]/pow(((ray.org[2] + ray.t * ray.dir[2]) - m_position[2]),2);
		return intensity;
	}


private:
	Vec3f m_intensity; ///< emission (red, green, blue)
	Vec3f m_position;  ///< The light source origin
};
