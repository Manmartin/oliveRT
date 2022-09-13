#include <Scene.hpp>

using std::vector;
using std::shared_ptr;
using std::make_shared;

static bool trace(Vec const &origin, Vec const &dir, vector<shared_ptr<Object const>> const &objects, Num &tNear, shared_ptr<Object const> &hitObject) {
    tNear = INFINITY; 
    for (auto &obj: objects) {
        Num t;
        if (obj->intersec(origin, dir, t) && t < tNear) {
            hitObject = obj;
            tNear = t;
        }
    } 
    return  hitObject != nullptr;
}

static Vec castRay(Vec const &origin, Vec const &dir, vector<shared_ptr<Object const>> const &objects) {
    Vec hitColor = 0, hitPoint, hitNormal;
    std::shared_ptr<Object const> hitObject = nullptr;
    Num t;
    if (trace(origin, dir, objects, t, hitObject)) {
        hitColor = hitObject->color; 
        hitPoint = origin + dir * t;
        hitObject->getPointInfo(hitPoint, hitNormal); 
#if FACING
        //Facing ratio
        Num facing = std::max(0.0, (-dir).dot(hitNormal));
        hitColor = hitColor * facing;
#endif
    }
    return hitColor;
}

void Scene::render( void ) {
    std::vector<Vec>     image(size); 
    Vec             origin = 0;
    int             pixel = 0;
    Num invWidth = 1 / Num(this->width), invHeight = 1 / Num(this->height);
    Num aspectRatio = this->width / Num(this->height);
    Num fov = 90;
    Num zoom = std::tan(M_PI * 0.5 * fov / 180);
    for (unsigned int y = 0; y < this->width; ++y) {
        for (unsigned int x = 0; x < this->height; ++x, ++pixel) {
            Num pixelX = (2 * ((x + 0.5) * invWidth) - 1) * zoom * aspectRatio;
            Num pixelY = (1 - 2 * ((y + 0.5) * invHeight)) * zoom;
            Vec dir(pixelX, pixelY, -1);
            dir.normalice();
           image[pixel] = castRay(origin, dir, this->objs);
        }
    }
    toImage(image);
}
