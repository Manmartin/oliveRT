#ifndef SCENE_HPP
# define SCENE_HPP

# include <fstream>
# include <memory>
# include <vector>
# include <algorithm>

# include <Triangle.hpp>
# include <Sphere.hpp>

# define FACING 1

typedef struct s_camera {
    Vec origin;
    Vec dir;
} Camera;

class Scene {
    
    private:
        Camera cam;

    public:
        constexpr static unsigned short height = 1000;
        constexpr static unsigned short width = 1000;
        constexpr static unsigned size = width * height;
        std::vector<std::shared_ptr<Object const>> objs{};
        std::vector<std::shared_ptr<Object const>> lights{};
        void (*toImage) (std::vector<Vec>);
    /* Scene.cpp */
        Scene();
        Scene( Scene const &ref );
        ~Scene();

        Scene &operator=( Scene const &ref );
       
    /* render.cpp */
        void  render(void);
};
#endif
