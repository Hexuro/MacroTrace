#include "MacroTrace.h"
#include "Hittable.h"
#include "HittableList.h"
#include "Sphere.h"
#include "Material.h"
#include "Camera.h"

int main() {
    hittable_list world;

    auto R = std::cos(pi / 4);

    auto material_left = make_shared<lambertian>(color(0, 0, 1));
    auto material_right = make_shared<lambertian>(color(1, 0, 0));

    world.add(make_shared<sphere>(point3(-R, 0, -1), R, material_left));
    world.add(make_shared<sphere>(point3(R, 0, -1), R, material_right));

    camera cam;

    cam.aspect_ratio = 16.0 / 9.0;
    cam.image_width = 256;
    cam.samples_per_pixel = cam.image_width/4;
    cam.max_depth = 50;

    cam.render(world);
}