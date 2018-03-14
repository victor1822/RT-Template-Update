#include "scene.h"

Scene::Scene( void )
{}

Scene::~Scene( void )
{}

bool Scene::intersect( const Ray &ray,
                       IntersectionRecord &intersection_record ) const
{
    bool intersection_result = false;
    IntersectionRecord tmp_intersection_record;
    std::size_t num_primitives = primitives_.size();

    // Loops over the list of primitives, testing the intersection of each primitive against the given ray 
    for ( std::size_t primitive_id = 0; primitive_id < num_primitives; primitive_id++ )
        if ( primitives_[primitive_id]->intersect( ray, tmp_intersection_record ) )
            if ( ( tmp_intersection_record.t_ < intersection_record.t_ ) && ( tmp_intersection_record.t_ > 0.0 ) )
            {
                intersection_record = tmp_intersection_record;
		intersection_record.cor[0] = primitives_[primitive_id]->cor[0];
		intersection_record.cor[1] = primitives_[primitive_id]->cor[1];
		intersection_record.cor[2] = primitives_[primitive_id]->cor[2];
                intersection_result = true; // the ray intersects a primitive!
            }

    return intersection_result;
}

void Scene::load( void ) 
{

 Assimp::Importer importer;

  const aiScene* scene = importer.ReadFile("monkey2.obj", aiProcess_Triangulate );

   if (!scene) {
    std::ostringstream ss;
    ss << "Error loading scene: " << importer.GetErrorString();
  }

  if (scene->HasMeshes()) {
    for (unsigned int mesh_id = 0; mesh_id < scene->mNumMeshes; mesh_id++) {
      const aiMesh* mesh_ptr = scene->mMeshes[mesh_id];

      for (size_t vertex_id = 0; vertex_id < mesh_ptr->mNumVertices;
           vertex_id += 3) {
        const aiVector3D* vertex_ptr = &mesh_ptr->mVertices[vertex_id];

        Triangle triangle(
            glm::vec3(vertex_ptr[0].x, vertex_ptr[0].y, vertex_ptr[0].z),
            glm::vec3(vertex_ptr[1].x, vertex_ptr[1].y, vertex_ptr[1].z),
            glm::vec3(vertex_ptr[2].x, vertex_ptr[2].y, vertex_ptr[2].z));

	primitives_.push_back(Primitive::PrimitiveUniquePtr( new Triangle{triangle.a_,triangle.b_,triangle.c_}));

      }
    }
  }

	//==========================================
    /*primitives_.push_back( Primitive::PrimitiveUniquePtr( new Sphere{ glm::vec3{  0.0f, 0.0f,  0.0f }, 0.2f } ) );
    primitives_.push_back( Primitive::PrimitiveUniquePtr( new Sphere{ glm::vec3{ -0.5f, 0.0f, -1.0f }, 0.2f } ) );
    primitives_.push_back( Primitive::PrimitiveUniquePtr( new Sphere{ glm::vec3{  0.0f,-0.5f, -2.0f }, 0.2f } ) );
    primitives_.push_back( Primitive::PrimitiveUniquePtr( new Sphere{ glm::vec3{  0.0f, 0.5f, -3.0f }, 0.2f } ) );
	
    int value = 0;

    glm::vec3 a = { -0.5f , 0.0f , value}, 
              c = { 0.0f , -0.5f , value}, 
              b = { 0.0f , 0.5f , value}; 
	
    primitives_.push_back( Primitive::PrimitiveUniquePtr( new Triangle{a,b,c} ) );*/

	//value_front = -1.0f;
	//value_back = -2.0f;

		///*****************DESCOMENTA AQUI

    /*primitives_.push_back( Primitive::PrimitiveUniquePtr( new Sphere{ glm::vec3{ -0.5f, 0.5f, -1.0f }, 0.2f } ) );
    primitives_.push_back( Primitive::PrimitiveUniquePtr( new Sphere{ glm::vec3{ -0.5f, -0.5f, -1.0f }, 0.2f } ) );
    primitives_.push_back( Primitive::PrimitiveUniquePtr( new Sphere{ glm::vec3{  0.5f,-0.5f, -1.0f }, 0.2f } ) );
    primitives_.push_back( Primitive::PrimitiveUniquePtr( new Sphere{ glm::vec3{  0.5f, 0.5f, -1.0f }, 0.2f } ) );

    primitives_.push_back( Primitive::PrimitiveUniquePtr( new Sphere{ glm::vec3{ -0.5f, -0.5f, -2.0f }, 0.2f } ) );
    primitives_.push_back( Primitive::PrimitiveUniquePtr( new Sphere{ glm::vec3{ -0.5f, 0.5f, -2.0f }, 0.2f } ) );
    primitives_.push_back( Primitive::PrimitiveUniquePtr( new Sphere{ glm::vec3{  0.5f,-0.5f, -2.0f }, 0.2f } ) );
    primitives_.push_back( Primitive::PrimitiveUniquePtr( new Sphere{ glm::vec3{  0.5f, 0.5f, -2.0f }, 0.2f } ) );*/	

		///****************ATE AQUI

    ///setar cores randômicas
   if(!primitives_.empty()){ for(int i=0;i<primitives_.size();i++){
    primitives_[i]->cor[0] = ((float)(rand())/RAND_MAX);
    primitives_[i]->cor[1] = ((float)(rand())/RAND_MAX);
    primitives_[i]->cor[2] = ((float)(rand())/RAND_MAX);}

}

  /*  for(int i=0;i<primitives_.size();i++){
    primitives_[i]->cor[0] = 255;
    primitives_[i]->cor[1] = 0;
    primitives_[i]->cor[2] = 0;

}*/

}

