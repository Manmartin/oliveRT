#include <raytracer.hpp>
using std::vector;
using std::shared_ptr;
using std::make_shared;

void to_ppm3(vector<Vec> image_data) {
    std::ofstream image("example.ppm", std::fstream::out | std::fstream::trunc);
    if (!image) {
        std::cerr << "Unable to create image\n";
        return;
    }
    // Image properties: P3 (file format), Width and height, max color value
    image << "P3\n" << WIDTH << " " << HEIGHT << "\n255\n";
    for (unsigned int i = 0; i < SIZE; i++) { 
        image 
        << (int)(255 * std::clamp(image_data[i].x, Num(0), Num(1))) << ' '
        << (int)(255 * std::clamp(image_data[i].y, Num(0), Num(1))) << ' '
        << (int)(255 * std::clamp(image_data[i].z, Num(0), Num(1))) << '\n';
    }
}

void to_ppm6(vector<Vec> image_data) {
    std::ofstream image("./example.ppm", std::ofstream::out | std::ofstream::trunc | std::ofstream::binary);
    if (!image) {
        std::cerr << "Unable to create image\n";
        return;
    }
    // Image properties: P6 (file format), Width and height, max color value
    image << "P6\n" << WIDTH << " " << HEIGHT << "\n255\n";
    for (unsigned i = 0; i < SIZE; ++i) {
        image 
        << (unsigned char)(255 * std::clamp(image_data[i].x, Num(0), Num(1)))
        << (unsigned char)(255 * std::clamp(image_data[i].y, Num(0), Num(1)))
        << (unsigned char)(255 * std::clamp(image_data[i].z, Num(0), Num(1)));
    }
}

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

Vec castRay(Vec const &origin, Vec const &dir, vector<shared_ptr<Object const>> const &objects) {
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

void render(std::vector<std::shared_ptr<Object const>> &objects) {
    vector<Vec>     image(SIZE); 
    Vec             origin = 0;
    int             pixel = 0;
    Num invWidth = 1 / Num(WIDTH), invHeight = 1 / Num(HEIGHT);
    Num aspectRatio = WIDTH / Num(HEIGHT);
    Num fov = 90;
    Num zoom = std::tan(M_PI * 0.5 * fov / 180);
    for (unsigned int y = 0; y < HEIGHT; ++y) {
        for (unsigned int x = 0; x < WIDTH; ++x, ++pixel) {
            Num pixelX = (2 * ((x + 0.5) * invWidth) - 1) * zoom * aspectRatio;
            Num pixelY = (1 - 2 * ((y + 0.5) * invHeight)) * zoom;
            Vec dir(pixelX, pixelY, -1);
            dir.normalice();
           image[pixel] = castRay(origin, dir, objects);
        }
    }
    to_ppm6(image);
}

int main(void) {
    std::vector<std::shared_ptr<Object const>> objects;
    std::vector<std::shared_ptr<Object const>> lights;
    objects.push_back(make_shared<Sphere const>(Vec(0, 0, -20), 14, Vec(50/255.0, 94/255.0, 168/255.0)));
    objects.push_back(make_shared<Sphere const>(Vec(2, 2, -5), 1, Vec(50/255.0, 155/255.0, 100/255.0)));
    objects.push_back(make_shared<Sphere const>(Vec(-2, 2, -5), 1, Vec(50/255.0, 155/255.0, 100/255.0)));
    objects.push_back(make_shared<Sphere const>(Vec(0, 0, -2), 1, Vec(129/255.0, 245/255.0, 66/255.0)));
//    objects.push_back(make_shared<Plane const>(Vec(0, 0, -7), Vec(0, 0, -1), Vec(255/255.0, 255/255.0, 255/255.0)));
//    objects.push_back(make_shared<Triangle const>(Vec(1, 1, -1), Vec(0, 0, -1), Vec(-1, 1, -1), Vec(255/255.0, 255/255.0, 255/255.0)));
//    objects.push_back(make_shared<Plane const>(Vec(0, 0, -7), Vec(0, 1, 1).normalice(), Vec(255/255.0, 100/255.0, 100/255.0)));
    render(objects);
    return 0;
}
