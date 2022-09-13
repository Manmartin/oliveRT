#include <raytracer.hpp>

using std::make_shared;

int main(void) {
    Scene scene;
    scene.toImage = toppm6;

    scene.objs.push_back(make_shared<Sphere const>(Vec(0, 0, -20), 14, Vec(50/255.0, 94/255.0, 168/255.0)));
    scene.objs.push_back(make_shared<Sphere const>(Vec(2, 2, -5), 1, Vec(50/255.0, 155/255.0, 100/255.0)));
    scene.objs.push_back(make_shared<Sphere const>(Vec(-2, 2, -5), 1, Vec(50/255.0, 155/255.0, 100/255.0)));
    scene.objs.push_back(make_shared<Sphere const>(Vec(0, 0, -2), 1, Vec(129/255.0, 245/255.0, 66/255.0)));
//    scene.objects.push_back(make_shared<Plane const>(Vec(0, 0, -7), Vec(0, 0, 1), Vec(255/255.0, 255/255.0, 255/255.0)));
//    objects.push_back(make_shared<Triangle const>(Vec(1, 1, -1), Vec(0, 0, -1), Vec(-1, 1, -1), Vec(255/255.0, 255/255.0, 255/255.0)));
//    scene.objects.push_back(make_shared<Plane const>(Vec(0, 0, -7), Vec(0, 1, 1).normalice(), Vec(255/255.0, 100/255.0, 100/255.0)));
    scene.render();
    return 0;
}
