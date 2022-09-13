#include <raytracer.hpp>

using std::vector;

void toppm3(vector<Vec> image_data) {
    std::ofstream image("example.ppm", std::fstream::out | std::fstream::trunc);
    if (!image) {
        std::cerr << "Unable to create image\n";
        return;
    }
    // Image properties: P3 (file format), Width and height, max color value
    image << "P3\n" << Scene::width << " " << Scene::height << "\n255\n";
    for (unsigned int i = 0; i < Scene::size; i++) { 
        image 
        << (int)(255 * std::clamp(image_data[i].x, Num(0), Num(1))) << ' '
        << (int)(255 * std::clamp(image_data[i].y, Num(0), Num(1))) << ' '
        << (int)(255 * std::clamp(image_data[i].z, Num(0), Num(1))) << '\n';
    }
}

void toppm6(vector<Vec> image_data) {
    std::ofstream image("./example.ppm", std::ofstream::out | std::ofstream::trunc | std::ofstream::binary);
    if (!image) {
        std::cerr << "Unable to create image\n";
        return;
    }
    // Image properties: P6 (file format), Width and height, max color value
    image << "P6\n" << Scene::width << " " << Scene::height << "\n255\n";
    for (unsigned i = 0; i < Scene::size; ++i) {
        image 
        << (unsigned char)(255 * std::clamp(image_data[i].x, Num(0), Num(1)))
        << (unsigned char)(255 * std::clamp(image_data[i].y, Num(0), Num(1)))
        << (unsigned char)(255 * std::clamp(image_data[i].z, Num(0), Num(1)));
    }
}
