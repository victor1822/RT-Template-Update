#include "raytracer.h"

RayTracer::RayTracer( Camera &camera,
                      const Scene &scene,
                      const glm::vec3 background_color,
                      Buffer &buffer ) :
        camera_( camera ),
        scene_( scene ),
        background_color_{ background_color },
        buffer_( buffer )
{}

void RayTracer::integrate( void )
{
    IntersectionRecord intersection_record;

    // Image space origin (i.e. x = 0 and y = 0) at the top left corner.

    // Loops over image rows
    for ( std::size_t y = 0; y < buffer_.v_resolution_; y++ )
    {
        std::stringstream progress_stream;
        progress_stream << "\r  progress .........................: "
                        << std::fixed << std::setw( 6 )
                        << std::setprecision( 2 )
                        << 100.0 * y / ( buffer_.v_resolution_ - 1 )
                        << "%";

        std::clog << progress_stream.str();

        // Loops over image columns
        for ( std::size_t x = 0; x < buffer_.h_resolution_; x++ )
        {
           intersection_record.t_ = std::numeric_limits< double >::max(); 

            Ray ray{ camera_.getWorldSpaceRay( glm::vec2{ x + 0.5f, y + 0.5f } ) };

            if ( scene_.intersect( ray, intersection_record ) )
                //buffer_.buffer_data_[x][y] = glm::vec3{ 1.0f, 0.0f, 0.0f };
		//intersection_record.cor = (glm::vec3{intersection_record.t_*0.2f} + intersection_record.cor);
		//intersection_record.cor = intersection_record.cor * 0.5f;
                //buffer_.buffer_data_[x][y] = intersection_record.cor + glm::vec3{intersection_record.t_*0.2f};
		////buffer_.buffer_data_[x][y] = glm::vec3{intersection_record.cor + intersection_record.t_*0.2f};
		////buffer_.buffer_data_[x][y][0] = buffer_.buffer_data_[x][y][0]/2;
		////buffer_.buffer_data_[x][y][1] = buffer_.buffer_data_[x][y][1]/2;
		////buffer_.buffer_data_[x][y][2] = buffer_.buffer_data_[x][y][2]/2;
		buffer_.buffer_data_[x][y] = intersection_record.cor;
        }
    }

    std::clog << std::endl;
}

