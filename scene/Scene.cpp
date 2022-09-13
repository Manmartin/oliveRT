#include <Scene.hpp>

Scene::Scene() {
    this->cam.origin = 0;
    this->cam.dir = Vec(0, 0, -1); 
}
Scene::Scene( Scene const &ref ): objs(ref.objs), lights(ref.lights) { *this = ref; }
Scene::~Scene() {}
Scene   &Scene::operator=( Scene const &ref ) {
    this->cam.origin = ref.cam.origin;
    this->cam.dir = ref.cam.dir;
    this->objs = ref.objs;
    this->lights = ref.lights;
    return *this;
}
